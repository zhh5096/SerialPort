#include "arithmetic.h"

arithmetic::arithmetic(QObject *parent) : QObject(parent)
{

}

void arithmetic::EOG_Detect()
{
    static QVector<QString> sendText = {"w", "d", "s", "a", " "};
    static QVector<double> part_CH1_Data(0, 500);
    static QVector<double> part_CH2_Data(0, 500);
    static uint8_t Update_Threshold_Count = 0;
    static double Threshold1 = 0.000006;
    static double Threshold2 = 0.000006;
    static bool CH1_Detect_State = false;
    static bool CH2_Detect_State = false;

    // 取前20个元素，在取绝对值后进行排序，取前两个最大的元素
    QVector<double> part_Detect_CH1_Data(CH1_Data.begin(), CH1_Data.begin()+20);
    QVector<double> part_Detect_CH2_Data(CH2_Data.begin(), CH2_Data.begin()+20);
    std::transform(part_Detect_CH1_Data.begin(), part_Detect_CH1_Data.end(), part_Detect_CH1_Data.begin(), [](double value) {return std::abs(value);});
    std::transform(part_Detect_CH2_Data.begin(), part_Detect_CH2_Data.end(), part_Detect_CH2_Data.begin(), [](double value) {return std::abs(value);});
    std::sort(part_Detect_CH1_Data.begin(), part_Detect_CH1_Data.end(), std::greater<double>());
    std::sort(part_Detect_CH2_Data.begin(), part_Detect_CH2_Data.end(), std::greater<double>());

    // 标志位检测
    CH1_Detect_State = false;
    CH2_Detect_State = false;
    if (part_Detect_CH1_Data[0] > 5*Threshold1 && part_Detect_CH1_Data[1] > 5*Threshold1) CH1_Detect_State = true;
    if (part_Detect_CH2_Data[0] > 5*Threshold2 && part_Detect_CH2_Data[1] > 5*Threshold2) CH2_Detect_State = true;
    if (CH1_Detect_State && CH2_Detect_State) {
        static int EOG_Detect_Count = 0;
        EOG_Detect_Count++;
        switch(EOG_Detect_Count) {
            case 0: socket_blue->write(sendText[0].toUtf8()); break;
            case 1: socket_blue->write(sendText[1].toUtf8()); break;
            case 2: socket_blue->write(sendText[2].toUtf8()); break;
            case 3: socket_blue->write(sendText[3].toUtf8()); break;
        }
    }

    Update_Threshold_Count++;
    if (Update_Threshold_Count == 25) {
        Update_Threshold_Count = 0;
        for (uint16_t i = 0; i < 500; i++) {
            part_CH1_Data[i] = qAbs(CH1_Data[i]);
            part_CH2_Data[i] = qAbs(CH2_Data[i]);
        }
        Threshold1 = std::accumulate(part_CH1_Data.begin(), part_CH1_Data.end(), 0.0);
        Threshold1 = Threshold1 / part_CH1_Data.size();
        Threshold2 = std::accumulate(part_CH2_Data.begin(), part_CH2_Data.end(), 0.0);
        Threshold2 = Threshold2 / part_CH2_Data.size();
    }
    if (!CH1_Detect_State && !CH2_Detect_State) {
        socket_blue->write(sendText[4].toUtf8());
    }
}

void arithmetic::IBLS()
{
    static QVector<QString> sendText = {"w", "d", "s", "a", " "};
    static int Sti_FreRange[6] = {14, 16, 18, 20, 22, 24};
    uint16_t Fre_Count = qFloor(CHn_Count/Fs)*HighFre;
    // 求指定通道频域分量的平均值作为检测阈值
    double CH1_FFTAbsData_Avg = 0.0;
    double CH2_FFTAbsData_Avg = 0.0;
    CH1_FFTAbsData_Avg = std::accumulate(CH1_FFTAbsData.begin(), CH1_FFTAbsData.begin() + Fre_Count, 0.0);
    CH1_FFTAbsData_Avg = CH1_FFTAbsData_Avg / (qFloor(CHn_Count/Fs)*HighFre);
    CH2_FFTAbsData_Avg = std::accumulate(CH2_FFTAbsData.begin(), CH2_FFTAbsData.begin() + Fre_Count, 0.0);
    CH2_FFTAbsData_Avg = CH2_FFTAbsData_Avg / (qFloor(CHn_Count/Fs)*HighFre);
    // qDebug() << "CH1_FFTAbsData_Avg" << CH1_FFTAbsData_Avg << "CH2_FFTAbsData_Avg" << CH2_FFTAbsData_Avg<< endl;
    // 求指定通道频域分量最大值所对应的刺激频率
    double CH1_SimulatorFre = 0.0;
    double CH2_SimulatorFre = 0.0;
    auto CH1_max = std::max_element(CH1_FFTAbsData.begin(), CH1_FFTAbsData.end());
    auto CH2_max = std::max_element(CH2_FFTAbsData.begin(), CH2_FFTAbsData.end());
    CH1_SimulatorFre = std::distance(CH1_FFTAbsData.begin(), CH1_max) * HighFre / Fre_Count;
    CH2_SimulatorFre = std::distance(CH2_FFTAbsData.begin(), CH2_max) * HighFre / Fre_Count;
    // qDebug() << "CH1_SimulatorFre" << CH1_SimulatorFre << "CH2_SimulatorFre" << CH2_SimulatorFre<< endl;
    // 识别结果
    if (*CH1_max > 2*CH1_FFTAbsData_Avg || *CH2_max > 2*CH2_FFTAbsData_Avg) {
        if ((CH1_SimulatorFre > Sti_FreRange[0] && CH1_SimulatorFre < Sti_FreRange[1]) || (CH2_SimulatorFre > Sti_FreRange[0] && CH2_SimulatorFre < Sti_FreRange[1]))
        {
            rectColor[0] = Qt::yellow; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
            socket_blue->write(sendText[0].toUtf8());
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[1] && CH1_SimulatorFre < Sti_FreRange[2]) || (CH2_SimulatorFre > Sti_FreRange[1] && CH2_SimulatorFre < Sti_FreRange[2]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::yellow;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
            socket_blue->write(sendText[1].toUtf8());
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[2] && CH1_SimulatorFre < Sti_FreRange[3]) || (CH2_SimulatorFre > Sti_FreRange[2] && CH2_SimulatorFre < Sti_FreRange[3]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::yellow;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
            socket_blue->write(sendText[2].toUtf8());
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[3] && CH1_SimulatorFre < Sti_FreRange[4]) || (CH2_SimulatorFre > Sti_FreRange[3] && CH2_SimulatorFre < Sti_FreRange[4]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::yellow;  rectColor[4] = Qt::white;
            socket_blue->write(sendText[3].toUtf8());
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[4] && CH1_SimulatorFre < Sti_FreRange[5]) || (CH2_SimulatorFre > Sti_FreRange[4] && CH2_SimulatorFre < Sti_FreRange[5]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::yellow;
            socket_blue->write(sendText[4].toUtf8());
        }
    }
    else {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
    }

    IBLS_AccomplishState = true;
}

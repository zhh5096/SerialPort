#include "arithmetic.h"
// #include <QDebug>

arithmetic::arithmetic(QObject *parent) : QObject(parent)
{

}

void arithmetic::IBLS()
{
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
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[1] && CH1_SimulatorFre < Sti_FreRange[2]) || (CH2_SimulatorFre > Sti_FreRange[1] && CH2_SimulatorFre < Sti_FreRange[2]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::yellow;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[2] && CH1_SimulatorFre < Sti_FreRange[3]) || (CH2_SimulatorFre > Sti_FreRange[2] && CH2_SimulatorFre < Sti_FreRange[3]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::yellow;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[3] && CH1_SimulatorFre < Sti_FreRange[4]) || (CH2_SimulatorFre > Sti_FreRange[3] && CH2_SimulatorFre < Sti_FreRange[4]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::yellow;  rectColor[4] = Qt::white;
        }
        else if ((CH1_SimulatorFre > Sti_FreRange[4] && CH1_SimulatorFre < Sti_FreRange[5]) || (CH2_SimulatorFre > Sti_FreRange[4] && CH2_SimulatorFre < Sti_FreRange[5]))
        {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::yellow;
        }
    }
    else {
            rectColor[0] = Qt::white; rectColor[1] = Qt::white;  rectColor[2] = Qt::white;  rectColor[3] = Qt::white;  rectColor[4] = Qt::white;
    }

    IBLS_AccomplishState = true;
}

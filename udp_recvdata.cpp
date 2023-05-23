#include "udp_recvdata.h"

UDP_RecvData::UDP_RecvData(QObject *parent, QUdpSocket *s) : QObject(parent), UDPSocket(s)
{

}

UDP_RecvData::~UDP_RecvData()
{

}

void UDP_RecvData::UDPRecvData()
{
    QByteArray datagram = NULL;
    while (UDPSocket->hasPendingDatagrams())  // 循环接收所有待处理的数据包
    {
        datagram.resize(static_cast<int>(UDPSocket->pendingDatagramSize()));  // 调整数据包的大小
        UDPSocket->readDatagram(datagram.data(), datagram.size());            // 读取数据包的内容
    }
    if (!datagram.isEmpty())
    {
        bool     ok=true;
        double   LSB = 2*4.5/(PGA*16777215);
        double   Voltage_AfterConve[8], *p;
        int32_t  Voltage_BeforeConve;
        QString  RecvDatastr = QString(datagram.toHex().trimmed().toUpper());
        for(uint8_t i=1; i<(CHn+1); i++)
        {
            uint8_t offset = 6*i;
            QString CHnData = RecvDatastr.mid(offset, 6);
            Voltage_BeforeConve = CHnData.toLong(&ok, 16);
            if((Voltage_BeforeConve & 0x800000) == 0x800000){
                Voltage_BeforeConve = Voltage_BeforeConve - 16777216;
            }
            Voltage_AfterConve[i-1] = Voltage_BeforeConve*LSB;
        }
        p = Voltage_AfterConve;

        if (HighPassFilterStatus == true)
        {
            for(uint8_t i=0; i<CHn; i++)
            {
                *(p+i) = FIR_HighPassFilter_01(*(p+i), &highpassfilter_pDelay[i]);
            }
        }
        if (TrapFilterStatus == true)
        {
            for(uint8_t i=0; i<CHn; i++)
            {
                *(p+i) = FIR_TrapFilter(*(p+i), &trapfilter_pDelay[i]);
            }
        }
        if (BandPassFilterStatus == true)
        {
            for(uint8_t i=0; i<CHn; i++)
            {
                *(p+i) = FIR_BandPassFilter(*(p+i), &bandpassfilter_pDelay[i]);
            }
        }
        if (CH_Mode == "Input_Short" && RmsPP_Status == true)
        {
            for (int i = 0; i < CHn; i++)
            {
                CHn_NoiseRMS[i] += (*(p+i)) * (*(p+i));
            }
            RmsPP_Count++;
            if (RmsPP_Count == CHn_Count)
            {
                QRWlock.lockForRead(); // 读取锁上锁
                for (int i = 0; i < CHn; i++)
                {
                    double maxValue, minValue;
                    QVector<double> CHn_Data = QVector<double>(2000, 0);
                    CHn_NoiseRMS[i] = qSqrt(CHn_NoiseRMS[i] / CHn_Count);
                    switch (i)
                    {
                        case (0): CHn_Data = CH1_Data; break;
                        case (1): CHn_Data = CH2_Data; break;
                        case (2): CHn_Data = CH3_Data; break;
                        case (3): CHn_Data = CH4_Data; break;
                        case (4): CHn_Data = CH5_Data; break;
                        case (5): CHn_Data = CH6_Data; break;
                        case (6): CHn_Data = CH7_Data; break;
                        case (7): CHn_Data = CH8_Data; break;
                    }
                    maxValue = *std::max_element(CHn_Data.constBegin(), CHn_Data.constEnd());
                    minValue = *std::min_element(CHn_Data.constBegin(), CHn_Data.constEnd());
                    CHn_NoisePP[i]  = maxValue - minValue;
                }
                QRWlock.unlock(); // 读取锁解锁
                for (int i = 0; i < CHn; i++)
                {
                    NoiseRMSPP += QString("CH%1 Noise RMS: %2 PP: %3\n").arg(i+1).arg(CHn_NoiseRMS[i]).arg(CHn_NoisePP[i]);  // 将计算数据转换为字符串
                    CHn_NoiseRMS[i] = 0;
                    CHn_NoisePP[i]  = 0;
                }
            }
        }
        QRWlock.lockForWrite(); // 写入锁上锁
        for(uint8_t i=0; i<CHn; i++)
        {
            switch (i)
            {
                case(0): CH1_Data.prepend(*p    ); CH1_Data.removeLast(); break;
                case(1): CH2_Data.prepend(*(p+1)); CH2_Data.removeLast(); break;
                case(2): CH3_Data.prepend(*(p+2)); CH3_Data.removeLast(); break;
                case(3): CH4_Data.prepend(*(p+3)); CH4_Data.removeLast(); break;
                case(4): CH5_Data.prepend(*(p+4)); CH5_Data.removeLast(); break;
                case(5): CH6_Data.prepend(*(p+5)); CH6_Data.removeLast(); break;
                case(6): CH7_Data.prepend(*(p+6)); CH7_Data.removeLast(); break;
                case(7): CH8_Data.prepend(*(p+7)); CH8_Data.removeLast(); break;
            }
        }
        QRWlock.unlock(); // 写入锁解锁

        FFT_Count++;
        if (FFT_Count == RR)
        {
            FFT_Count = 0;
            emit FFT_Signal();
        }
        RecvDataStatus = false;
    }
}

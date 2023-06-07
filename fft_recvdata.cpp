#include "fft_recvdata.h"

FFT_RecvData::FFT_RecvData(QObject *parent) : QObject(parent)
{

}

void FFT_RecvData::FFT_Transform()
{
    // 拷贝数据
    QRWlock.lockForRead(); // 读取锁上锁
    memcpy(FFT_CHnIn[0], CH1_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[1], CH2_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[2], CH3_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[3], CH4_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[4], CH5_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[5], CH6_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[6], CH7_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    memcpy(FFT_CHnIn[7], CH8_Data.data(), sizeof(double)*static_cast<unsigned long>(CHn_Count));
    QRWlock.unlock();      // 读取锁解锁
    // 执行FFT变换
    for (uint8_t i = 0; i < CHn; i++)
    {
        fftw_execute(FFT_CHn[i]);
    }
    // 将FFT变换后的结果取绝对值
    uint16_t Fre_Count = qFloor(CHn_Count/Fs)*HighFre;
    for(uint16_t i=0; i<Fre_Count; i++)
    {
        CH1_FFTAbsData[i] = abs(FFT_CHnOut[0][i]);
        CH2_FFTAbsData[i] = abs(FFT_CHnOut[1][i]);
        CH3_FFTAbsData[i] = abs(FFT_CHnOut[2][i]);
        CH4_FFTAbsData[i] = abs(FFT_CHnOut[3][i]);
        CH5_FFTAbsData[i] = abs(FFT_CHnOut[4][i]);
        CH6_FFTAbsData[i] = abs(FFT_CHnOut[5][i]);
        CH7_FFTAbsData[i] = abs(FFT_CHnOut[6][i]);
        CH8_FFTAbsData[i] = abs(FFT_CHnOut[7][i]);
    }

    FFTRecvDataStatus = true;
    emit FFT_Accomplish(); // FFT变换完成，发送FFT_Accomplish信号
}


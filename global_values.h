#ifndef GLOBAL_VALUES_H
#define GLOBAL_VALUES_H

#include <QWidget>
#include <QReadWriteLock>
#include <fftw-3.3.5-dll64/fftw3.h>

extern ushort  PGA;                  // 放大增益
extern ushort  CHn;                  // 通道数
extern uint16_t SPS;                 // 采样率
extern QString CH_Mode;              // 通道工作模式
extern QVector<double> CHn_NoiseRMS; // 存储每个通道噪声的均方根值
extern QVector<double> CHn_NoisePP;  // 存储每个通道噪声的峰峰值
extern bool RmsPP_Status;
extern QString NoiseRMSPP;
extern int RmsPP_Count;
extern double  yRange;               // 绘图y轴范围
extern QString yUnit;                // 绘图y轴坐标
extern int CHn_Count;
extern QVector<double> time_count;
extern QVector<double> CH1_Data;
extern QVector<double> CH2_Data;
extern QVector<double> CH3_Data;
extern QVector<double> CH4_Data;
extern QVector<double> CH5_Data;
extern QVector<double> CH6_Data;
extern QVector<double> CH7_Data;
extern QVector<double> CH8_Data;
extern QReadWriteLock QRWlock;
extern bool RecvDataStatus;
extern int HighFre;
extern double Fs;
extern double *FFT_CHnIn[8];
extern double *FFT_CHnOut[8];
extern bool FFTRecvDataStatus;
extern uint16_t FFT_Count;
extern QVector<double> fre_count;
extern QVector<double> CH1_FFTAbsData;
extern QVector<double> CH2_FFTAbsData;
extern QVector<double> CH3_FFTAbsData;
extern QVector<double> CH4_FFTAbsData;
extern QVector<double> CH5_FFTAbsData;
extern QVector<double> CH6_FFTAbsData;
extern QVector<double> CH7_FFTAbsData;
extern QVector<double> CH8_FFTAbsData;
extern fftw_plan FFT_CHn[8];
extern double fft_ymin;
extern double fft_ymax;

#endif // GLOBAL_VALUES_H

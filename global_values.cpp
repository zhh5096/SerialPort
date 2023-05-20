#include "global_values.h"

/* ADS1299参数 */
ushort PGA = 1;                                       // 放大增益
ushort CHn = 8;                                       // 通道数
uint16_t SPS = 500;                                   // 采样率
QString CH_Mode = "Normal_Input";                     // ADS1299工作模式
QVector<double> CHn_NoiseRMS = QVector<double>(8, 0); // 存储每个通道噪声的均方根值
QVector<double> CHn_NoisePP  = QVector<double>(8, 0); // 存储每个通道噪声的峰峰值
bool RmsPP_Status = false;                            // 均方值和峰峰值计算标志
int RmsPP_Count = 0;                                  // 均方值和峰峰值计算点数
QString NoiseRMSPP;                                   // 噪声RMS和PP
/* 绘图参数 */
double yRange = 0;
QString yUnit = "mV";
int CHn_Count = 2000;
/* 接受数据缓存 */
QVector<double> time_count = QVector<double>(2000, 0);
QVector<double> CH1_Data   = QVector<double>(2000, 0);
QVector<double> CH2_Data   = QVector<double>(2000, 0);
QVector<double> CH3_Data   = QVector<double>(2000, 0);
QVector<double> CH4_Data   = QVector<double>(2000, 0);
QVector<double> CH5_Data   = QVector<double>(2000, 0);
QVector<double> CH6_Data   = QVector<double>(2000, 0);
QVector<double> CH7_Data   = QVector<double>(2000, 0);
QVector<double> CH8_Data   = QVector<double>(2000, 0);
/* 串口功能数据 */
QReadWriteLock QRWlock;                                // 读写锁
bool RecvDataStatus = false;                           // 串口接收数据状态标志
uint16_t FFT_Count = 0;                                // 串口接收数据个数到FFT_Count时，发出FFT变换的信号
/* 频域数据缓存 */
int HighFre = 60;
double Fs = 500;
double *FFT_CHnIn[8];
double *FFT_CHnOut[8];
bool FFTRecvDataStatus = false;                        // FFT变换完成标志
// 存储每个通道FFT变换取绝对值的数据
QVector<double> fre_count        = QVector<double>(1000, 0);
QVector<double> CH1_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH2_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH3_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH4_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH5_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH6_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH7_FFTAbsData   = QVector<double>(1000, 0);
QVector<double> CH8_FFTAbsData   = QVector<double>(1000, 0);
fftw_plan FFT_CHn[8];
double fft_ymin = 0;
double fft_ymax = 1.0;

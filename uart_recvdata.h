#ifndef UART_RECVDATA_H
#define UART_RECVDATA_H

#include <QObject>
#include <QDebug>
#include <QtMath>
#include <QTextEdit>
#include <QSerialPort>

#include "global_values.h"
#include "highpassfilter_cofficient.h"
#include "fir_highpassfilter.h"
#include "trapfilter_cofficient.h"
#include "fir_trapfilter.h"
#include "bandpassfilter_cofficient.h"
#include "fir_bandpassfilter.h"
#include "lowpassfilter_cofficient.h"
#include "fir_lowpassfilter.h"

class Uart_RecvData : public QObject
{
    Q_OBJECT
public:
    explicit Uart_RecvData(QObject *parent=nullptr, QSerialPort *S=nullptr);

signals:
    void FFT_Signal(); // 串口发出的FFT变换信号
    void EOG_Signal(); // 串口发出的EOG检测信号

private:
    QSerialPort *Uart; // QSerialPort提供访问串行端口的功能。

private slots:
    void UartRecvData();
};

#endif // UART_RECVDATA_H

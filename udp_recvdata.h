#ifndef UDP_RECVDATA_H
#define UDP_RECVDATA_H

#include <QObject>
#include <QDebug>
#include <QtMath>
#include <QTextEdit>
#include <QUdpSocket>

#include "global_values.h"
#include "highpassfilter_cofficient.h"
#include "fir_highpassfilter.h"
#include "trapfilter_cofficient.h"
#include "fir_trapfilter.h"
#include "bandpassfilter_cofficient.h"
#include "fir_bandpassfilter.h"
#include "lowpassfilter_cofficient.h"
#include "fir_lowpassfilter.h"

class UDP_RecvData : public QObject
{
    Q_OBJECT
public:
    explicit UDP_RecvData(QObject *parent = nullptr,  QUdpSocket *S=nullptr);
    ~UDP_RecvData();

public slots:
    void UDPRecvData();

signals:
    void FFT_Signal(); // UDP发出的FFT变换信号

private:
    QUdpSocket* UDPSocket;
};

#endif // UDP_RECVDATA_H

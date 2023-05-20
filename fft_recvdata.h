#ifndef FFT_RECVDATA_H
#define FFT_RECVDATA_H

#include <QObject>
#include <QtMath>
#include "global_values.h"

class FFT_RecvData : public QObject
{
    Q_OBJECT
public:
    explicit FFT_RecvData(QObject *parent = nullptr);

signals:

private slots:
    void FFT_Transform();
};

#endif // FFT_RECVDATA_H

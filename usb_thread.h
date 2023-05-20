#ifndef USB_THREAD_H
#define USB_THREAD_H
#include <QDebug>
#include <QMutex>
#include <QThread>
#include "hidapi.h"


class USB_Thread : public QThread
{
    Q_OBJECT
signals:
    void updateString11(QString);

protected:
    void run();

public:
    hid_device *handle;
    USB_Thread();
    void closeThread();

private:
    volatile bool isStop;       // isStop是易失性变量，需要用volatile进行申明
};

#endif // USB_THREAD_H

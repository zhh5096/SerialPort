#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFileDialog>
#include <QTest>
#include <QList>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <QUdpSocket>
#include <QHostAddress>
#include <QSharedPointer>

#include "global_values.h"
#include "qcustomplot.h"
#include "uart_recvdata.h"
#include "fft_recvdata.h"
#include "udp_recvdata.h"
#include "hidapi.h"
#include "usb_thread.h"
#include "highpassfilter_cofficient.h"
#include "trapfilter_cofficient.h"
#include "bandpassfilter_cofficient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QCustomPlot *customPlot;
    QLineEdit *lineEdit_YRange;

    void selectFunction();
    void eegDataPlotConfig();
    void setUartMessageState();

private:
    Ui::Widget *ui;

    QTimer *PlotTimer;

    bool UartState=false;
    QString mUartMessage[5] = {};       // 用于存储串口信息的字符串数组
    QSerialPort mUart;                  // 串口
    QThread* UartThread;                // 串口子线程
    Uart_RecvData* Uart_RecvDataThread; // 自定义的串口子线程类

    bool UDPState=false;
    QUdpSocket mUDP;                   // UDP
    QThread* UDPThread;                // UDP子线程
    UDP_RecvData* UDP_RecvDataThread;  // 自定义的UDP子线程类

    hid_device *handle;
    unsigned char buf_IN[64];
    bool start_flag=false;
    USB_Thread* usbThread;

    QThread* FFTThread;                 // FFT子线程
    FFT_RecvData* FFT_RecvDataThread;   // 自定义的FFT子线程类

private slots:
    void closeAllThreads();
    void eegDataPlotUpdate();
    void on_PBtn_UartOpen_clicked();
    void on_PBtn_UDPOpen_clicked();
    void on_PBtn_Refresh_clicked();
    void on_PBtn_UsbOpen_clicked();
    void on_PBtn_HighPassFilter_clicked();
    void on_PBtn_TrapFilter_clicked();
    void on_PBtn_BandPassFilter_clicked();
    void on_PBtn_RmsPP_clicked();
    void updateUsb(QString);
    void on_PBtn_UsbRecv_clicked();
    void on_PBtn_UsbSend_clicked();
    void on_Slider_FFTyrange_valueChanged(int value);
    void on_Slider_FFrr_valueChanged(int value);
};
#endif // WIDGET_H

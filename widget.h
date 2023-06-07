#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDate>
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
#include "udp_recvdata.h"
#include "hidapi.h"
#include "fft_recvdata.h"
#include "arithmetic.h"

#include "highpassfilter_cofficient.h"
#include "trapfilter_cofficient.h"
#include "bandpassfilter_cofficient.h"
#include "lowpassfilter_cofficient.h"
#include "stimulusmetagraphics.h"

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
    void drawStimulusmetaGraphs();
    void setFir_filter();
    void setFFT_plan();

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

    QThread* FFTThread;                 // FFT子线程
    FFT_RecvData* FFT_RecvDataThread;   // 自定义的FFT子线程类

    QThread* ArithmeticThread;          // 算法子线程
    arithmetic* Arithmetic_Thread;      // 自定义的算法子线程类

private slots:
    void closeAllThreads();
    void eegDataPlotUpdate();
    void on_PBtn_UartOpen_clicked();
    void on_PBtn_UDPOpen_clicked();
    void on_PBtn_Refresh_clicked();
    void on_PBtn_HighPassFilter_clicked();
    void on_PBtn_TrapFilter_clicked();
    void on_PBtn_BandPassFilter_clicked();
    void on_PBtn_LowPassFilter_clicked();
    void on_PBtn_RmsPP_clicked();
    void setFFTMessage();
    void on_PBtn_SaveRecvData_clicked();
    void on_PBtn_CCA_clicked();
    void on_Slider_FFTrr_valueChanged();
    void on_PBtn_IBLS_clicked();
};
#endif // WIDGET_H

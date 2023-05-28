#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    selectFunction();                                                       // 选择串口，USB，无线
    eegDataPlotConfig();                                                    // 绘图界面初始化配置

    PlotTimer = new QTimer();
    PlotTimer->setInterval(80);                                             // 每隔80ms刷新
    connect(PlotTimer, SIGNAL(timeout()), this, SLOT(eegDataPlotUpdate())); // 接收到定时器发出的信号，更新绘图界面

    /* 串口子线程 */
    Uart_RecvDataThread = new Uart_RecvData(nullptr, &mUart);               // 给串口接收数据子线程分配动态空间，但不能指定父对象
    UartThread = new QThread(this);                                         // 给串口接收数据子线程分配动态内存空间，指定当前线程为父对象
    Uart_RecvDataThread->moveToThread(UartThread);                          // 将自定义的串口接收数据子线程加入到子线程中

    /* UDP子线程 */
    UDP_RecvDataThread = new UDP_RecvData(nullptr, &mUDP);                  // 给UDP接收数据子线程分配动态空间，但不能指定父对象
    UDPThread = new QThread(this);                                          // 给UDP接收数据子线程分配动态内存空间，指定当前线程为父对象
    UDP_RecvDataThread->moveToThread(UDPThread);                            // 将自定义的UDP接收数据子线程加入到子线程中
    connect(&mUDP, &QUdpSocket::readyRead, UDP_RecvDataThread, &UDP_RecvData::UDPRecvData, Qt::DirectConnection);

    /* 频域变换子线程 */
    FFT_RecvDataThread = new FFT_RecvData(nullptr);                         // 给频域变换子线程分配动态空间，但不能指定父对象
    FFTThread  = new QThread(this);                                         // 给频域变换子线程分配动态内存空间，指定当前线程为父对象
    FFT_RecvDataThread->moveToThread(FFTThread);                            // 将自定义的频域变换子线程加入到子线程中

    // 串口子线程发出信号，频域变换子线程接收到信号后进行FFT变换
    connect(Uart_RecvDataThread, SIGNAL(FFT_Signal()), FFT_RecvDataThread, SLOT(FFT_Transform()), Qt::DirectConnection);
    // UDP子线程发出信号，频域变化子线程收到信号后进行FFT变换
    connect(UDP_RecvDataThread, SIGNAL(FFT_Signal()), FFT_RecvDataThread, SLOT(FFT_Transform()), Qt::DirectConnection);


    /* 设置滤波器 */
    for (uint8_t i = 0; i < CHn; i++)
    {
        Highpassfilter_CreateListHear(&highpassfilter_pDelay[i], FIR_Highpassfilter_FilterLength); // 用于存放每个通道过去时刻经高通滤波后的滤波结果
        Bandpassfilter_CreateListHear(&bandpassfilter_pDelay[i], FIR_Bandpassfilter_FilterLength); // 用于存放每个通道过去时刻经带通滤波后的滤波结果
        Trapfilter_CreateListHear(&trapfilter_pDelay[i], FIR_Trapfilter_FilterLength);             // 用于存放每个通道过去时刻经陷波滤波后的滤波结果
    }

    /* 设置FFT Plan */
    for (uint8_t i = 0; i < CHn; i++)
    {
        FFT_CHnIn[i]  = fftw_alloc_real(static_cast<size_t>(CHn_Count));
        FFT_CHnOut[i] = fftw_alloc_real(static_cast<size_t>(CHn_Count));
        FFT_CHn[i] = fftw_plan_r2r_1d(CHn_Count, FFT_CHnIn[i], FFT_CHnOut[i], FFTW_R2HC, FFTW_ESTIMATE);
    }

    connect(this, &Widget::destroyed, this, &Widget::closeAllThreads);      // 关闭所有子线程
}


Widget::~Widget()
{
    delete ui;

    /* 释放频域变换子线程变量占据的内存空间 */
    for (uint8_t i = 0; i < CHn; i++)
    {
        fftw_free(FFT_CHnIn[i]);
        fftw_free(FFT_CHnOut[i]);
        fftw_destroy_plan(FFT_CHn[i]);
    }
}

/*
    函   数：closeAllThreads
    描   述：释放所有开启的子线程
    输   入：无
    输   出：无
*/
void Widget::closeAllThreads()
{
    delete UartThread;
    delete Uart_RecvDataThread;   // 释放串口接收数据子线程空间
    delete UDPThread;
    delete UDP_RecvDataThread;    // 释放UDP接收数据子线程空间
    delete FFTThread;
    delete FFT_RecvDataThread;    // 释放频域变换子线程空间
}

/*
    函   数：selectFunction
    描   述：选择串口、USB、无线功能
    输   入：无
    输   出：无
*/
void Widget::selectFunction()
{
    connect(ui->PBtn_uart, &QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->PBtn_usb,  &QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->PBtn_udp,  &QPushButton::clicked,[=](){ui->stackedWidget->setCurrentIndex(2);});
}


/*
    函   数：eegDataPlotConfig
    描   述：绘图界面初始化配置
    输   入：无
    输   出：无
*/
void Widget::eegDataPlotConfig()
{
    for (int i = 0;i < 8;i++)
    {
        switch(i)
        {
            case(0): customPlot = ui->customPlot_1; break;
            case(1): customPlot = ui->customPlot_2; break;
            case(2): customPlot = ui->customPlot_3; break;
            case(3): customPlot = ui->customPlot_4; break;
            case(4): customPlot = ui->customPlot_5; break;
            case(5): customPlot = ui->customPlot_6; break;
            case(6): customPlot = ui->customPlot_7; break;
            case(7): customPlot = ui->customPlot_8; break;
        }
        customPlot->xAxis->setLabel("");                    // 清空键轴（底部x轴）标签
        customPlot->yAxis->setLabel("");                    // 清空值轴（左侧y轴）标签
        customPlot->xAxis->setTickLabels(false);            // 设置键轴（底部x轴）标签不显示刻度值
        customPlot->xAxis->setVisible(false);               // 设置键轴（底部x轴）不显示刻度线
        customPlot->xAxis->setRange(0, CHn_Count);          // 设置键轴（底部x轴）范围
        customPlot->yAxis->setRange(-0.001, 0.001);         // 设置值轴（左侧y轴）范围
        /* 将底部x轴和左侧y轴的范围转移到顶部x轴和右侧y轴上，使上下两个x轴的范围相等，左右两个y轴范围相等 */
        connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
        connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
        customPlot->axisRect()->setBackground(QBrush(Qt::white));
    }
    ui->customplot_9->xAxis->setRange(0, 60);
    ui->customplot_9->yAxis->setRange(0,1);
    ui->customplot_9->xAxis->setLabel("频率/HZ");
    ui->customplot_9->yAxis->setLabel("幅值/V");
}


/*
    函   数：eegDataPlotUpdate
    描   述：更新绘图
    输   入：无
    输   出：无
*/
void Widget::eegDataPlotUpdate()
{
    if(RecvDataStatus == false)
    {
        // 绘制时域图
        QRWlock.lockForRead(); // 读取锁上锁
        for (uint8_t i=0; i<CHn; i++)
        {
            switch(i)
            {
                case(0): customPlot = ui->customPlot_1; ui->customPlot_1->graph(0)->setData(time_count, CH1_Data); break;
                case(1): customPlot = ui->customPlot_2; ui->customPlot_2->graph(0)->setData(time_count, CH2_Data); break;
                case(2): customPlot = ui->customPlot_3; ui->customPlot_3->graph(0)->setData(time_count, CH3_Data); break;
                case(3): customPlot = ui->customPlot_4; ui->customPlot_4->graph(0)->setData(time_count, CH4_Data); break;
                case(4): customPlot = ui->customPlot_5; ui->customPlot_5->graph(0)->setData(time_count, CH5_Data); break;
                case(5): customPlot = ui->customPlot_6; ui->customPlot_6->graph(0)->setData(time_count, CH6_Data); break;
                case(6): customPlot = ui->customPlot_7; ui->customPlot_7->graph(0)->setData(time_count, CH7_Data); break;
                case(7): customPlot = ui->customPlot_8; ui->customPlot_8->graph(0)->setData(time_count, CH8_Data); break;
            }
            customPlot->replot(QCustomPlot::rpQueuedReplot);    // 立即刷新图像
        }
        QRWlock.unlock(); // 读取锁解锁

        if (RmsPP_Count >= CHn_Count)
        {
            ui->Txt_CHnNoise->clear();
            ui->Txt_CHnNoise->setText(NoiseRMSPP);
            NoiseRMSPP = "";
            RmsPP_Count = 0;
        }

        // 绘制频域图
        if (FFTRecvDataStatus == true)
        {
            for (uint8_t i=0; i<CHn; i++)
            {
                switch (i)
                {
                    case(0): ui->customplot_9->graph(0)->setData(fre_count, CH1_FFTAbsData); break;
                    case(1): ui->customplot_9->graph(1)->setData(fre_count, CH2_FFTAbsData); break;
                    case(2): ui->customplot_9->graph(2)->setData(fre_count, CH3_FFTAbsData); break;
                    case(3): ui->customplot_9->graph(3)->setData(fre_count, CH4_FFTAbsData); break;
                    case(4): ui->customplot_9->graph(4)->setData(fre_count, CH5_FFTAbsData); break;
                    case(5): ui->customplot_9->graph(5)->setData(fre_count, CH6_FFTAbsData); break;
                    case(6): ui->customplot_9->graph(6)->setData(fre_count, CH7_FFTAbsData); break;
                    case(7): ui->customplot_9->graph(7)->setData(fre_count, CH8_FFTAbsData); break;
                }
            }
            ui->customplot_9->replot(QCustomPlot::rpQueuedReplot);    // 立即刷新图像
            FFTRecvDataStatus = false;
        }

        RecvDataStatus = true;
    }
}


/*
    函   数：on_PBtn_UartOpen_clicked
    描   述：打开串口
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_UartOpen_clicked()
{
    /* 判断当前是否有可用串口 */
    if (!ui->CBox_Uart->currentText().isEmpty())
    {
        /* 串口接收数据子线程线程没有在运行，主线程点击打开按键，发送串口信息，开启串口子线程 */
        if (UartThread->isRunning() == false)
        {
            mUartMessage[0] = ui->CBox_Uart->currentText();
            mUartMessage[1] = ui->CBox_Baudrate->currentText();
            mUartMessage[2] = ui->CBox_Parity->currentText();
            mUartMessage[3] = ui->CBox_DataBits->currentText();
            mUartMessage[4] = ui->CBox_StopBits->currentText();
            /* 串口号 */
            mUart.setPortName(mUartMessage[0]);
            /* 波特率 */
            if ("9600" == mUartMessage[1])
            {
                mUart.setBaudRate(QSerialPort::Baud9600);
            }
            else if ("19200" == mUartMessage[1])
            {
                mUart.setBaudRate(QSerialPort::Baud19200);
            }
            else if ("115200" == mUartMessage[1])
            {
                mUart.setBaudRate(QSerialPort::Baud115200);
            }
            else if ("540000" == mUartMessage[1]){
                mUart.setBaudRate(540000);
            }
            /* 校验位 */
            if ("NONE" == mUartMessage[2])
            {
                mUart.setParity(QSerialPort::NoParity);
            }
            else if ("ODD" == mUartMessage[2])
            {
                mUart.setParity(QSerialPort::OddParity);
            }
            else if ("EVEN" == mUartMessage[2])
            {
                mUart.setParity(QSerialPort::EvenParity);
            }
            else
            {
                mUart.setParity(QSerialPort::MarkParity);
            }
            /* 数据位 */
            if ("5" == mUartMessage[3])
            {
                mUart.setDataBits(QSerialPort::Data5);
            }
            else if ("6" == mUartMessage[3])
            {
                mUart.setDataBits(QSerialPort::Data6);
            }
            else if ("7" == mUartMessage[3])
            {
                mUart.setDataBits(QSerialPort::Data7);
            }
            else
            {
                mUart.setDataBits(QSerialPort::Data8);
            }
            /* 停止位 */
            if ("1" == mUartMessage[4])
            {
                mUart.setStopBits(QSerialPort::OneStop);
            }
            else if ("1.5" == mUartMessage[4])
            {
                mUart.setStopBits(QSerialPort::OneAndHalfStop);
            }
            else
            {
                mUart.setStopBits(QSerialPort::TwoStop);
            }
            UartState = mUart.open(QSerialPort::ReadWrite);     // 开启串口
            if(UartState == true)
            {
                UartThread->start();                            // 开启串口子线程
                setUartMessageState();                          // 设置串口参数为不可访问状态
            }
            else
            {
                QMessageBox::information(this, QString::fromLocal8Bit(" Error "), QString::fromLocal8Bit(" Failed to open the serial port. "));
                return;
            }
            PlotTimer->start();                                 // 启动定时器，更新绘图函数
        }
        /* 串口子线程正在运行，主线程点击关闭按键，关闭串口，更改串口当前状态标志，挂起主线程一段时间，关闭串口子线程，设置串口参数为可访问状态 */
        else
        {
            UartThread->quit();                                 // 关闭串口子线程
            UartThread->wait();                                 // 等待子线程退出
            mUart.close();                                      // 关闭串口
            UartState = false;                                  // 更改串口当前状态标志
            setUartMessageState();                              // 设置串口参数为可访问状态
            PlotTimer->stop();                                  // 关闭定时器
        }
    }
    else
    {
        QMessageBox::information(this, QString::fromLocal8Bit(" Warning "), QString::fromLocal8Bit(" No serial port is available. "));
        return;
    }
}


/*
    函   数：setUartMessageState
    描   述：设置按钮状态
    输   入：无
    输   出：无
*/
void Widget::setUartMessageState()
{
    if (UartState == false){
        ui->PBtn_UartOpen->setText(QString::fromLocal8Bit(" Open "));
        ui->CBox_Uart->setEnabled(true);
        ui->CBox_Baudrate->setEnabled(true);
        ui->CBox_Parity->setEnabled(true);
        ui->CBox_DataBits->setEnabled(true);
        ui->CBox_StopBits->setEnabled(true);
        ui->CBox_PGA->setEnabled(true);
        ui->CBox_CHn->setEnabled(true);
        ui->PBtn_uart->setEnabled(true);
        ui->PBtn_usb->setEnabled(true);
        ui->PBtn_udp->setEnabled(true);
        ui->PBtn_Refresh->setEnabled(true);
        ui->CBox_CH_Mode->setEnabled(true);
        ui->CBox_YUnit->setEnabled(true);
        ui->Ledit_YRange->setEnabled(true);
        ui->PBtn_HighPassFilter->setEnabled(false);
        ui->PBtn_TrapFilter->setEnabled(false);
        ui->PBtn_BandPassFilter->setEnabled(false);
        ui->PBtn_LowPassFilter->setEnabled(false);
        ui->PBtn_RmsPP->setEnabled(false);
    }
    else{
        ui->PBtn_UartOpen->setText(QString::fromLocal8Bit( "Close" ));
        ui->CBox_Uart->setEnabled(false);
        ui->CBox_Baudrate->setEnabled(false);
        ui->CBox_Parity->setEnabled(false);
        ui->CBox_DataBits->setEnabled(false);
        ui->CBox_StopBits->setEnabled(false);
        ui->CBox_PGA->setEnabled(false);
        ui->CBox_CHn->setEnabled(false);
        ui->PBtn_uart->setEnabled(false);
        ui->PBtn_usb->setEnabled(false);
        ui->PBtn_udp->setEnabled(false);
        ui->PBtn_Refresh->setEnabled(false);
        ui->CBox_CH_Mode->setEnabled(false);
        ui->CBox_YUnit->setEnabled(false);
        ui->Ledit_YRange->setEnabled(false);
        ui->PBtn_HighPassFilter->setEnabled(true);
        ui->PBtn_TrapFilter->setEnabled(true);
        ui->PBtn_BandPassFilter->setEnabled(true);
        ui->PBtn_LowPassFilter->setEnabled(true);
        ui->PBtn_RmsPP->setEnabled(true);
    }
}


/*
    函   数：on_PBtn_UDPOpen_clicked
    描   述：打开UDP
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_UDPOpen_clicked()
{
    if (!ui->Ledit_hostIPaddress->text().isEmpty() && !ui->Ledit_port->text().isEmpty()) {
        UDPState = !UDPState;
        if (UDPState == true)
        {
            IP_Address = ui->Ledit_hostIPaddress->text();
            Port = ui->Ledit_port->text().toUShort();
            mUDP.bind(QHostAddress(IP_Address), Port);  // 绑定到指定的地址和端口
            UDPThread->start();                         // 开启UDP子线程
            ui->PBtn_UDPOpen->setText(QString::fromLocal8Bit(" close "));
            PlotTimer->start();                         // 启动定时器，更新绘图函数
        }
        else
        {
            UDPThread->quit();                          // 关闭UDP子线程
            UDPThread->wait();                          // 等待子线程退出
            mUDP.close();
            ui->PBtn_UDPOpen->setText(QString::fromLocal8Bit(" open "));
            PlotTimer->stop();                          // 关闭定时器
        }
    }
    else {
        QMessageBox::information(this, QString::fromLocal8Bit(" Warning "), QString::fromLocal8Bit(" No valid IP Address or Port is available. "));
        return;
    }
}


/*
    函   数：on_PBtn_Refresh_clicked
    描   述：刷新，查找新的串口并添加到CBoxSerialPort，设置界面Y轴范围
    输   入：yRange、yUnit、CH_Mode、CHn、PGA
    输   出：yRange、yUnit、CH_Mode、CHn、PGA
*/
void Widget::on_PBtn_Refresh_clicked()
{
    ui->CBox_Uart->clear();
    /* 遍历可用的串口设备并添加到串口设备显示框 */
    QList<QSerialPortInfo> serialPortInfo;
    serialPortInfo = QSerialPortInfo::availablePorts();             // 获取可用串口列表
    int count = serialPortInfo.count();                             // 可用串口数量
    for (int i=0; i<count; i++) {
        ui->CBox_Uart->addItem(serialPortInfo.at(i).portName());    // 将可用串口号添加到串口设备显示框
    }
    PGA = ui->CBox_PGA->currentText().toUShort();
    CHn = ui->CBox_CHn->currentText().toUShort();
    CH_Mode = ui->CBox_CH_Mode->currentText();
    yRange = ui->Ledit_YRange->text().toDouble();
    yUnit = ui->CBox_YUnit->currentText();
    setFFTMessage();
    /* 如果串口已关闭，则可以更新绘图界面 */
    if (UartState == false)
    {
        ushort line_width = 1;  // 设置线宽
        // 设置X轴坐标范围
        for(uint16_t i=0; i<CHn_Count; i++)
        {
            time_count[i] = i;
            for (uint8_t j=0; j<CHn; j++)
            {
                switch (j)
                {
                    case(0): CH1_Data[i] = 0; break;
                    case(1): CH2_Data[i] = 0; break;
                    case(2): CH3_Data[i] = 0; break;
                    case(3): CH4_Data[i] = 0; break;
                    case(4): CH5_Data[i] = 0; break;
                    case(5): CH6_Data[i] = 0; break;
                    case(6): CH7_Data[i] = 0; break;
                    case(7): CH8_Data[i] = 0; break;
                }
            }
        }
        // 设置Y轴坐标范围
        if ("mV" == yUnit)
        {
            yRange = yRange / 1000.0;
        }
        else
        {
            yRange = yRange / 1000000.0;
        }
        for (uint8_t i = 0;i < CHn;i++)
        {
            switch(i)
            {
                case(0): customPlot = ui->customPlot_1; break;
                case(1): customPlot = ui->customPlot_2; break;
                case(2): customPlot = ui->customPlot_3; break;
                case(3): customPlot = ui->customPlot_4; break;
                case(4): customPlot = ui->customPlot_5; break;
                case(5): customPlot = ui->customPlot_6; break;
                case(6): customPlot = ui->customPlot_7; break;
                case(7): customPlot = ui->customPlot_8; break;
            }
            customPlot->yAxis->setRange(-yRange, yRange);
        }
        // 清空所有图层并重新绘图
        for (uint8_t i=0; i<CHn; i++)
        {
            switch(i)
            {
                case(0): customPlot = ui->customPlot_1; break;
                case(1): customPlot = ui->customPlot_2; break;
                case(2): customPlot = ui->customPlot_3; break;
                case(3): customPlot = ui->customPlot_4; break;
                case(4): customPlot = ui->customPlot_5; break;
                case(5): customPlot = ui->customPlot_6; break;
                case(6): customPlot = ui->customPlot_7; break;
                case(7): customPlot = ui->customPlot_8; break;
            }
            customPlot->clearGraphs();
            customPlot->replot();
        }
        // 设置线宽
        for (uint8_t i=0; i<CHn; i++)
        {
            switch (i)
            {
                case(0): ui->customPlot_1->addGraph(); ui->customPlot_1->graph(0)->setPen(QPen(Qt::black,       line_width)); break;
                case(1): ui->customPlot_2->addGraph(); ui->customPlot_2->graph(0)->setPen(QPen(Qt::darkRed,     line_width)); break;
                case(2): ui->customPlot_3->addGraph(); ui->customPlot_3->graph(0)->setPen(QPen(Qt::darkGreen,   line_width)); break;
                case(3): ui->customPlot_4->addGraph(); ui->customPlot_4->graph(0)->setPen(QPen(Qt::darkBlue,    line_width)); break;
                case(4): ui->customPlot_5->addGraph(); ui->customPlot_5->graph(0)->setPen(QPen(Qt::darkCyan,    line_width)); break;
                case(5): ui->customPlot_6->addGraph(); ui->customPlot_6->graph(0)->setPen(QPen(Qt::darkMagenta, line_width)); break;
                case(6): ui->customPlot_7->addGraph(); ui->customPlot_7->graph(0)->setPen(QPen(Qt::darkYellow,  line_width)); break;
                case(7): ui->customPlot_8->addGraph(); ui->customPlot_8->graph(0)->setPen(QPen(Qt::darkGray,    line_width)); break;
            }
        }
        // 设置频域X轴坐标范围
        for(uint16_t i=0; i<qFloor(CHn_Count/Fs)*HighFre; i++)
        {
            fre_count[i] = i*Fs/CHn_Count;
            CH1_FFTAbsData[i] = 0;
            CH2_FFTAbsData[i] = 0;
            CH3_FFTAbsData[i] = 0;
            CH4_FFTAbsData[i] = 0;
            CH5_FFTAbsData[i] = 0;
            CH6_FFTAbsData[i] = 0;
            CH7_FFTAbsData[i] = 0;
            CH8_FFTAbsData[i] = 0;
        }
        for (uint8_t i = 0; i<CHn; i++)
        {
            ui->customplot_9->addGraph();
            switch(i)
            {
                case(0): ui->customplot_9->graph(0)->setPen(QPen(Qt::black,       line_width));break;
                case(1): ui->customplot_9->graph(1)->setPen(QPen(Qt::darkRed,     line_width));break;
                case(2): ui->customplot_9->graph(2)->setPen(QPen(Qt::darkGreen,   line_width));break;
                case(3): ui->customplot_9->graph(3)->setPen(QPen(Qt::darkBlue,    line_width));break;
                case(4): ui->customplot_9->graph(4)->setPen(QPen(Qt::darkCyan,    line_width));break;
                case(5): ui->customplot_9->graph(5)->setPen(QPen(Qt::darkMagenta, line_width));break;
                case(6): ui->customplot_9->graph(6)->setPen(QPen(Qt::darkYellow,  line_width));break;
                case(7): ui->customplot_9->graph(7)->setPen(QPen(Qt::darkGray,    line_width));break;
            }
        }
        ui->customplot_9->xAxis->setRange(0, HighFre);
        FFTRecvDataStatus = true;
        RecvDataStatus = false;
        eegDataPlotUpdate();
    }
}


/*
    函   数：setFFTMessage
    描   述：设置FFT图像参数
    输   入：无
    输   出：无
*/
void Widget::setFFTMessage()
{
    QString selectedFreq = ui->CBox_Freq->currentText();
    QString selectedAmpl = ui->CBox_Ampl->currentText();
    int sliderValue = ui->Slider_FFTrr->value();

    /* fft截止频率 */
    if (selectedFreq == "60 Hz")
        HighFre = 60;
    else if (selectedFreq == "70 Hz")
        HighFre = 70;
    else if (selectedFreq == "80 Hz")
        HighFre = 80;
    else if (selectedFreq == "90 Hz")
        HighFre = 90;
    else
        HighFre = 100;

    /* fft幅值 */
    if (selectedAmpl == "1 V")
        ui->customplot_9->yAxis->setRange(0, 1);
    else if (selectedAmpl == "100 mV")
        ui->customplot_9->yAxis->setRange(0, 0.1);
    else if (selectedAmpl == "10 mV")
        ui->customplot_9->yAxis->setRange(0, 0.01);
    else if (selectedAmpl == "1 mV")
        ui->customplot_9->yAxis->setRange(0, 0.001);
    else
        ui->customplot_9->yAxis->setRange(0, 0.0001);
    ui->customplot_9->replot();

    /* FFT刷新速率 */
    double range = fft_rrmax - fft_rrmin;
    double scaledValue = sliderValue / 100.0;
    double fft_rrRange = scaledValue * range;
    RR = fft_rrmin + fft_rrRange;
}


/*
    函   数：on_PBtn_HighPassFilter_clicked
    描   述：高通滤波
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_HighPassFilter_clicked()
{
    if(UartState == true)
    {
        if(HighPassFilterStatus == false)
        {
            ui->PBtn_HighPassFilter->setStyleSheet("background-color: rgb(0, 170, 255);");
            HighPassFilterStatus = true;
        }
        else
        {
            ui->PBtn_HighPassFilter->setStyleSheet("background-color: rgb(255, 255, 255);");
            HighPassFilterStatus = false;
        }
    }
}


/*
    函   数：on_PBtn_TrapFilter_clicked
    描   述：陷波滤波
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_TrapFilter_clicked()
{
    if(UartState == true)
    {
        if(TrapFilterStatus == false)
        {
            ui->PBtn_TrapFilter->setStyleSheet("background-color: rgb(0, 170, 255);");
            TrapFilterStatus = true;
        }
        else
        {
            ui->PBtn_TrapFilter->setStyleSheet("background-color: rgb(255, 255, 255);");
            TrapFilterStatus = false;
        }
    }
}


/*
    函   数：on_PBtn_BandPassFilter_clicked
    描   述：带通滤波
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_BandPassFilter_clicked()
{
    if(UartState == true)
    {
        if(BandPassFilterStatus == false)
        {
            ui->PBtn_BandPassFilter->setStyleSheet("background-color: rgb(0, 170, 255);");
            BandPassFilterStatus = true;
        }
        else
        {
            ui->PBtn_BandPassFilter->setStyleSheet("background-color: rgb(255, 255, 255);");
            BandPassFilterStatus = false;
        }
    }
}


/*
    函   数：on_PBtn_Rms_clicked
    描   述：打开均方根和峰峰值测量
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_RmsPP_clicked()
{
    if(UartState == true)
    {
        if(RmsPP_Status == false)
        {
            ui->PBtn_RmsPP->setStyleSheet("background-color: rgb(0, 170, 255);");
            RmsPP_Status = true;
        }
        else
        {
            ui->PBtn_RmsPP->setStyleSheet("background-color: rgb(255, 255, 255);");
            RmsPP_Status = false;
        }
    }
}


/*
    函   数：on_PBtn_UsbOpen_clicked
    描   述：打开USB
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_UsbOpen_clicked()
{
    hid_init();   // 初始化
    qDebug()<<handle;
    handle = hid_open(0x0483, 0x5750, NULL);    // 获取VID,PID
    qDebug()<<handle;
    if(handle == NULL)
    {
        QMessageBox::information(this, "warn", "未检测到设备！");
        ui->PBtn_uart->setEnabled(true);
        ui->PBtn_usb->setEnabled(true);
        ui->PBtn_udp->setEnabled(true);
    }
    else
    {
        hid_set_nonblocking(handle, 1);
        usbThread=new USB_Thread;
        usbThread->start();
        connect(usbThread,&USB_Thread::updateString11,this,&Widget::updateUsb);
        ui->PBtn_uart->setEnabled(false);
        ui->PBtn_usb->setEnabled(false);
        ui->PBtn_udp->setEnabled(false);
    }
}


/*
    函   数：updateUsb
    描   述：USB自动接收
    输   入：无
    输   出：无
*/
void Widget::updateUsb(QString str1)
{
    if(!str1.isEmpty())
    {
        ui->Txt_Usb->setText(str1);
    }
}


/*
    函   数：on_PBtn_UsbRecv_clicked
    描   述：USB手动接收
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_UsbRecv_clicked()
{
    qDebug("hid read start");
    QString show_text;
    for(int i=0;i<64;i++)
    buf_IN[i]=0x0b;
    start_flag=true;
    QCoreApplication::processEvents();
    hid_read(handle,buf_IN,64);
    for(int i = 0;i < 64;i++)
    {
        qDebug("buf[%d]:0x%02x",i,buf_IN[i]);
        show_text+=tr("%1,").arg(buf_IN[i]);
    }
    ui->Txt_Usb->setText(show_text);
    show_text.clear();
}


/*
    函   数：on_PBtn_UsbSend_clicked
    描   述：USB手动发送
    输   入：无
    输   出：无
*/
void Widget::on_PBtn_UsbSend_clicked()
{
    int res;	                       // 如果返回-1表示发送失败
    unsigned char buf[10];
    buf[0] = 0;	                       // 这就是Report ID
    buf[1] = 0x0a;
    for(int i=0;i<8;i++)
        buf[2+i] = i;
    res = hid_write(handle, buf, 33);  // 此处必须是33或这大于一些的数字
    qDebug()<<res;
}

/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QPushButton *PBtn_uart;
    QPushButton *PBtn_usb;
    QPushButton *PBtn_udp;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelCH_Mode_2;
    QComboBox *CBox_CH_Mode;
    QPushButton *PBtn_Refresh;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QTextEdit *Txt_CHnNoise;
    QSpacerItem *verticalSpacer_15;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelPGA;
    QComboBox *CBox_PGA;
    QLabel *labelCHn;
    QComboBox *CBox_CHn;
    QGridLayout *gridLayout_9;
    QPushButton *PBtn_RmsPP;
    QSpacerItem *verticalSpacer_14;
    QPushButton *PBtn_HighPassFilter;
    QSpacerItem *verticalSpacer_11;
    QPushButton *PBtn_SaveRecvData;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *PBtn_BandPassFilter;
    QPushButton *PBtn_TrapFilter;
    QPushButton *PBtn_LowPassFilter;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *spacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_YRange;
    QLineEdit *Ledit_YRange;
    QLabel *label_Unit;
    QComboBox *CBox_YUnit;
    QGridLayout *gridLayout_3;
    QCustomPlot *customPlot_7;
    QCustomPlot *customPlot_8;
    QCustomPlot *customPlot_3;
    QCustomPlot *customPlot_4;
    QCustomPlot *customPlot_1;
    QCustomPlot *customPlot_5;
    QCustomPlot *customPlot_6;
    QCustomPlot *customPlot_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_7;
    QLabel *label_5;
    QComboBox *CBox_Freq;
    QLabel *label_4;
    QComboBox *CBox_Ampl;
    QLabel *label_3;
    QSlider *Slider_FFTrr;
    QGridLayout *gridLayout_11;
    QPushButton *PBtn_TRCA;
    QPushButton *PBtn_IBLS;
    QPushButton *PBtn_CCA;
    QPushButton *PBtn_FBCCA;
    QCustomPlot *customplot_9;
    QWidget *stimuluselementwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QComboBox *CBox_Baudrate;
    QComboBox *CBox_DataBits;
    QComboBox *CBox_Uart;
    QComboBox *CBox_Parity;
    QSpacerItem *spacer_3;
    QSpacerItem *spacer_9;
    QSpacerItem *spacer_5;
    QLabel *labelStopBits;
    QLabel *labelSerialPort;
    QSpacerItem *spacer_4;
    QPushButton *PBtn_UartSend;
    QComboBox *CBox_StopBits;
    QSpacerItem *spacer_8;
    QLabel *labelDataBits;
    QPushButton *PBtn_UartOpen;
    QSpacerItem *spacer_2;
    QTextEdit *Txt_UartRecv;
    QLabel *labelParity;
    QSpacerItem *spacer_6;
    QLabel *labelBaudrate;
    QWidget *page_4;
    QGridLayout *gridLayout_10;
    QTextEdit *Txt_Usb;
    QPushButton *PBtn_UsbOpen;
    QPushButton *PBtn_UsbRecv;
    QPushButton *PBtn_UsbSend;
    QWidget *page_5;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *PBtn_UDPPing;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_2;
    QPushButton *PBtn_UDPOpen;
    QLineEdit *Ledit_port;
    QTextEdit *Txt_UDP;
    QLineEdit *Ledit_hostIPaddress;
    QLabel *labelSystemName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *CHName1;
    QLineEdit *CHColor1;
    QLabel *CHName2;
    QLineEdit *CHColor2;
    QLabel *CHName3;
    QLineEdit *CHColor3;
    QLabel *CHName6;
    QLineEdit *CHColor6;
    QLabel *CHName7;
    QLineEdit *CHColor7;
    QLabel *CHName4;
    QLineEdit *CHColor4;
    QLabel *CHName5;
    QLineEdit *CHColor5;
    QLabel *CHName8;
    QLineEdit *CHColor8;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1588, 889);
        gridLayout_5 = new QGridLayout(Widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PBtn_uart = new QPushButton(Widget);
        PBtn_uart->setObjectName(QString::fromUtf8("PBtn_uart"));
        PBtn_uart->setMinimumSize(QSize(100, 30));
        PBtn_uart->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        PBtn_uart->setFont(font);

        gridLayout->addWidget(PBtn_uart, 0, 0, 1, 1);

        PBtn_usb = new QPushButton(Widget);
        PBtn_usb->setObjectName(QString::fromUtf8("PBtn_usb"));
        PBtn_usb->setMinimumSize(QSize(100, 30));
        PBtn_usb->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        PBtn_usb->setFont(font1);

        gridLayout->addWidget(PBtn_usb, 0, 1, 1, 1);

        PBtn_udp = new QPushButton(Widget);
        PBtn_udp->setObjectName(QString::fromUtf8("PBtn_udp"));
        PBtn_udp->setMinimumSize(QSize(100, 30));
        PBtn_udp->setMaximumSize(QSize(100, 30));
        PBtn_udp->setFont(font1);

        gridLayout->addWidget(PBtn_udp, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelCH_Mode_2 = new QLabel(Widget);
        labelCH_Mode_2->setObjectName(QString::fromUtf8("labelCH_Mode_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCH_Mode_2->sizePolicy().hasHeightForWidth());
        labelCH_Mode_2->setSizePolicy(sizePolicy);
        labelCH_Mode_2->setMinimumSize(QSize(100, 0));
        labelCH_Mode_2->setMaximumSize(QSize(60, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        labelCH_Mode_2->setFont(font2);

        horizontalLayout_8->addWidget(labelCH_Mode_2);

        CBox_CH_Mode = new QComboBox(Widget);
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->addItem(QString());
        CBox_CH_Mode->setObjectName(QString::fromUtf8("CBox_CH_Mode"));
        sizePolicy.setHeightForWidth(CBox_CH_Mode->sizePolicy().hasHeightForWidth());
        CBox_CH_Mode->setSizePolicy(sizePolicy);
        CBox_CH_Mode->setMinimumSize(QSize(130, 30));
        CBox_CH_Mode->setMaximumSize(QSize(130, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(12);
        CBox_CH_Mode->setFont(font3);

        horizontalLayout_8->addWidget(CBox_CH_Mode);

        PBtn_Refresh = new QPushButton(Widget);
        PBtn_Refresh->setObjectName(QString::fromUtf8("PBtn_Refresh"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PBtn_Refresh->sizePolicy().hasHeightForWidth());
        PBtn_Refresh->setSizePolicy(sizePolicy1);
        PBtn_Refresh->setMinimumSize(QSize(100, 30));
        PBtn_Refresh->setMaximumSize(QSize(100, 30));
        PBtn_Refresh->setFont(font1);

        horizontalLayout_8->addWidget(PBtn_Refresh);


        gridLayout_8->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_9, 5, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_10, 7, 0, 1, 1);

        Txt_CHnNoise = new QTextEdit(Widget);
        Txt_CHnNoise->setObjectName(QString::fromUtf8("Txt_CHnNoise"));
        Txt_CHnNoise->setMinimumSize(QSize(0, 130));
        Txt_CHnNoise->setMaximumSize(QSize(16777215, 130));

        gridLayout_8->addWidget(Txt_CHnNoise, 0, 0, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_15, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelPGA = new QLabel(Widget);
        labelPGA->setObjectName(QString::fromUtf8("labelPGA"));
        sizePolicy.setHeightForWidth(labelPGA->sizePolicy().hasHeightForWidth());
        labelPGA->setSizePolicy(sizePolicy);
        labelPGA->setMinimumSize(QSize(60, 0));
        labelPGA->setMaximumSize(QSize(60, 60));
        labelPGA->setFont(font2);

        horizontalLayout_7->addWidget(labelPGA);

        CBox_PGA = new QComboBox(Widget);
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->addItem(QString());
        CBox_PGA->setObjectName(QString::fromUtf8("CBox_PGA"));
        sizePolicy1.setHeightForWidth(CBox_PGA->sizePolicy().hasHeightForWidth());
        CBox_PGA->setSizePolicy(sizePolicy1);
        CBox_PGA->setMinimumSize(QSize(100, 30));
        CBox_PGA->setMaximumSize(QSize(100, 30));
        CBox_PGA->setFont(font3);

        horizontalLayout_7->addWidget(CBox_PGA);

        labelCHn = new QLabel(Widget);
        labelCHn->setObjectName(QString::fromUtf8("labelCHn"));
        sizePolicy.setHeightForWidth(labelCHn->sizePolicy().hasHeightForWidth());
        labelCHn->setSizePolicy(sizePolicy);
        labelCHn->setMinimumSize(QSize(60, 0));
        labelCHn->setMaximumSize(QSize(60, 60));
        labelCHn->setFont(font2);

        horizontalLayout_7->addWidget(labelCHn);

        CBox_CHn = new QComboBox(Widget);
        CBox_CHn->addItem(QString());
        CBox_CHn->addItem(QString());
        CBox_CHn->addItem(QString());
        CBox_CHn->setObjectName(QString::fromUtf8("CBox_CHn"));
        sizePolicy1.setHeightForWidth(CBox_CHn->sizePolicy().hasHeightForWidth());
        CBox_CHn->setSizePolicy(sizePolicy1);
        CBox_CHn->setMinimumSize(QSize(100, 30));
        CBox_CHn->setMaximumSize(QSize(100, 30));
        CBox_CHn->setFont(font3);

        horizontalLayout_7->addWidget(CBox_CHn);


        gridLayout_8->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        PBtn_RmsPP = new QPushButton(Widget);
        PBtn_RmsPP->setObjectName(QString::fromUtf8("PBtn_RmsPP"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PBtn_RmsPP->sizePolicy().hasHeightForWidth());
        PBtn_RmsPP->setSizePolicy(sizePolicy2);
        PBtn_RmsPP->setMinimumSize(QSize(150, 30));
        PBtn_RmsPP->setMaximumSize(QSize(150, 30));
        PBtn_RmsPP->setFont(font1);

        gridLayout_9->addWidget(PBtn_RmsPP, 4, 0, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_14, 3, 0, 1, 1);

        PBtn_HighPassFilter = new QPushButton(Widget);
        PBtn_HighPassFilter->setObjectName(QString::fromUtf8("PBtn_HighPassFilter"));
        sizePolicy2.setHeightForWidth(PBtn_HighPassFilter->sizePolicy().hasHeightForWidth());
        PBtn_HighPassFilter->setSizePolicy(sizePolicy2);
        PBtn_HighPassFilter->setMinimumSize(QSize(150, 30));
        PBtn_HighPassFilter->setMaximumSize(QSize(150, 30));
        PBtn_HighPassFilter->setFont(font1);

        gridLayout_9->addWidget(PBtn_HighPassFilter, 0, 0, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_11, 1, 2, 1, 1);

        PBtn_SaveRecvData = new QPushButton(Widget);
        PBtn_SaveRecvData->setObjectName(QString::fromUtf8("PBtn_SaveRecvData"));
        sizePolicy.setHeightForWidth(PBtn_SaveRecvData->sizePolicy().hasHeightForWidth());
        PBtn_SaveRecvData->setSizePolicy(sizePolicy);
        PBtn_SaveRecvData->setMinimumSize(QSize(150, 30));
        PBtn_SaveRecvData->setMaximumSize(QSize(150, 30));
        PBtn_SaveRecvData->setFont(font1);

        gridLayout_9->addWidget(PBtn_SaveRecvData, 4, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        PBtn_BandPassFilter = new QPushButton(Widget);
        PBtn_BandPassFilter->setObjectName(QString::fromUtf8("PBtn_BandPassFilter"));
        sizePolicy2.setHeightForWidth(PBtn_BandPassFilter->sizePolicy().hasHeightForWidth());
        PBtn_BandPassFilter->setSizePolicy(sizePolicy2);
        PBtn_BandPassFilter->setMinimumSize(QSize(150, 30));
        PBtn_BandPassFilter->setMaximumSize(QSize(150, 30));
        PBtn_BandPassFilter->setFont(font1);

        gridLayout_9->addWidget(PBtn_BandPassFilter, 2, 0, 1, 1);

        PBtn_TrapFilter = new QPushButton(Widget);
        PBtn_TrapFilter->setObjectName(QString::fromUtf8("PBtn_TrapFilter"));
        sizePolicy2.setHeightForWidth(PBtn_TrapFilter->sizePolicy().hasHeightForWidth());
        PBtn_TrapFilter->setSizePolicy(sizePolicy2);
        PBtn_TrapFilter->setMinimumSize(QSize(150, 30));
        PBtn_TrapFilter->setMaximumSize(QSize(150, 30));
        PBtn_TrapFilter->setFont(font1);

        gridLayout_9->addWidget(PBtn_TrapFilter, 0, 2, 1, 1);

        PBtn_LowPassFilter = new QPushButton(Widget);
        PBtn_LowPassFilter->setObjectName(QString::fromUtf8("PBtn_LowPassFilter"));
        sizePolicy2.setHeightForWidth(PBtn_LowPassFilter->sizePolicy().hasHeightForWidth());
        PBtn_LowPassFilter->setSizePolicy(sizePolicy2);
        PBtn_LowPassFilter->setMinimumSize(QSize(150, 30));
        PBtn_LowPassFilter->setMaximumSize(QSize(150, 30));
        PBtn_LowPassFilter->setFont(font1);

        gridLayout_9->addWidget(PBtn_LowPassFilter, 2, 2, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_12, 1, 0, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_13, 3, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_9, 8, 0, 1, 1);

        spacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(spacer, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_YRange = new QLabel(Widget);
        label_YRange->setObjectName(QString::fromUtf8("label_YRange"));
        label_YRange->setMinimumSize(QSize(60, 30));
        label_YRange->setMaximumSize(QSize(60, 30));
        label_YRange->setFont(font2);

        horizontalLayout->addWidget(label_YRange);

        Ledit_YRange = new QLineEdit(Widget);
        Ledit_YRange->setObjectName(QString::fromUtf8("Ledit_YRange"));
        Ledit_YRange->setMinimumSize(QSize(100, 30));
        Ledit_YRange->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(Ledit_YRange);

        label_Unit = new QLabel(Widget);
        label_Unit->setObjectName(QString::fromUtf8("label_Unit"));
        label_Unit->setMinimumSize(QSize(60, 30));
        label_Unit->setMaximumSize(QSize(60, 30));
        label_Unit->setFont(font2);

        horizontalLayout->addWidget(label_Unit);

        CBox_YUnit = new QComboBox(Widget);
        CBox_YUnit->addItem(QString());
        CBox_YUnit->addItem(QString());
        CBox_YUnit->setObjectName(QString::fromUtf8("CBox_YUnit"));
        CBox_YUnit->setMinimumSize(QSize(100, 30));
        CBox_YUnit->setMaximumSize(QSize(100, 30));
        CBox_YUnit->setFont(font3);

        horizontalLayout->addWidget(CBox_YUnit);


        gridLayout_8->addLayout(horizontalLayout, 4, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_8, 3, 0, 2, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        customPlot_7 = new QCustomPlot(Widget);
        customPlot_7->setObjectName(QString::fromUtf8("customPlot_7"));
        customPlot_7->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_7, 6, 0, 1, 1);

        customPlot_8 = new QCustomPlot(Widget);
        customPlot_8->setObjectName(QString::fromUtf8("customPlot_8"));
        customPlot_8->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_8, 7, 0, 1, 1);

        customPlot_3 = new QCustomPlot(Widget);
        customPlot_3->setObjectName(QString::fromUtf8("customPlot_3"));
        customPlot_3->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_3, 2, 0, 1, 1);

        customPlot_4 = new QCustomPlot(Widget);
        customPlot_4->setObjectName(QString::fromUtf8("customPlot_4"));
        customPlot_4->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_4, 3, 0, 1, 1);

        customPlot_1 = new QCustomPlot(Widget);
        customPlot_1->setObjectName(QString::fromUtf8("customPlot_1"));
        customPlot_1->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_1, 0, 0, 1, 1);

        customPlot_5 = new QCustomPlot(Widget);
        customPlot_5->setObjectName(QString::fromUtf8("customPlot_5"));
        customPlot_5->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_5, 4, 0, 1, 1);

        customPlot_6 = new QCustomPlot(Widget);
        customPlot_6->setObjectName(QString::fromUtf8("customPlot_6"));
        customPlot_6->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_6, 5, 0, 1, 1);

        customPlot_2 = new QCustomPlot(Widget);
        customPlot_2->setObjectName(QString::fromUtf8("customPlot_2"));
        customPlot_2->setMinimumSize(QSize(600, 0));

        gridLayout_3->addWidget(customPlot_2, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 1, 4, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(80, 30));
        label_5->setFont(font1);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        CBox_Freq = new QComboBox(Widget);
        CBox_Freq->addItem(QString());
        CBox_Freq->addItem(QString());
        CBox_Freq->addItem(QString());
        CBox_Freq->addItem(QString());
        CBox_Freq->addItem(QString());
        CBox_Freq->setObjectName(QString::fromUtf8("CBox_Freq"));
        CBox_Freq->setMinimumSize(QSize(100, 30));
        CBox_Freq->setMaximumSize(QSize(100, 30));
        CBox_Freq->setFont(font3);

        gridLayout_7->addWidget(CBox_Freq, 0, 1, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(80, 30));
        label_4->setFont(font1);

        gridLayout_7->addWidget(label_4, 0, 2, 1, 1);

        CBox_Ampl = new QComboBox(Widget);
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->addItem(QString());
        CBox_Ampl->setObjectName(QString::fromUtf8("CBox_Ampl"));
        CBox_Ampl->setMinimumSize(QSize(100, 30));
        CBox_Ampl->setMaximumSize(QSize(100, 30));
        CBox_Ampl->setFont(font3);

        gridLayout_7->addWidget(CBox_Ampl, 0, 3, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(80, 30));
        label_3->setSizeIncrement(QSize(0, 0));
        label_3->setFont(font1);

        gridLayout_7->addWidget(label_3, 0, 4, 1, 1);

        Slider_FFTrr = new QSlider(Widget);
        Slider_FFTrr->setObjectName(QString::fromUtf8("Slider_FFTrr"));
        Slider_FFTrr->setMinimumSize(QSize(0, 30));
        Slider_FFTrr->setMaximumSize(QSize(100, 30));
        Slider_FFTrr->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(Slider_FFTrr, 0, 5, 1, 1);


        gridLayout_4->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        PBtn_TRCA = new QPushButton(Widget);
        PBtn_TRCA->setObjectName(QString::fromUtf8("PBtn_TRCA"));
        PBtn_TRCA->setMinimumSize(QSize(100, 30));
        PBtn_TRCA->setMaximumSize(QSize(100, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(14);
        PBtn_TRCA->setFont(font4);

        gridLayout_11->addWidget(PBtn_TRCA, 0, 1, 1, 1);

        PBtn_IBLS = new QPushButton(Widget);
        PBtn_IBLS->setObjectName(QString::fromUtf8("PBtn_IBLS"));
        PBtn_IBLS->setMinimumSize(QSize(100, 30));
        PBtn_IBLS->setMaximumSize(QSize(100, 30));
        PBtn_IBLS->setFont(font4);

        gridLayout_11->addWidget(PBtn_IBLS, 0, 3, 1, 1);

        PBtn_CCA = new QPushButton(Widget);
        PBtn_CCA->setObjectName(QString::fromUtf8("PBtn_CCA"));
        PBtn_CCA->setMinimumSize(QSize(100, 30));
        PBtn_CCA->setMaximumSize(QSize(100, 30));
        PBtn_CCA->setFont(font4);

        gridLayout_11->addWidget(PBtn_CCA, 0, 0, 1, 1);

        PBtn_FBCCA = new QPushButton(Widget);
        PBtn_FBCCA->setObjectName(QString::fromUtf8("PBtn_FBCCA"));
        PBtn_FBCCA->setMinimumSize(QSize(100, 30));
        PBtn_FBCCA->setMaximumSize(QSize(100, 30));
        PBtn_FBCCA->setFont(font4);

        gridLayout_11->addWidget(PBtn_FBCCA, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_11, 3, 0, 1, 1);

        customplot_9 = new QCustomPlot(Widget);
        customplot_9->setObjectName(QString::fromUtf8("customplot_9"));
        customplot_9->setMinimumSize(QSize(600, 300));
        customplot_9->setMaximumSize(QSize(600, 16777215));

        gridLayout_4->addWidget(customplot_9, 1, 0, 1, 1);

        stimuluselementwidget = new QWidget(Widget);
        stimuluselementwidget->setObjectName(QString::fromUtf8("stimuluselementwidget"));

        gridLayout_4->addWidget(stimuluselementwidget, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 2, 4, 1);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        CBox_Baudrate = new QComboBox(page_3);
        CBox_Baudrate->addItem(QString());
        CBox_Baudrate->addItem(QString());
        CBox_Baudrate->addItem(QString());
        CBox_Baudrate->addItem(QString());
        CBox_Baudrate->setObjectName(QString::fromUtf8("CBox_Baudrate"));
        sizePolicy1.setHeightForWidth(CBox_Baudrate->sizePolicy().hasHeightForWidth());
        CBox_Baudrate->setSizePolicy(sizePolicy1);
        CBox_Baudrate->setMinimumSize(QSize(130, 30));
        CBox_Baudrate->setMaximumSize(QSize(130, 30));
        CBox_Baudrate->setFont(font3);

        gridLayout_2->addWidget(CBox_Baudrate, 2, 1, 1, 1);

        CBox_DataBits = new QComboBox(page_3);
        CBox_DataBits->addItem(QString());
        CBox_DataBits->addItem(QString());
        CBox_DataBits->addItem(QString());
        CBox_DataBits->addItem(QString());
        CBox_DataBits->setObjectName(QString::fromUtf8("CBox_DataBits"));
        sizePolicy1.setHeightForWidth(CBox_DataBits->sizePolicy().hasHeightForWidth());
        CBox_DataBits->setSizePolicy(sizePolicy1);
        CBox_DataBits->setMinimumSize(QSize(130, 30));
        CBox_DataBits->setMaximumSize(QSize(130, 30));
        CBox_DataBits->setFont(font3);

        gridLayout_2->addWidget(CBox_DataBits, 6, 1, 1, 1);

        CBox_Uart = new QComboBox(page_3);
        CBox_Uart->setObjectName(QString::fromUtf8("CBox_Uart"));
        sizePolicy1.setHeightForWidth(CBox_Uart->sizePolicy().hasHeightForWidth());
        CBox_Uart->setSizePolicy(sizePolicy1);
        CBox_Uart->setMinimumSize(QSize(130, 30));
        CBox_Uart->setMaximumSize(QSize(130, 30));
        CBox_Uart->setFont(font3);

        gridLayout_2->addWidget(CBox_Uart, 0, 1, 1, 1);

        CBox_Parity = new QComboBox(page_3);
        CBox_Parity->addItem(QString());
        CBox_Parity->addItem(QString());
        CBox_Parity->addItem(QString());
        CBox_Parity->addItem(QString());
        CBox_Parity->setObjectName(QString::fromUtf8("CBox_Parity"));
        sizePolicy1.setHeightForWidth(CBox_Parity->sizePolicy().hasHeightForWidth());
        CBox_Parity->setSizePolicy(sizePolicy1);
        CBox_Parity->setMinimumSize(QSize(130, 30));
        CBox_Parity->setMaximumSize(QSize(130, 30));
        CBox_Parity->setFont(font3);

        gridLayout_2->addWidget(CBox_Parity, 4, 1, 1, 1);

        spacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_3, 3, 0, 1, 1);

        spacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_9, 13, 0, 1, 1);

        spacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_5, 7, 0, 1, 1);

        labelStopBits = new QLabel(page_3);
        labelStopBits->setObjectName(QString::fromUtf8("labelStopBits"));
        sizePolicy1.setHeightForWidth(labelStopBits->sizePolicy().hasHeightForWidth());
        labelStopBits->setSizePolicy(sizePolicy1);
        labelStopBits->setMaximumSize(QSize(100, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setWeight(50);
        labelStopBits->setFont(font5);
        labelStopBits->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelStopBits, 8, 0, 1, 1);

        labelSerialPort = new QLabel(page_3);
        labelSerialPort->setObjectName(QString::fromUtf8("labelSerialPort"));
        sizePolicy1.setHeightForWidth(labelSerialPort->sizePolicy().hasHeightForWidth());
        labelSerialPort->setSizePolicy(sizePolicy1);
        labelSerialPort->setMaximumSize(QSize(100, 30));
        labelSerialPort->setFont(font5);
        labelSerialPort->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelSerialPort, 0, 0, 1, 1);

        spacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_4, 5, 0, 1, 1);

        PBtn_UartSend = new QPushButton(page_3);
        PBtn_UartSend->setObjectName(QString::fromUtf8("PBtn_UartSend"));
        sizePolicy1.setHeightForWidth(PBtn_UartSend->sizePolicy().hasHeightForWidth());
        PBtn_UartSend->setSizePolicy(sizePolicy1);
        PBtn_UartSend->setMinimumSize(QSize(100, 30));
        PBtn_UartSend->setMaximumSize(QSize(100, 30));
        PBtn_UartSend->setFont(font1);

        gridLayout_2->addWidget(PBtn_UartSend, 12, 0, 1, 1);

        CBox_StopBits = new QComboBox(page_3);
        CBox_StopBits->addItem(QString());
        CBox_StopBits->addItem(QString());
        CBox_StopBits->addItem(QString());
        CBox_StopBits->setObjectName(QString::fromUtf8("CBox_StopBits"));
        sizePolicy1.setHeightForWidth(CBox_StopBits->sizePolicy().hasHeightForWidth());
        CBox_StopBits->setSizePolicy(sizePolicy1);
        CBox_StopBits->setMinimumSize(QSize(130, 30));
        CBox_StopBits->setMaximumSize(QSize(130, 30));
        CBox_StopBits->setFont(font3);

        gridLayout_2->addWidget(CBox_StopBits, 8, 1, 1, 1);

        spacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_8, 11, 0, 1, 1);

        labelDataBits = new QLabel(page_3);
        labelDataBits->setObjectName(QString::fromUtf8("labelDataBits"));
        sizePolicy1.setHeightForWidth(labelDataBits->sizePolicy().hasHeightForWidth());
        labelDataBits->setSizePolicy(sizePolicy1);
        labelDataBits->setMaximumSize(QSize(100, 30));
        labelDataBits->setFont(font5);
        labelDataBits->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelDataBits, 6, 0, 1, 1);

        PBtn_UartOpen = new QPushButton(page_3);
        PBtn_UartOpen->setObjectName(QString::fromUtf8("PBtn_UartOpen"));
        sizePolicy1.setHeightForWidth(PBtn_UartOpen->sizePolicy().hasHeightForWidth());
        PBtn_UartOpen->setSizePolicy(sizePolicy1);
        PBtn_UartOpen->setMinimumSize(QSize(100, 30));
        PBtn_UartOpen->setMaximumSize(QSize(100, 30));
        PBtn_UartOpen->setFont(font1);

        gridLayout_2->addWidget(PBtn_UartOpen, 12, 1, 1, 1);

        spacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_2, 1, 0, 1, 1);

        Txt_UartRecv = new QTextEdit(page_3);
        Txt_UartRecv->setObjectName(QString::fromUtf8("Txt_UartRecv"));
        Txt_UartRecv->setFont(font3);

        gridLayout_2->addWidget(Txt_UartRecv, 10, 0, 1, 2);

        labelParity = new QLabel(page_3);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        sizePolicy1.setHeightForWidth(labelParity->sizePolicy().hasHeightForWidth());
        labelParity->setSizePolicy(sizePolicy1);
        labelParity->setMaximumSize(QSize(100, 30));
        labelParity->setFont(font5);
        labelParity->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelParity, 4, 0, 1, 1);

        spacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer_6, 9, 0, 1, 1);

        labelBaudrate = new QLabel(page_3);
        labelBaudrate->setObjectName(QString::fromUtf8("labelBaudrate"));
        sizePolicy1.setHeightForWidth(labelBaudrate->sizePolicy().hasHeightForWidth());
        labelBaudrate->setSizePolicy(sizePolicy1);
        labelBaudrate->setMaximumSize(QSize(100, 30));
        labelBaudrate->setFont(font5);
        labelBaudrate->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelBaudrate, 2, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_10 = new QGridLayout(page_4);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        Txt_Usb = new QTextEdit(page_4);
        Txt_Usb->setObjectName(QString::fromUtf8("Txt_Usb"));
        Txt_Usb->setMinimumSize(QSize(0, 0));
        Txt_Usb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(Txt_Usb, 0, 0, 1, 3);

        PBtn_UsbOpen = new QPushButton(page_4);
        PBtn_UsbOpen->setObjectName(QString::fromUtf8("PBtn_UsbOpen"));
        PBtn_UsbOpen->setMinimumSize(QSize(100, 30));
        PBtn_UsbOpen->setMaximumSize(QSize(100, 30));
        PBtn_UsbOpen->setSizeIncrement(QSize(0, 2));
        PBtn_UsbOpen->setFont(font1);

        gridLayout_10->addWidget(PBtn_UsbOpen, 1, 0, 1, 1);

        PBtn_UsbRecv = new QPushButton(page_4);
        PBtn_UsbRecv->setObjectName(QString::fromUtf8("PBtn_UsbRecv"));
        PBtn_UsbRecv->setMinimumSize(QSize(100, 30));
        PBtn_UsbRecv->setMaximumSize(QSize(100, 30));
        PBtn_UsbRecv->setFont(font1);

        gridLayout_10->addWidget(PBtn_UsbRecv, 1, 1, 1, 1);

        PBtn_UsbSend = new QPushButton(page_4);
        PBtn_UsbSend->setObjectName(QString::fromUtf8("PBtn_UsbSend"));
        PBtn_UsbSend->setMinimumSize(QSize(100, 30));
        PBtn_UsbSend->setMaximumSize(QSize(100, 30));
        PBtn_UsbSend->setFont(font1);

        gridLayout_10->addWidget(PBtn_UsbSend, 1, 2, 1, 1);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_6 = new QGridLayout(page_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_12, 3, 0, 1, 1);

        PBtn_UDPPing = new QPushButton(page_5);
        PBtn_UDPPing->setObjectName(QString::fromUtf8("PBtn_UDPPing"));
        PBtn_UDPPing->setMinimumSize(QSize(100, 30));
        PBtn_UDPPing->setMaximumSize(QSize(100, 30));
        PBtn_UDPPing->setFont(font1);

        gridLayout_6->addWidget(PBtn_UDPPing, 3, 1, 1, 2);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_13, 3, 4, 1, 1);

        label = new QLabel(page_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_6->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_15, 0, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        label_2 = new QLabel(page_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_6->addWidget(label_2, 2, 1, 1, 1);

        PBtn_UDPOpen = new QPushButton(page_5);
        PBtn_UDPOpen->setObjectName(QString::fromUtf8("PBtn_UDPOpen"));
        PBtn_UDPOpen->setMinimumSize(QSize(100, 30));
        PBtn_UDPOpen->setMaximumSize(QSize(100, 30));
        PBtn_UDPOpen->setFont(font1);

        gridLayout_6->addWidget(PBtn_UDPOpen, 3, 3, 1, 1);

        Ledit_port = new QLineEdit(page_5);
        Ledit_port->setObjectName(QString::fromUtf8("Ledit_port"));
        Ledit_port->setMinimumSize(QSize(0, 30));
        Ledit_port->setMaximumSize(QSize(16777215, 30));

        gridLayout_6->addWidget(Ledit_port, 2, 2, 1, 2);

        Txt_UDP = new QTextEdit(page_5);
        Txt_UDP->setObjectName(QString::fromUtf8("Txt_UDP"));

        gridLayout_6->addWidget(Txt_UDP, 0, 1, 1, 3);

        Ledit_hostIPaddress = new QLineEdit(page_5);
        Ledit_hostIPaddress->setObjectName(QString::fromUtf8("Ledit_hostIPaddress"));
        Ledit_hostIPaddress->setMinimumSize(QSize(0, 30));
        Ledit_hostIPaddress->setMaximumSize(QSize(16777215, 30));

        gridLayout_6->addWidget(Ledit_hostIPaddress, 1, 2, 1, 2);

        stackedWidget->addWidget(page_5);

        gridLayout_5->addWidget(stackedWidget, 2, 0, 1, 1);

        labelSystemName = new QLabel(Widget);
        labelSystemName->setObjectName(QString::fromUtf8("labelSystemName"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelSystemName->sizePolicy().hasHeightForWidth());
        labelSystemName->setSizePolicy(sizePolicy3);
        labelSystemName->setMaximumSize(QSize(240, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Times New Roman"));
        font6.setPointSize(19);
        font6.setBold(true);
        font6.setWeight(75);
        labelSystemName->setFont(font6);

        gridLayout_5->addWidget(labelSystemName, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        CHName1 = new QLabel(Widget);
        CHName1->setObjectName(QString::fromUtf8("CHName1"));
        sizePolicy3.setHeightForWidth(CHName1->sizePolicy().hasHeightForWidth());
        CHName1->setSizePolicy(sizePolicy3);
        CHName1->setMaximumSize(QSize(220, 30));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Times New Roman"));
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setWeight(75);
        CHName1->setFont(font7);

        horizontalLayout_6->addWidget(CHName1);

        CHColor1 = new QLineEdit(Widget);
        CHColor1->setObjectName(QString::fromUtf8("CHColor1"));
        CHColor1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(CHColor1);

        CHName2 = new QLabel(Widget);
        CHName2->setObjectName(QString::fromUtf8("CHName2"));
        sizePolicy3.setHeightForWidth(CHName2->sizePolicy().hasHeightForWidth());
        CHName2->setSizePolicy(sizePolicy3);
        CHName2->setMaximumSize(QSize(220, 30));
        CHName2->setFont(font7);

        horizontalLayout_6->addWidget(CHName2);

        CHColor2 = new QLineEdit(Widget);
        CHColor2->setObjectName(QString::fromUtf8("CHColor2"));
        CHColor2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 0, 0);"));

        horizontalLayout_6->addWidget(CHColor2);

        CHName3 = new QLabel(Widget);
        CHName3->setObjectName(QString::fromUtf8("CHName3"));
        sizePolicy3.setHeightForWidth(CHName3->sizePolicy().hasHeightForWidth());
        CHName3->setSizePolicy(sizePolicy3);
        CHName3->setMaximumSize(QSize(220, 30));
        CHName3->setFont(font7);

        horizontalLayout_6->addWidget(CHName3);

        CHColor3 = new QLineEdit(Widget);
        CHColor3->setObjectName(QString::fromUtf8("CHColor3"));
        CHColor3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 0);"));

        horizontalLayout_6->addWidget(CHColor3);

        CHName6 = new QLabel(Widget);
        CHName6->setObjectName(QString::fromUtf8("CHName6"));
        sizePolicy3.setHeightForWidth(CHName6->sizePolicy().hasHeightForWidth());
        CHName6->setSizePolicy(sizePolicy3);
        CHName6->setMaximumSize(QSize(220, 30));
        CHName6->setFont(font7);

        horizontalLayout_6->addWidget(CHName6);

        CHColor6 = new QLineEdit(Widget);
        CHColor6->setObjectName(QString::fromUtf8("CHColor6"));
        CHColor6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 128);"));

        horizontalLayout_6->addWidget(CHColor6);

        CHName7 = new QLabel(Widget);
        CHName7->setObjectName(QString::fromUtf8("CHName7"));
        sizePolicy3.setHeightForWidth(CHName7->sizePolicy().hasHeightForWidth());
        CHName7->setSizePolicy(sizePolicy3);
        CHName7->setMaximumSize(QSize(220, 30));
        CHName7->setFont(font7);

        horizontalLayout_6->addWidget(CHName7);

        CHColor7 = new QLineEdit(Widget);
        CHColor7->setObjectName(QString::fromUtf8("CHColor7"));
        CHColor7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 128);"));

        horizontalLayout_6->addWidget(CHColor7);

        CHName4 = new QLabel(Widget);
        CHName4->setObjectName(QString::fromUtf8("CHName4"));
        sizePolicy3.setHeightForWidth(CHName4->sizePolicy().hasHeightForWidth());
        CHName4->setSizePolicy(sizePolicy3);
        CHName4->setMaximumSize(QSize(220, 30));
        CHName4->setFont(font7);

        horizontalLayout_6->addWidget(CHName4);

        CHColor4 = new QLineEdit(Widget);
        CHColor4->setObjectName(QString::fromUtf8("CHColor4"));
        CHColor4->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 0, 128);"));

        horizontalLayout_6->addWidget(CHColor4);

        CHName5 = new QLabel(Widget);
        CHName5->setObjectName(QString::fromUtf8("CHName5"));
        sizePolicy3.setHeightForWidth(CHName5->sizePolicy().hasHeightForWidth());
        CHName5->setSizePolicy(sizePolicy3);
        CHName5->setMaximumSize(QSize(220, 30));
        CHName5->setFont(font7);

        horizontalLayout_6->addWidget(CHName5);

        CHColor5 = new QLineEdit(Widget);
        CHColor5->setObjectName(QString::fromUtf8("CHColor5"));
        CHColor5->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 0);"));

        horizontalLayout_6->addWidget(CHColor5);

        CHName8 = new QLabel(Widget);
        CHName8->setObjectName(QString::fromUtf8("CHName8"));
        sizePolicy3.setHeightForWidth(CHName8->sizePolicy().hasHeightForWidth());
        CHName8->setSizePolicy(sizePolicy3);
        CHName8->setMaximumSize(QSize(220, 30));
        CHName8->setFont(font7);

        horizontalLayout_6->addWidget(CHName8);

        CHColor8 = new QLineEdit(Widget);
        CHColor8->setObjectName(QString::fromUtf8("CHColor8"));
        CHColor8->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);"));

        horizontalLayout_6->addWidget(CHColor8);


        gridLayout_5->addLayout(horizontalLayout_6, 4, 1, 1, 2);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        PBtn_uart->setText(QApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        PBtn_usb->setText(QApplication::translate("Widget", "USB", nullptr));
        PBtn_udp->setText(QApplication::translate("Widget", "\346\227\240\347\272\277", nullptr));
        labelCH_Mode_2->setText(QApplication::translate("Widget", "CH_Mode:", nullptr));
        CBox_CH_Mode->setItemText(0, QApplication::translate("Widget", "Normal_Input", nullptr));
        CBox_CH_Mode->setItemText(1, QApplication::translate("Widget", "Input_Short", nullptr));
        CBox_CH_Mode->setItemText(2, QApplication::translate("Widget", "BIAS_Measure", nullptr));
        CBox_CH_Mode->setItemText(3, QApplication::translate("Widget", "Supply_Measure", nullptr));
        CBox_CH_Mode->setItemText(4, QApplication::translate("Widget", "Temp_Sense", nullptr));
        CBox_CH_Mode->setItemText(5, QApplication::translate("Widget", "Test_Signal", nullptr));
        CBox_CH_Mode->setItemText(6, QApplication::translate("Widget", "BIAS_DRP", nullptr));
        CBox_CH_Mode->setItemText(7, QApplication::translate("Widget", "BIAS_DRN", nullptr));

        PBtn_Refresh->setText(QApplication::translate("Widget", "\345\210\267\346\226\260", nullptr));
        labelPGA->setText(QApplication::translate("Widget", "PGA:", nullptr));
        CBox_PGA->setItemText(0, QApplication::translate("Widget", "1", nullptr));
        CBox_PGA->setItemText(1, QApplication::translate("Widget", "2", nullptr));
        CBox_PGA->setItemText(2, QApplication::translate("Widget", "4", nullptr));
        CBox_PGA->setItemText(3, QApplication::translate("Widget", "6", nullptr));
        CBox_PGA->setItemText(4, QApplication::translate("Widget", "8", nullptr));
        CBox_PGA->setItemText(5, QApplication::translate("Widget", "12", nullptr));
        CBox_PGA->setItemText(6, QApplication::translate("Widget", "24", nullptr));

        labelCHn->setText(QApplication::translate("Widget", "CHn:", nullptr));
        CBox_CHn->setItemText(0, QApplication::translate("Widget", "8", nullptr));
        CBox_CHn->setItemText(1, QApplication::translate("Widget", "6", nullptr));
        CBox_CHn->setItemText(2, QApplication::translate("Widget", "4", nullptr));

        PBtn_RmsPP->setText(QApplication::translate("Widget", "RMS\345\222\214PP\346\265\213\351\207\217", nullptr));
        PBtn_HighPassFilter->setText(QApplication::translate("Widget", "\351\253\230\351\200\232\346\273\244\346\263\242", nullptr));
        PBtn_SaveRecvData->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        PBtn_BandPassFilter->setText(QApplication::translate("Widget", "\345\270\246\351\200\232\346\273\244\346\263\242", nullptr));
        PBtn_TrapFilter->setText(QApplication::translate("Widget", "\351\231\267\346\263\242\346\273\244\346\263\242", nullptr));
        PBtn_LowPassFilter->setText(QApplication::translate("Widget", "\344\275\216\351\200\232\346\273\244\346\263\242", nullptr));
        label_YRange->setText(QApplication::translate("Widget", "Y_range:", nullptr));
        Ledit_YRange->setText(QApplication::translate("Widget", "1", nullptr));
        label_Unit->setText(QApplication::translate("Widget", "Unit:", nullptr));
        CBox_YUnit->setItemText(0, QApplication::translate("Widget", "mV", nullptr));
        CBox_YUnit->setItemText(1, QApplication::translate("Widget", "uV", nullptr));

        label_5->setText(QApplication::translate("Widget", "\351\242\221\347\216\207", nullptr));
        CBox_Freq->setItemText(0, QApplication::translate("Widget", "60 Hz", nullptr));
        CBox_Freq->setItemText(1, QApplication::translate("Widget", "70 Hz", nullptr));
        CBox_Freq->setItemText(2, QApplication::translate("Widget", "80 Hz", nullptr));
        CBox_Freq->setItemText(3, QApplication::translate("Widget", "90 Hz", nullptr));
        CBox_Freq->setItemText(4, QApplication::translate("Widget", "100 Hz", nullptr));

        label_4->setText(QApplication::translate("Widget", "\345\271\205\345\200\274", nullptr));
        CBox_Ampl->setItemText(0, QApplication::translate("Widget", "1 V", nullptr));
        CBox_Ampl->setItemText(1, QApplication::translate("Widget", "500 mV", nullptr));
        CBox_Ampl->setItemText(2, QApplication::translate("Widget", "100 mV", nullptr));
        CBox_Ampl->setItemText(3, QApplication::translate("Widget", "50 mV", nullptr));
        CBox_Ampl->setItemText(4, QApplication::translate("Widget", "10 mV", nullptr));
        CBox_Ampl->setItemText(5, QApplication::translate("Widget", "5 mV", nullptr));
        CBox_Ampl->setItemText(6, QApplication::translate("Widget", "1 mV", nullptr));
        CBox_Ampl->setItemText(7, QApplication::translate("Widget", "500 uV", nullptr));
        CBox_Ampl->setItemText(8, QApplication::translate("Widget", "100 uV", nullptr));

        label_3->setText(QApplication::translate("Widget", "\351\200\237\347\216\207", nullptr));
        PBtn_TRCA->setText(QApplication::translate("Widget", "TRCA", nullptr));
        PBtn_IBLS->setText(QApplication::translate("Widget", "IBLS", nullptr));
        PBtn_CCA->setText(QApplication::translate("Widget", "CCA", nullptr));
        PBtn_FBCCA->setText(QApplication::translate("Widget", "FBCCA", nullptr));
        CBox_Baudrate->setItemText(0, QApplication::translate("Widget", "540000", nullptr));
        CBox_Baudrate->setItemText(1, QApplication::translate("Widget", "9600", nullptr));
        CBox_Baudrate->setItemText(2, QApplication::translate("Widget", "19200", nullptr));
        CBox_Baudrate->setItemText(3, QApplication::translate("Widget", "115200", nullptr));

        CBox_DataBits->setItemText(0, QApplication::translate("Widget", "8", nullptr));
        CBox_DataBits->setItemText(1, QApplication::translate("Widget", "5", nullptr));
        CBox_DataBits->setItemText(2, QApplication::translate("Widget", "6", nullptr));
        CBox_DataBits->setItemText(3, QApplication::translate("Widget", "7", nullptr));

        CBox_Parity->setItemText(0, QApplication::translate("Widget", "NONE", nullptr));
        CBox_Parity->setItemText(1, QApplication::translate("Widget", "ODD", nullptr));
        CBox_Parity->setItemText(2, QApplication::translate("Widget", "EVEN", nullptr));
        CBox_Parity->setItemText(3, QApplication::translate("Widget", "MARK", nullptr));

        labelStopBits->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        labelSerialPort->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        PBtn_UartSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        CBox_StopBits->setItemText(0, QApplication::translate("Widget", "1", nullptr));
        CBox_StopBits->setItemText(1, QApplication::translate("Widget", "1.5", nullptr));
        CBox_StopBits->setItemText(2, QApplication::translate("Widget", "2", nullptr));

        labelDataBits->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        PBtn_UartOpen->setText(QApplication::translate("Widget", "open", nullptr));
        labelParity->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        labelBaudrate->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        PBtn_UsbOpen->setText(QApplication::translate("Widget", "open", nullptr));
        PBtn_UsbRecv->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\346\216\245\346\224\266", nullptr));
        PBtn_UsbSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        PBtn_UDPPing->setText(QApplication::translate("Widget", "Ping", nullptr));
        label->setText(QApplication::translate("Widget", "\344\270\273\346\234\272IP\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", nullptr));
        PBtn_UDPOpen->setText(QApplication::translate("Widget", "open", nullptr));
        Ledit_port->setText(QApplication::translate("Widget", "6060", nullptr));
        Ledit_hostIPaddress->setText(QString());
        labelSystemName->setText(QApplication::translate("Widget", "EEG Monitor", nullptr));
        CHName1->setText(QApplication::translate("Widget", "\351\200\232\351\201\2231", nullptr));
        CHName2->setText(QApplication::translate("Widget", "\351\200\232\351\201\2232", nullptr));
        CHName3->setText(QApplication::translate("Widget", "\351\200\232\351\201\2233", nullptr));
        CHName6->setText(QApplication::translate("Widget", "\351\200\232\351\201\2234", nullptr));
        CHName7->setText(QApplication::translate("Widget", "\351\200\232\351\201\2235", nullptr));
        CHName4->setText(QApplication::translate("Widget", "\351\200\232\351\201\2236", nullptr));
        CHName5->setText(QApplication::translate("Widget", "\351\200\232\351\201\2237", nullptr));
        CHName8->setText(QApplication::translate("Widget", "\351\200\232\351\201\2238", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

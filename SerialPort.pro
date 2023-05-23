QT       += core gui serialport testlib network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bandpassfilter_cofficient.cpp \
    fft_recvdata.cpp \
    fir_bandpassfilter.cpp \
    fir_highpassfilter.cpp \
    fir_trapfilter.cpp \
    global_values.cpp \
    highpassfilter_cofficient.cpp \
    main.cpp \
    qcustomplot.cpp \
    trapfilter_cofficient.cpp \
    uart_recvdata.cpp \
    udp_recvdata.cpp \
    usb_thread.cpp \
    widget.cpp

HEADERS += \
    bandpassfilter_cofficient.h \
    fft_recvdata.h \
    fftw-3.3.5-dll64/fftw3.h \
    fir_bandpassfilter.h \
    fir_highpassfilter.h \
    fir_trapfilter.h \
    global_values.h \
    hidapi.h \
    highpassfilter_cofficient.h \
    qcustomplot.h \
    trapfilter_cofficient.h \
    uart_recvdata.h \
    udp_recvdata.h \
    usb_thread.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/ -lhidapi
LIBS += $$PWD/fftw-3.3.5-dll64/libfftw3-3.lib

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

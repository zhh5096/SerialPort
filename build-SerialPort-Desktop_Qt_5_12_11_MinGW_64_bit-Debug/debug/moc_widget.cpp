/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SerialPort/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 15), // "closeAllThreads"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "eegDataPlotUpdate"
QT_MOC_LITERAL(4, 42, 24), // "on_PBtn_UartOpen_clicked"
QT_MOC_LITERAL(5, 67, 23), // "on_PBtn_UDPOpen_clicked"
QT_MOC_LITERAL(6, 91, 23), // "on_PBtn_Refresh_clicked"
QT_MOC_LITERAL(7, 115, 30), // "on_PBtn_HighPassFilter_clicked"
QT_MOC_LITERAL(8, 146, 26), // "on_PBtn_TrapFilter_clicked"
QT_MOC_LITERAL(9, 173, 30), // "on_PBtn_BandPassFilter_clicked"
QT_MOC_LITERAL(10, 204, 29), // "on_PBtn_LowPassFilter_clicked"
QT_MOC_LITERAL(11, 234, 21), // "on_PBtn_RmsPP_clicked"
QT_MOC_LITERAL(12, 256, 13), // "setFFTMessage"
QT_MOC_LITERAL(13, 270, 28), // "on_PBtn_SaveRecvData_clicked"
QT_MOC_LITERAL(14, 299, 19), // "on_PBtn_CCA_clicked"
QT_MOC_LITERAL(15, 319, 28), // "on_Slider_FFTrr_valueChanged"
QT_MOC_LITERAL(16, 348, 20) // "on_PBtn_IBLS_clicked"

    },
    "Widget\0closeAllThreads\0\0eegDataPlotUpdate\0"
    "on_PBtn_UartOpen_clicked\0"
    "on_PBtn_UDPOpen_clicked\0on_PBtn_Refresh_clicked\0"
    "on_PBtn_HighPassFilter_clicked\0"
    "on_PBtn_TrapFilter_clicked\0"
    "on_PBtn_BandPassFilter_clicked\0"
    "on_PBtn_LowPassFilter_clicked\0"
    "on_PBtn_RmsPP_clicked\0setFFTMessage\0"
    "on_PBtn_SaveRecvData_clicked\0"
    "on_PBtn_CCA_clicked\0on_Slider_FFTrr_valueChanged\0"
    "on_PBtn_IBLS_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeAllThreads(); break;
        case 1: _t->eegDataPlotUpdate(); break;
        case 2: _t->on_PBtn_UartOpen_clicked(); break;
        case 3: _t->on_PBtn_UDPOpen_clicked(); break;
        case 4: _t->on_PBtn_Refresh_clicked(); break;
        case 5: _t->on_PBtn_HighPassFilter_clicked(); break;
        case 6: _t->on_PBtn_TrapFilter_clicked(); break;
        case 7: _t->on_PBtn_BandPassFilter_clicked(); break;
        case 8: _t->on_PBtn_LowPassFilter_clicked(); break;
        case 9: _t->on_PBtn_RmsPP_clicked(); break;
        case 10: _t->setFFTMessage(); break;
        case 11: _t->on_PBtn_SaveRecvData_clicked(); break;
        case 12: _t->on_PBtn_CCA_clicked(); break;
        case 13: _t->on_Slider_FFTrr_valueChanged(); break;
        case 14: _t->on_PBtn_IBLS_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

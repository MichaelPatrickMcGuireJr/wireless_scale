/****************************************************************************
** Meta object code from reading C++ file 'rfreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../readNRF24l01_display/rfreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rfreader_t {
    QByteArrayData data[7];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rfreader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rfreader_t qt_meta_stringdata_rfreader = {
    {
QT_MOC_LITERAL(0, 0, 8), // "rfreader"
QT_MOC_LITERAL(1, 9, 10), // "get_double"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "get_qstring"
QT_MOC_LITERAL(4, 33, 11), // "startThread"
QT_MOC_LITERAL(5, 45, 10), // "stopThread"
QT_MOC_LITERAL(6, 56, 11) // "read_sensor"

    },
    "rfreader\0get_double\0\0get_qstring\0"
    "startThread\0stopThread\0read_sensor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rfreader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x02 /* Public */,
       3,    0,   40,    2, 0x02 /* Public */,
       4,    0,   41,    2, 0x02 /* Public */,
       5,    0,   42,    2, 0x02 /* Public */,
       6,    0,   43,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Double,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rfreader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rfreader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { double _r = _t->get_double();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->get_qstring();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->startThread(); break;
        case 3: _t->stopThread(); break;
        case 4: _t->read_sensor(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rfreader::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_rfreader.data,
    qt_meta_data_rfreader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rfreader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rfreader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rfreader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rfreader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

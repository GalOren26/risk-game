/****************************************************************************
** Meta object code from reading C++ file 'risk.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../risk.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'risk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_risk_t {
    QByteArrayData data[9];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_risk_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_risk_t qt_meta_stringdata_risk = {
    {
QT_MOC_LITERAL(0, 0, 4), // "risk"
QT_MOC_LITERAL(1, 5, 4), // "LOAD"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 4), // "SAVE"
QT_MOC_LITERAL(4, 16, 5), // "ENTER"
QT_MOC_LITERAL(5, 22, 8), // "SAVE_ALL"
QT_MOC_LITERAL(6, 31, 9), // "saveStats"
QT_MOC_LITERAL(7, 41, 4), // "EXIT"
QT_MOC_LITERAL(8, 46, 9) // "nextState"

    },
    "risk\0LOAD\0\0SAVE\0ENTER\0SAVE_ALL\0saveStats\0"
    "EXIT\0nextState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_risk[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void risk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        risk *_t = static_cast<risk *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->LOAD();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->SAVE(); break;
        case 2: _t->ENTER(); break;
        case 3: _t->SAVE_ALL(); break;
        case 4: _t->saveStats(); break;
        case 5: _t->EXIT(); break;
        case 6: _t->nextState(); break;
        default: ;
        }
    }
}

const QMetaObject risk::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_risk.data,
      qt_meta_data_risk,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *risk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *risk::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_risk.stringdata0))
        return static_cast<void*>(const_cast< risk*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int risk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'LogControl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/logClient/LogControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogControl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   11,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,
      63,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,
      86,   11,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogControl[] = {
    "LogControl\0\0update_speed(QString)\0"
    "log_forward()\0log_backward()\0log_play()\0"
    "log_pause()\0log_faster()\0log_slower()\0"
    "log_frame_forward()\0log_frame_back()\0"
    "goto_frame(int)\0"
};

void LogControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogControl *_t = static_cast<LogControl *>(_o);
        switch (_id) {
        case 0: _t->update_speed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->log_forward(); break;
        case 2: _t->log_backward(); break;
        case 3: _t->log_play(); break;
        case 4: _t->log_pause(); break;
        case 5: _t->log_faster(); break;
        case 6: _t->log_slower(); break;
        case 7: _t->log_frame_forward(); break;
        case 8: _t->log_frame_back(); break;
        case 9: _t->goto_frame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LogControl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogControl,
      qt_meta_data_LogControl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogControl))
        return static_cast<void*>(const_cast< LogControl*>(this));
    return QObject::qt_metacast(_clname);
}

int LogControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void LogControl::update_speed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ClientThreading.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/logClient/ClientThreading.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientThreading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewUpdateThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      36,   17,   17,   17, 0x05,
      55,   50,   17,   17, 0x05,
      93,   17,   17,   17, 0x05,
     114,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ViewUpdateThread[] = {
    "ViewUpdateThread\0\0update_frame(int)\0"
    "log_size(int)\0,,,,\0"
    "initializeSlider(int,int,int,int,int)\0"
    "showLogControl(bool)\0change_play_button(QString)\0"
    "playLogfilePressed()\0"
};

void ViewUpdateThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewUpdateThread *_t = static_cast<ViewUpdateThread *>(_o);
        switch (_id) {
        case 0: _t->update_frame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->log_size((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->initializeSlider((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->showLogControl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->change_play_button((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->playLogfilePressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViewUpdateThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewUpdateThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ViewUpdateThread,
      qt_meta_data_ViewUpdateThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewUpdateThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewUpdateThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewUpdateThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewUpdateThread))
        return static_cast<void*>(const_cast< ViewUpdateThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ViewUpdateThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ViewUpdateThread::update_frame(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViewUpdateThread::log_size(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ViewUpdateThread::initializeSlider(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ViewUpdateThread::showLogControl(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ViewUpdateThread::change_play_button(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

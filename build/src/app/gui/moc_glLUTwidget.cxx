/****************************************************************************
** Meta object code from reading C++ file 'glLUTwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/app/gui/glLUTwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glLUTwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLLUTWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      48,   42,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,   12,   12,   12, 0x09,
      91,   12,   12,   12, 0x09,
     102,   12,   12,   12, 0x09,
     114,   12,   12,   12, 0x09,
     129,   12,   12,   12, 0x0a,
     138,   12,   12,   12, 0x0a,
     155,   12,   12,   12, 0x0a,
     169,   12,   12,   12, 0x0a,
     180,   12,   12,   12, 0x0a,
     193,   12,   12,   12, 0x0a,
     212,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLLUTWidget[] = {
    "GLLUTWidget\0\0updateVideoStats(VideoStats)\0"
    "event\0signalKeyPressEvent(QKeyEvent*)\0"
    "editUndo()\0editRedo()\0editStore()\0"
    "editClearAll()\0redraw()\0callZoomNormal()\0"
    "callZoomFit()\0callHelp()\0switchMode()\0"
    "rebuildAndRedraw()\0clearSampler()\0"
};

void GLLUTWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLLUTWidget *_t = static_cast<GLLUTWidget *>(_o);
        switch (_id) {
        case 0: _t->updateVideoStats((*reinterpret_cast< VideoStats(*)>(_a[1]))); break;
        case 1: _t->signalKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->editUndo(); break;
        case 3: _t->editRedo(); break;
        case 4: _t->editStore(); break;
        case 5: _t->editClearAll(); break;
        case 6: _t->redraw(); break;
        case 7: _t->callZoomNormal(); break;
        case 8: _t->callZoomFit(); break;
        case 9: _t->callHelp(); break;
        case 10: _t->switchMode(); break;
        case 11: _t->rebuildAndRedraw(); break;
        case 12: _t->clearSampler(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLLUTWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLLUTWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLLUTWidget,
      qt_meta_data_GLLUTWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLLUTWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLLUTWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLLUTWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLLUTWidget))
        return static_cast<void*>(const_cast< GLLUTWidget*>(this));
    if (!strcmp(_clname, "RealTimeDisplayWidget"))
        return static_cast< RealTimeDisplayWidget*>(const_cast< GLLUTWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLLUTWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void GLLUTWidget::updateVideoStats(VideoStats _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLLUTWidget::signalKeyPressEvent(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

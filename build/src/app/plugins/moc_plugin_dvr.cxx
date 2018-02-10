/****************************************************************************
** Meta object code from reading C++ file 'plugin_dvr.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/app/plugins/plugin_dvr.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin_dvr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginDVRWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_PluginDVRWidget[] = {
    "PluginDVRWidget\0"
};

void PluginDVRWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PluginDVRWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginDVRWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PluginDVRWidget,
      qt_meta_data_PluginDVRWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginDVRWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginDVRWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginDVRWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginDVRWidget))
        return static_cast<void*>(const_cast< PluginDVRWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PluginDVRWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_PluginDVR[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x09,
      29,   10,   10,   10, 0x09,
      48,   10,   10,   10, 0x09,
      70,   10,   10,   10, 0x09,
      91,   10,   10,   10, 0x09,
     114,   10,   10,   10, 0x09,
     134,   10,   10,   10, 0x09,
     154,   10,   10,   10, 0x09,
     169,   10,   10,   10, 0x09,
     185,   10,   10,   10, 0x09,
     205,  201,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_PluginDVR[] = {
    "PluginDVR\0\0slotModeToggled()\0"
    "slotPauseRefresh()\0slotSeekModeToggled()\0"
    "slotSeekFrameFirst()\0slotSeekFrameForward()\0"
    "slotSeekFrameBack()\0slotSeekFrameLast()\0"
    "slotMovieNew()\0slotMovieLoad()\0"
    "slotMovieSave()\0val\0jogValueChanged(float)\0"
};

void PluginDVR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PluginDVR *_t = static_cast<PluginDVR *>(_o);
        switch (_id) {
        case 0: _t->slotModeToggled(); break;
        case 1: _t->slotPauseRefresh(); break;
        case 2: _t->slotSeekModeToggled(); break;
        case 3: _t->slotSeekFrameFirst(); break;
        case 4: _t->slotSeekFrameForward(); break;
        case 5: _t->slotSeekFrameBack(); break;
        case 6: _t->slotSeekFrameLast(); break;
        case 7: _t->slotMovieNew(); break;
        case 8: _t->slotMovieLoad(); break;
        case 9: _t->slotMovieSave(); break;
        case 10: _t->jogValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PluginDVR::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginDVR::staticMetaObject = {
    { &VisionPlugin::staticMetaObject, qt_meta_stringdata_PluginDVR,
      qt_meta_data_PluginDVR, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginDVR::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginDVR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginDVR::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginDVR))
        return static_cast<void*>(const_cast< PluginDVR*>(this));
    return VisionPlugin::qt_metacast(_clname);
}

int PluginDVR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VisionPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

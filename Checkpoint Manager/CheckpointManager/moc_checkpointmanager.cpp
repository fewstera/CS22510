/****************************************************************************
** Meta object code from reading C++ file 'checkpointmanager.h'
**
** Created: Fri Mar 22 13:57:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "checkpointmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkpointmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckpointManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      42,   18,   18,   18, 0x0a,
      59,   18,   18,   18, 0x0a,
      84,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CheckpointManager[] = {
    "CheckpointManager\0\0checkpointChanged(int)\0"
    "entrantChanged()\0entrantExcludedChanged()\0"
    "submitPressed()\0"
};

void CheckpointManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckpointManager *_t = static_cast<CheckpointManager *>(_o);
        switch (_id) {
        case 0: _t->checkpointChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->entrantChanged(); break;
        case 2: _t->entrantExcludedChanged(); break;
        case 3: _t->submitPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CheckpointManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckpointManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CheckpointManager,
      qt_meta_data_CheckpointManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckpointManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckpointManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckpointManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckpointManager))
        return static_cast<void*>(const_cast< CheckpointManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int CheckpointManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

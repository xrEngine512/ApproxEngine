/****************************************************************************
** Meta object code from reading C++ file 'ApproxSceneVarsContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ApproxSceneVarsContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ApproxSceneVarsContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ApproxSceneVarsContainer_t {
    QByteArrayData data[6];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApproxSceneVarsContainer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApproxSceneVarsContainer_t qt_meta_stringdata_ApproxSceneVarsContainer = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ApproxSceneVarsContainer"
QT_MOC_LITERAL(1, 25, 11), // "linkAttempt"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "QWidget*"
QT_MOC_LITERAL(4, 47, 6), // "sender"
QT_MOC_LITERAL(5, 54, 17) // "mouseGlobalPosEnd"

    },
    "ApproxSceneVarsContainer\0linkAttempt\0"
    "\0QWidget*\0sender\0mouseGlobalPosEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApproxSceneVarsContainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    4,    5,

       0        // eod
};

void ApproxSceneVarsContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ApproxSceneVarsContainer *_t = static_cast<ApproxSceneVarsContainer *>(_o);
        switch (_id) {
        case 0: _t->linkAttempt((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ApproxSceneVarsContainer::*_t)(QWidget * , const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ApproxSceneVarsContainer::linkAttempt)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ApproxSceneVarsContainer::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ApproxSceneVarsContainer.data,
      qt_meta_data_ApproxSceneVarsContainer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ApproxSceneVarsContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApproxSceneVarsContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ApproxSceneVarsContainer.stringdata))
        return static_cast<void*>(const_cast< ApproxSceneVarsContainer*>(this));
    return QFrame::qt_metacast(_clname);
}

int ApproxSceneVarsContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ApproxSceneVarsContainer::linkAttempt(QWidget * _t1, const QPoint & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
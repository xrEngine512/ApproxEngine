/****************************************************************************
** Meta object code from reading C++ file 'shaderlabgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shaderlabgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shaderlabgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ASL__ShaderLabGUI_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ASL__ShaderLabGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ASL__ShaderLabGUI_t qt_meta_stringdata_ASL__ShaderLabGUI = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ASL::ShaderLabGUI"
QT_MOC_LITERAL(1, 18, 11), // "on_Settings"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10) // "on_NewView"

    },
    "ASL::ShaderLabGUI\0on_Settings\0\0"
    "on_NewView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ASL__ShaderLabGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ASL::ShaderLabGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShaderLabGUI *_t = static_cast<ShaderLabGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Settings(); break;
        case 1: _t->on_NewView(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ASL::ShaderLabGUI::staticMetaObject = {
    { &ApproxGUI::ApproxWindow<QWidget>::staticMetaObject, qt_meta_stringdata_ASL__ShaderLabGUI.data,
      qt_meta_data_ASL__ShaderLabGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ASL::ShaderLabGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ASL::ShaderLabGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ASL__ShaderLabGUI.stringdata0))
        return static_cast<void*>(const_cast< ShaderLabGUI*>(this));
    return ApproxGUI::ApproxWindow<QWidget>::qt_metacast(_clname);
}

int ASL::ShaderLabGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApproxGUI::ApproxWindow<QWidget>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'LocationResource.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/include/connections/LocationResource.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LocationResource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSLocationResourceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSLocationResourceENDCLASS = QtMocHelpers::stringData(
    "LocationResource",
    "networkResponse",
    "",
    "ResponseType",
    "responseType",
    "data",
    "networkRequestFinished",
    "searchQ",
    "search",
    "Success",
    "Failed",
    "NetworkError"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLocationResourceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   48, // properties
       1,   53, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    3 /* Public */,
       1,    1,   43,    2, 0x26,    6 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   46,    2, 0x0a,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   47,    2, 0x02,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QJsonArray,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00015902, uint(-1), 0,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    3,   58,

 // enum data: key, value
       9, uint(LocationResource::Success),
      10, uint(LocationResource::Failed),
      11, uint(LocationResource::NetworkError),

       0        // eod
};

Q_CONSTINIT const QMetaObject LocationResource::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractResource::staticMetaObject>(),
    qt_meta_stringdata_CLASSLocationResourceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLocationResourceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLocationResourceENDCLASS_t,
        // property 'search'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // enum 'ResponseType'
        QtPrivate::TypeAndForceComplete<LocationResource::ResponseType, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LocationResource, std::true_type>,
        // method 'networkResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResponseType, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonArray &, std::false_type>,
        // method 'networkResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ResponseType, std::false_type>,
        // method 'networkRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchQ'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LocationResource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocationResource *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->networkResponse((*reinterpret_cast< std::add_pointer_t<ResponseType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 1: _t->networkResponse((*reinterpret_cast< std::add_pointer_t<ResponseType>>(_a[1]))); break;
        case 2: _t->networkRequestFinished(); break;
        case 3: _t->searchQ(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LocationResource::*)(ResponseType , const QJsonArray & );
            if (_t _q_method = &LocationResource::networkResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LocationResource *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSearch(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *LocationResource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocationResource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLocationResourceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractResource::qt_metacast(_clname);
}

int LocationResource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractResource::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void LocationResource::networkResponse(ResponseType _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

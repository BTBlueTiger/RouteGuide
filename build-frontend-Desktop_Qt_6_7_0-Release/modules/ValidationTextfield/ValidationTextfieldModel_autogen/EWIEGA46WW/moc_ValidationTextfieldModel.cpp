/****************************************************************************
** Meta object code from reading C++ file 'ValidationTextfieldModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../frontend/modules/ValidationTextfield/ValidationTextfieldModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ValidationTextfieldModel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSValidationTextfieldModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSValidationTextfieldModelENDCLASS = QtMocHelpers::stringData(
    "ValidationTextfieldModel",
    "QML.Element",
    "auto",
    "stateChanged",
    "",
    "borderColorChanged",
    "colorChanged",
    "opacityChanged",
    "state",
    "borderColor",
    "color",
    "opacity",
    "type",
    "ValidationTyp",
    "NONE",
    "EMAIL"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSValidationTextfieldModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       5,   50, // properties
       1,   75, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   40,    4, 0x06,    7 /* Public */,
       5,    1,   41,    4, 0x06,    8 /* Public */,
       6,    1,   44,    4, 0x06,   10 /* Public */,
       7,    1,   47,    4, 0x06,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Float,    4,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00015103, uint(0), 0,
       9, QMetaType::QString, 0x00015001, uint(1), 0,
      10, QMetaType::QString, 0x00015001, uint(2), 0,
      11, QMetaType::Float, 0x00015001, uint(3), 0,
      12, QMetaType::Int, 0x00015103, uint(-1), 0,

 // enums: name, alias, flags, count, data
      13,   13, 0x0,    2,   80,

 // enum data: key, value
      14, uint(ValidationTextfieldModel::NONE),
      15, uint(ValidationTextfieldModel::EMAIL),

       0        // eod
};

Q_CONSTINIT const QMetaObject ValidationTextfieldModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSValidationTextfieldModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSValidationTextfieldModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'state'
        int,
        // property 'borderColor'
        QString,
        // property 'color'
        QString,
        // property 'opacity'
        float,
        // property 'type'
        int,
        // enum 'ValidationTyp'
        ValidationTextfieldModel::ValidationTyp,
        // Q_OBJECT / Q_GADGET
        ValidationTextfieldModel,
        // method 'stateChanged'
        void,
        // method 'borderColorChanged'
        void,
        QString,
        // method 'colorChanged'
        void,
        QString,
        // method 'opacityChanged'
        void,
        float
    >,
    nullptr
} };

void ValidationTextfieldModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ValidationTextfieldModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged(); break;
        case 1: _t->borderColorChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->opacityChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ValidationTextfieldModel::*)();
            if (_t _q_method = &ValidationTextfieldModel::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ValidationTextfieldModel::*)(QString );
            if (_t _q_method = &ValidationTextfieldModel::borderColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ValidationTextfieldModel::*)(QString );
            if (_t _q_method = &ValidationTextfieldModel::colorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ValidationTextfieldModel::*)(float );
            if (_t _q_method = &ValidationTextfieldModel::opacityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ValidationTextfieldModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->borderColor(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->color(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->opacity(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->type(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ValidationTextfieldModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setState(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setType(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ValidationTextfieldModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ValidationTextfieldModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSValidationTextfieldModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ValidationTextfieldModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ValidationTextfieldModel::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ValidationTextfieldModel::borderColorChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ValidationTextfieldModel::colorChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ValidationTextfieldModel::opacityChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP

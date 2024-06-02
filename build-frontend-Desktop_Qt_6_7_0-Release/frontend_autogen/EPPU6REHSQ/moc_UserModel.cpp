/****************************************************************************
** Meta object code from reading C++ file 'UserModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/include/models/UserModel.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserModel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSUserModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserModelENDCLASS = QtMocHelpers::stringData(
    "UserModel",
    "userChanged",
    "",
    "registerSuccessChanged",
    "premiumGroupsChanged",
    "QList<int>",
    "email_tChanged",
    "loginAttempt",
    "data",
    "logoutAttempt",
    "emailType",
    "EMAIL_T",
    "email",
    "registerAttempt",
    "changePremiumGroup",
    "group",
    "user",
    "loggedIn",
    "registerSuccess",
    "email_t",
    "loginPath",
    "logoutPath",
    "COMPANY",
    "PRIVATE",
    "PREMIUM",
    "ERROR",
    "PREMIUM_GROUPS",
    "HIKER",
    "SPORTLER",
    "TOURIST"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       6,   89, // properties
       2,  119, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    9 /* Public */,
       3,    0,   69,    2, 0x06,   10 /* Public */,
       4,    1,   70,    2, 0x06,   11 /* Public */,
       6,    1,   73,    2, 0x06,   13 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   76,    2, 0x02,   15 /* Public */,
       9,    0,   79,    2, 0x02,   17 /* Public */,
      10,    1,   80,    2, 0x02,   18 /* Public */,
      13,    1,   83,    2, 0x02,   20 /* Public */,
      14,    1,   86,    2, 0x02,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantMap,    8,
    QMetaType::Void,
    0x80000000 | 11, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QVariantMap,    8,
    QMetaType::Void, QMetaType::Int,   15,

 // properties: name, type, flags
      16, QMetaType::QString, 0x00015001, uint(0), 0,
      17, QMetaType::Bool, 0x00015001, uint(0), 0,
      18, QMetaType::Bool, 0x00015001, uint(1), 0,
      19, QMetaType::Int, 0x00015903, uint(3), 0,
      20, QMetaType::QString, 0x00015003, uint(-1), 0,
      21, QMetaType::QString, 0x00015003, uint(-1), 0,

 // enums: name, alias, flags, count, data
      11,   11, 0x0,    4,  129,
      26,   26, 0x0,    3,  137,

 // enum data: key, value
      22, uint(UserModel::COMPANY),
      23, uint(UserModel::PRIVATE),
      24, uint(UserModel::PREMIUM),
      25, uint(UserModel::ERROR),
      27, uint(UserModel::HIKER),
      28, uint(UserModel::SPORTLER),
      29, uint(UserModel::TOURIST),

       0        // eod
};

Q_CONSTINIT const QMetaObject UserModel::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractResource::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserModelENDCLASS_t,
        // property 'user'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'loggedIn'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'registerSuccess'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'email_t'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'loginPath'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'logoutPath'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // enum 'EMAIL_T'
        QtPrivate::TypeAndForceComplete<UserModel::EMAIL_T, std::true_type>,
        // enum 'PREMIUM_GROUPS'
        QtPrivate::TypeAndForceComplete<UserModel::PREMIUM_GROUPS, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserModel, std::true_type>,
        // method 'userChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerSuccessChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'premiumGroupsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        // method 'email_tChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loginAttempt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'logoutAttempt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emailType'
        QtPrivate::TypeAndForceComplete<EMAIL_T, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'registerAttempt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'changePremiumGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void UserModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->userChanged(); break;
        case 1: _t->registerSuccessChanged(); break;
        case 2: _t->premiumGroupsChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 3: _t->email_tChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->loginAttempt((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 5: _t->logoutAttempt(); break;
        case 6: { EMAIL_T _r = _t->emailType((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< EMAIL_T*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->registerAttempt((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 8: _t->changePremiumGroup((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserModel::*)();
            if (_t _q_method = &UserModel::userChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserModel::*)();
            if (_t _q_method = &UserModel::registerSuccessChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserModel::*)(QVector<int> );
            if (_t _q_method = &UserModel::premiumGroupsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserModel::*)(int );
            if (_t _q_method = &UserModel::email_tChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UserModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->user(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->loggedIn(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->registerSuccess(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->email_t(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->m_loginPath; break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->m_logoutPath; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UserModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setEmail_t(*reinterpret_cast< int*>(_v)); break;
        case 4:
            if (_t->m_loginPath != *reinterpret_cast< QString*>(_v)) {
                _t->m_loginPath = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 5:
            if (_t->m_logoutPath != *reinterpret_cast< QString*>(_v)) {
                _t->m_logoutPath = *reinterpret_cast< QString*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *UserModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractResource::qt_metacast(_clname);
}

int UserModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractResource::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserModel::userChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserModel::registerSuccessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserModel::premiumGroupsChanged(QVector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserModel::email_tChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP

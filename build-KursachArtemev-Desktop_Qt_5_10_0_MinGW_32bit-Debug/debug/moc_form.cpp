/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KursachArtemev/form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_t {
    QByteArrayData data[16];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_t qt_meta_stringdata_Form = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Form"
QT_MOC_LITERAL(1, 5, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(4, 48, 7), // "checked"
QT_MOC_LITERAL(5, 56, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 80, 5), // "pause"
QT_MOC_LITERAL(7, 86, 6), // "resume"
QT_MOC_LITERAL(8, 93, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(9, 114, 5), // "index"
QT_MOC_LITERAL(10, 120, 15), // "updateTableViev"
QT_MOC_LITERAL(11, 136, 1), // "x"
QT_MOC_LITERAL(12, 138, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(13, 165, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(14, 189, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(15, 213, 9) // "slotAbout"

    },
    "Form\0on_pushButton_clicked\0\0"
    "on_checkBox_toggled\0checked\0"
    "on_pushButton_2_clicked\0pause\0resume\0"
    "on_tableView_clicked\0index\0updateTableViev\0"
    "x\0on_tableView_doubleClicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "slotAbout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Form *_t = static_cast<Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->pause(); break;
        case 4: _t->resume(); break;
        case 5: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->updateTableViev((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->slotAbout(); break;
        default: ;
        }
    }
}

const QMetaObject Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form.data,
      qt_meta_data_Form,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OAR/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[409];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "isKeyRepeated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "key"
QT_MOC_LITERAL(4, 30, 20), // "on_newFile_triggered"
QT_MOC_LITERAL(5, 51, 12), // "Availability"
QT_MOC_LITERAL(6, 64, 9), // "lookIndex"
QT_MOC_LITERAL(7, 74, 21), // "on_addField_triggered"
QT_MOC_LITERAL(8, 96, 21), // "on_delField_triggered"
QT_MOC_LITERAL(9, 118, 24), // "on_updateField_triggered"
QT_MOC_LITERAL(10, 143, 22), // "on_addRecord_triggered"
QT_MOC_LITERAL(11, 166, 30), // "on_Tabla_Principal_itemChanged"
QT_MOC_LITERAL(12, 197, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(13, 215, 22), // "on_delRecord_triggered"
QT_MOC_LITERAL(14, 238, 21), // "on_saveFile_triggered"
QT_MOC_LITERAL(15, 260, 23), // "on_saveRecord_triggered"
QT_MOC_LITERAL(16, 284, 22), // "on_closeFile_triggered"
QT_MOC_LITERAL(17, 307, 24), // "on_exitProgram_triggered"
QT_MOC_LITERAL(18, 332, 24), // "on_importFiles_triggered"
QT_MOC_LITERAL(19, 357, 25), // "on_updateRecord_triggered"
QT_MOC_LITERAL(20, 383, 25) // "on_searchRecord_triggered"

    },
    "MainWindow\0isKeyRepeated\0\0key\0"
    "on_newFile_triggered\0Availability\0"
    "lookIndex\0on_addField_triggered\0"
    "on_delField_triggered\0on_updateField_triggered\0"
    "on_addRecord_triggered\0"
    "on_Tabla_Principal_itemChanged\0"
    "QTableWidgetItem*\0on_delRecord_triggered\0"
    "on_saveFile_triggered\0on_saveRecord_triggered\0"
    "on_closeFile_triggered\0on_exitProgram_triggered\0"
    "on_importFiles_triggered\0"
    "on_updateRecord_triggered\0"
    "on_searchRecord_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    0,  102,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    1,  104,    2, 0x08 /* Private */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    0,  108,    2, 0x08 /* Private */,
       9,    0,  109,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    1,  111,    2, 0x08 /* Private */,
      13,    0,  114,    2, 0x08 /* Private */,
      14,    0,  115,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::UInt, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->isKeyRepeated((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->on_newFile_triggered(); break;
        case 2: { int _r = _t->Availability();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { uint _r = _t->lookIndex((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 4: _t->on_addField_triggered(); break;
        case 5: _t->on_delField_triggered(); break;
        case 6: _t->on_updateField_triggered(); break;
        case 7: _t->on_addRecord_triggered(); break;
        case 8: _t->on_Tabla_Principal_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_delRecord_triggered(); break;
        case 10: _t->on_saveFile_triggered(); break;
        case 11: _t->on_saveRecord_triggered(); break;
        case 12: _t->on_closeFile_triggered(); break;
        case 13: _t->on_exitProgram_triggered(); break;
        case 14: _t->on_importFiles_triggered(); break;
        case 15: _t->on_updateRecord_triggered(); break;
        case 16: _t->on_searchRecord_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

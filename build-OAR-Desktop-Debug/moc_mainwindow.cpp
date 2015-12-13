/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OAR/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 20),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 12),
QT_MOC_LITERAL(4, 46, 9),
QT_MOC_LITERAL(5, 56, 21),
QT_MOC_LITERAL(6, 78, 21),
QT_MOC_LITERAL(7, 100, 24),
QT_MOC_LITERAL(8, 125, 22),
QT_MOC_LITERAL(9, 148, 30),
QT_MOC_LITERAL(10, 179, 17),
QT_MOC_LITERAL(11, 197, 22),
QT_MOC_LITERAL(12, 220, 21),
QT_MOC_LITERAL(13, 242, 23),
QT_MOC_LITERAL(14, 266, 22),
QT_MOC_LITERAL(15, 289, 24),
QT_MOC_LITERAL(16, 314, 24),
QT_MOC_LITERAL(17, 339, 25),
QT_MOC_LITERAL(18, 365, 25)
    },
    "MainWindow\0on_newFile_triggered\0\0"
    "Availability\0lookIndex\0on_addField_triggered\0"
    "on_delField_triggered\0on_updateField_triggered\0"
    "on_addRecord_triggered\0"
    "on_Tabla_Principal_itemChanged\0"
    "QTableWidgetItem*\0on_delRecord_triggered\0"
    "on_saveFile_triggered\0on_saveRecord_triggered\0"
    "on_closeFile_triggered\0on_exitProgram_triggered\0"
    "on_importFiles_triggered\0"
    "on_updateRecord_triggered\0"
    "on_searchRecord_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08,
       3,    0,   95,    2, 0x08,
       4,    1,   96,    2, 0x08,
       5,    0,   99,    2, 0x08,
       6,    0,  100,    2, 0x08,
       7,    0,  101,    2, 0x08,
       8,    0,  102,    2, 0x08,
       9,    1,  103,    2, 0x08,
      11,    0,  106,    2, 0x08,
      12,    0,  107,    2, 0x08,
      13,    0,  108,    2, 0x08,
      14,    0,  109,    2, 0x08,
      15,    0,  110,    2, 0x08,
      16,    0,  111,    2, 0x08,
      17,    0,  112,    2, 0x08,
      18,    0,  113,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::UInt, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
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
        switch (_id) {
        case 0: _t->on_newFile_triggered(); break;
        case 1: { int _r = _t->Availability();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { uint _r = _t->lookIndex((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 3: _t->on_addField_triggered(); break;
        case 4: _t->on_delField_triggered(); break;
        case 5: _t->on_updateField_triggered(); break;
        case 6: _t->on_addRecord_triggered(); break;
        case 7: _t->on_Tabla_Principal_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_delRecord_triggered(); break;
        case 9: _t->on_saveFile_triggered(); break;
        case 10: _t->on_saveRecord_triggered(); break;
        case 11: _t->on_closeFile_triggered(); break;
        case 12: _t->on_exitProgram_triggered(); break;
        case 13: _t->on_importFiles_triggered(); break;
        case 14: _t->on_updateRecord_triggered(); break;
        case 15: _t->on_searchRecord_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

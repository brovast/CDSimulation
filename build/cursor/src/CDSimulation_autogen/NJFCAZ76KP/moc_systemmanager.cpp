/****************************************************************************
** Meta object code from reading C++ file 'systemmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/views/system/systemmanager.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSSystemManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSystemManagerENDCLASS = QtMocHelpers::stringData(
    "SystemManager",
    "onBasicDataTreeClicked",
    "",
    "QModelIndex",
    "index",
    "onCDDataTreeClicked",
    "onNewModelClicked",
    "onAddStructureTypeClicked",
    "onCopyDataClicked",
    "onDeleteClicked",
    "onTaskFilterChanged",
    "onTaskSearch",
    "text",
    "onTaskSelectionChanged",
    "onTaskPublishClicked",
    "onTaskDeleteClicked",
    "onSelectWorkDirClicked",
    "onModelTypeChanged",
    "onSystemTabChanged",
    "onSelectBasicDataPath",
    "onAddBasicFolder",
    "onDeleteBasicData",
    "onBasicDataItemClicked",
    "onSelectAcousticsPath",
    "loadAcousticsCSV",
    "filePath",
    "onSelectCSVClicked",
    "loadCSVData",
    "onSelectLoadPathClicked",
    "onLoadFileSelected",
    "QListWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSystemManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  158,    2, 0x08,    1 /* Private */,
       5,    1,  161,    2, 0x08,    3 /* Private */,
       6,    0,  164,    2, 0x08,    5 /* Private */,
       7,    0,  165,    2, 0x08,    6 /* Private */,
       8,    0,  166,    2, 0x08,    7 /* Private */,
       9,    0,  167,    2, 0x08,    8 /* Private */,
      10,    0,  168,    2, 0x08,    9 /* Private */,
      11,    1,  169,    2, 0x08,   10 /* Private */,
      13,    0,  172,    2, 0x08,   12 /* Private */,
      14,    0,  173,    2, 0x08,   13 /* Private */,
      15,    0,  174,    2, 0x08,   14 /* Private */,
      16,    0,  175,    2, 0x08,   15 /* Private */,
      17,    1,  176,    2, 0x08,   16 /* Private */,
      18,    1,  179,    2, 0x08,   18 /* Private */,
      19,    0,  182,    2, 0x08,   20 /* Private */,
      20,    0,  183,    2, 0x08,   21 /* Private */,
      21,    0,  184,    2, 0x08,   22 /* Private */,
      22,    1,  185,    2, 0x08,   23 /* Private */,
      23,    0,  188,    2, 0x08,   25 /* Private */,
      24,    1,  189,    2, 0x08,   26 /* Private */,
      26,    0,  192,    2, 0x08,   28 /* Private */,
      27,    1,  193,    2, 0x08,   29 /* Private */,
      28,    0,  196,    2, 0x08,   31 /* Private */,
      29,    1,  197,    2, 0x08,   32 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

Q_CONSTINIT const QMetaObject SystemManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSystemManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSystemManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSystemManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SystemManager, std::true_type>,
        // method 'onBasicDataTreeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onCDDataTreeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onNewModelClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddStructureTypeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCopyDataClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTaskFilterChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTaskSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onTaskSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTaskPublishClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTaskDeleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSelectWorkDirClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModelTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSystemTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSelectBasicDataPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddBasicFolder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteBasicData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onBasicDataItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'onSelectAcousticsPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAcousticsCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSelectCSVClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadCSVData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSelectLoadPathClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLoadFileSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>
    >,
    nullptr
} };

void SystemManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onBasicDataTreeClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->onCDDataTreeClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->onNewModelClicked(); break;
        case 3: _t->onAddStructureTypeClicked(); break;
        case 4: _t->onCopyDataClicked(); break;
        case 5: _t->onDeleteClicked(); break;
        case 6: _t->onTaskFilterChanged(); break;
        case 7: _t->onTaskSearch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->onTaskSelectionChanged(); break;
        case 9: _t->onTaskPublishClicked(); break;
        case 10: _t->onTaskDeleteClicked(); break;
        case 11: _t->onSelectWorkDirClicked(); break;
        case 12: _t->onModelTypeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->onSystemTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->onSelectBasicDataPath(); break;
        case 15: _t->onAddBasicFolder(); break;
        case 16: _t->onDeleteBasicData(); break;
        case 17: _t->onBasicDataItemClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 18: _t->onSelectAcousticsPath(); break;
        case 19: _t->loadAcousticsCSV((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->onSelectCSVClicked(); break;
        case 21: _t->loadCSVData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->onSelectLoadPathClicked(); break;
        case 23: _t->onLoadFileSelected((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SystemManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSystemManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SystemManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newFile;
    QAction *saveFile;
    QAction *closeFile;
    QAction *exitProgram;
    QAction *addField;
    QAction *importFiles;
    QAction *delField;
    QAction *updateField;
    QAction *addRecord;
    QAction *updateRecord;
    QAction *delRecord;
    QAction *saveRecord;
    QAction *searchRecord;
    QAction *exportExcel;
    QWidget *centralWidget;
    QTableWidget *Tabla_Principal;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuCampo;
    QMenu *menuRegistros;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(845, 613);
        newFile = new QAction(MainWindow);
        newFile->setObjectName(QStringLiteral("newFile"));
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QStringLiteral("saveFile"));
        closeFile = new QAction(MainWindow);
        closeFile->setObjectName(QStringLiteral("closeFile"));
        exitProgram = new QAction(MainWindow);
        exitProgram->setObjectName(QStringLiteral("exitProgram"));
        addField = new QAction(MainWindow);
        addField->setObjectName(QStringLiteral("addField"));
        importFiles = new QAction(MainWindow);
        importFiles->setObjectName(QStringLiteral("importFiles"));
        delField = new QAction(MainWindow);
        delField->setObjectName(QStringLiteral("delField"));
        updateField = new QAction(MainWindow);
        updateField->setObjectName(QStringLiteral("updateField"));
        addRecord = new QAction(MainWindow);
        addRecord->setObjectName(QStringLiteral("addRecord"));
        updateRecord = new QAction(MainWindow);
        updateRecord->setObjectName(QStringLiteral("updateRecord"));
        delRecord = new QAction(MainWindow);
        delRecord->setObjectName(QStringLiteral("delRecord"));
        saveRecord = new QAction(MainWindow);
        saveRecord->setObjectName(QStringLiteral("saveRecord"));
        searchRecord = new QAction(MainWindow);
        searchRecord->setObjectName(QStringLiteral("searchRecord"));
        exportExcel = new QAction(MainWindow);
        exportExcel->setObjectName(QStringLiteral("exportExcel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tabla_Principal = new QTableWidget(centralWidget);
        Tabla_Principal->setObjectName(QStringLiteral("Tabla_Principal"));
        Tabla_Principal->setGeometry(QRect(10, 60, 821, 491));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 845, 24));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuCampo = new QMenu(menuBar);
        menuCampo->setObjectName(QStringLiteral("menuCampo"));
        menuRegistros = new QMenu(menuBar);
        menuRegistros->setObjectName(QStringLiteral("menuRegistros"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuCampo->menuAction());
        menuBar->addAction(menuRegistros->menuAction());
        menuArchivo->addAction(newFile);
        menuArchivo->addAction(saveFile);
        menuArchivo->addAction(exportExcel);
        menuArchivo->addAction(closeFile);
        menuArchivo->addAction(exitProgram);
        menuCampo->addAction(addField);
        menuCampo->addAction(delField);
        menuCampo->addAction(updateField);
        menuRegistros->addAction(importFiles);
        menuRegistros->addSeparator();
        menuRegistros->addAction(searchRecord);
        menuRegistros->addSeparator();
        menuRegistros->addAction(addRecord);
        menuRegistros->addAction(updateRecord);
        menuRegistros->addAction(delRecord);
        menuRegistros->addSeparator();
        menuRegistros->addAction(saveRecord);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newFile->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        saveFile->setText(QApplication::translate("MainWindow", "Guardar", 0));
        closeFile->setText(QApplication::translate("MainWindow", "Cerrar", 0));
        exitProgram->setText(QApplication::translate("MainWindow", "Salir", 0));
        addField->setText(QApplication::translate("MainWindow", "Crear", 0));
        importFiles->setText(QApplication::translate("MainWindow", "Cargar ", 0));
        delField->setText(QApplication::translate("MainWindow", "Borrar", 0));
        updateField->setText(QApplication::translate("MainWindow", "Modificar", 0));
        addRecord->setText(QApplication::translate("MainWindow", "Agregar", 0));
        updateRecord->setText(QApplication::translate("MainWindow", "Modificar", 0));
        delRecord->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        saveRecord->setText(QApplication::translate("MainWindow", "Guardar", 0));
        searchRecord->setText(QApplication::translate("MainWindow", "Buscar", 0));
#ifndef QT_NO_TOOLTIP
        searchRecord->setToolTip(QApplication::translate("MainWindow", "Buscar Reigistro", 0));
#endif // QT_NO_TOOLTIP
        exportExcel->setText(QApplication::translate("MainWindow", "Exportar Excel", 0));
#ifndef QT_NO_TOOLTIP
        exportExcel->setToolTip(QApplication::translate("MainWindow", "Exportar a Excel", 0));
#endif // QT_NO_TOOLTIP
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuCampo->setTitle(QApplication::translate("MainWindow", "Campo", 0));
        menuRegistros->setTitle(QApplication::translate("MainWindow", "Registros", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *actionGuardar;
    QAction *actionSalvar;
    QAction *actionCerrar;
    QAction *actionSalir;
    QAction *CrearCampo;
    QAction *actionListar;
    QAction *actionModificar;
    QAction *actionCargar;
    QAction *actionBorrar;
    QAction *actionModificar_2;
    QWidget *centralWidget;
    QTableWidget *Tabla_Principal;
    QPushButton *pushButton;
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
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionSalvar = new QAction(MainWindow);
        actionSalvar->setObjectName(QStringLiteral("actionSalvar"));
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QStringLiteral("actionCerrar"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        CrearCampo = new QAction(MainWindow);
        CrearCampo->setObjectName(QStringLiteral("CrearCampo"));
        actionListar = new QAction(MainWindow);
        actionListar->setObjectName(QStringLiteral("actionListar"));
        actionModificar = new QAction(MainWindow);
        actionModificar->setObjectName(QStringLiteral("actionModificar"));
        actionCargar = new QAction(MainWindow);
        actionCargar->setObjectName(QStringLiteral("actionCargar"));
        actionBorrar = new QAction(MainWindow);
        actionBorrar->setObjectName(QStringLiteral("actionBorrar"));
        actionModificar_2 = new QAction(MainWindow);
        actionModificar_2->setObjectName(QStringLiteral("actionModificar_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tabla_Principal = new QTableWidget(centralWidget);
        Tabla_Principal->setObjectName(QStringLiteral("Tabla_Principal"));
        Tabla_Principal->setGeometry(QRect(10, 60, 821, 491));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 131, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 845, 22));
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
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionSalvar);
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addAction(actionSalir);
        menuCampo->addAction(CrearCampo);
        menuCampo->addAction(actionBorrar);
        menuCampo->addAction(actionModificar_2);
        menuRegistros->addAction(actionCargar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNuevo->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", 0));
        actionSalvar->setText(QApplication::translate("MainWindow", "Salvar", 0));
        actionCerrar->setText(QApplication::translate("MainWindow", "Cerrar", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        CrearCampo->setText(QApplication::translate("MainWindow", "Crear", 0));
        actionListar->setText(QApplication::translate("MainWindow", "Listar", 0));
        actionModificar->setText(QApplication::translate("MainWindow", "Modificar", 0));
        actionCargar->setText(QApplication::translate("MainWindow", "Cargar ", 0));
        actionBorrar->setText(QApplication::translate("MainWindow", "Borrar", 0));
        actionModificar_2->setText(QApplication::translate("MainWindow", "Modificar", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Agregar Registro", 0));
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

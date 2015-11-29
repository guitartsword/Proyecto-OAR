#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Campo.h"
#include "dialogcampo.h"
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <vector>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    borrar_campo(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tabla_Principal->setDisabled(true);
    campos = new vector<FieldDefenition>();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete campos;
}


void MainWindow::on_actionNuevo_triggered()
{
    ui->Tabla_Principal->setEnabled(true);
    QFile datafile("../../../Data.OAR");
    if (!datafile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Failed to create:" << datafile.errorString();
    datafile.flush();
    datafile.close();
    ui->Tabla_Principal->setRowCount(1);
}

void MainWindow::on_CrearCampo_triggered()
{
    if(ui->Tabla_Principal->isEnabled()){
        DialogCampo dialog(this->campos,ui->Tabla_Principal,this);
        dialog.exec();
    }else{
        QMessageBox Box;
        Box.setText("¡Debe crear un nuevo archivo para agregar campos!");
        Box.exec();
    }

}

void MainWindow::on_sectionClicked ( int logicalIndex ){
    cout<<"HOLA";
}

void MainWindow::on_actionBorrar_triggered()
{
    QMessageBox Box;
    Box.setText("Haga click en el campo que desea borrar");
    Box.exec();
    borrar_campo=true;
}




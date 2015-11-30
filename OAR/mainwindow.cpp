#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Campo.h"
#include "dialogcampo.h"
#include "dialogmodificarcampo.h"
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


void MainWindow::on_newFile_triggered()
{
    ui->Tabla_Principal->setEnabled(true);
    QFile datafile("../../../Data.OAR");
    if (!datafile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Failed to create:" << datafile.errorString();
    datafile.flush();
    datafile.close();
    ui->Tabla_Principal->setRowCount(1);
}

void MainWindow::on_addField_triggered()
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

void MainWindow::on_delField_triggered()
{
    QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!selected.isEmpty()){
        int x=ui->Tabla_Principal->currentColumn();
        campos->erase(campos->begin()+x);
        ui->Tabla_Principal->removeColumn(ui->Tabla_Principal->currentColumn());
    }else{
        QMessageBox Box;
        Box.setText("¡No se ha seleccionado ninguna columna!");
        Box.exec();
    }
}




void MainWindow::on_updateField_triggered()
{
    QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!selected.isEmpty()){
        DialogModificarCampo dialog(this->campos,ui->Tabla_Principal,this);
        dialog.exec();
    }else{
        QMessageBox Box;
        Box.setText("¡No se ha seleccionado ninguna columna!");
        Box.exec();
    }
}

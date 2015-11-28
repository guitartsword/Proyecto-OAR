#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogcampo.h"
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tabla_Principal->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuevo_triggered()
{
    ui->Tabla_Principal->setEnabled(true);
    QFile datafile("../../../Data.txt");
    if (!datafile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Failed to create:" << datafile.errorString();
    datafile.flush();
    datafile.close();
}

void MainWindow::on_CrearCampo_triggered()
{
    DialogCampo dialog(this);
    dialog.exec();
}

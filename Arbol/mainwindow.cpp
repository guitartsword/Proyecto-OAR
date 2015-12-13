#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <iostream>
#include "btree.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    btree(6)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = "";
    filename = QInputDialog::getText(this,"Nuevo indice","Numero a agregar: ");
    int key = filename.toInt();
    Key temp(key,0);
    btree.addKey(btree.root,temp);
    cout << "***********************************************************" << endl;
    btree.PrintNodes(btree.root);
    cout << "***********************************************************" << endl;
    ui->treeIndexInputOrder->setText(ui->treeIndexInputOrder->text() + filename + ", ");
}

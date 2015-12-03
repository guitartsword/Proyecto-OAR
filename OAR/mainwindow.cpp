#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "campo.h"
#include "dialogcampo.h"
#include "dialogmodificarcampo.h"
#include "file.h"

#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <vector>
#include <QMessageBox>
#include <QInputDialog>
#include <fstream>
#include <string>


using namespace std;

bool isKeyRepeated(Campo&);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Avail_offset(0),
    ui(new Ui::MainWindow),
    campos(new vector<Campo>()),
    registro(campos)
{
    cout << "HERE" << endl;
    ui->setupUi(this);
    ui->Tabla_Principal->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete campos;
}


void MainWindow::on_newFile_triggered()
{
    ui->Tabla_Principal->setEnabled(true);
    QFileDialog dialog;
    /*QString pathExport = dialog.getSaveFileName(this, tr("Nombre del Archivo"),
                                         "/home",
                                         tr("Registros (*.OAR)"));*/
    //string text = pathExport.toUtf8().constData();
    QString filename = "";
    filename = QInputDialog::getText(this,"Nuevo Archivo","Ingrese el nombre del nuevo archivo:");
    string text = filename.toStdString();
    if(filename != ""){
        output = new File(text, "prueba");
    }
}

int MainWindow::Availability(){
    if(Avail_offset==0){
        return 0;
    }else{
        //Buscar en el archivo con el offset del avail
        //retornar la posicion
    }
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

void MainWindow::on_addRecord_triggered()
{
    if(ui->Tabla_Principal->columnCount()<1){
        QMessageBox Box;
        Box.setText("¡Se necesita al menos un campo!");
        Box.exec();
    }else if(ui->Tabla_Principal->rowCount()>15){
        QMessageBox Box;
        Box.setText("¡Solo puede ver 15 registros por pagina");
        Box.exec();
    }else
        ui->Tabla_Principal->setRowCount(ui->Tabla_Principal->rowCount()+1);

}

void MainWindow::on_delRecord_triggered()
{
    QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!selected.isEmpty() && ui->Tabla_Principal->rowCount()>1)
        ui->Tabla_Principal->removeRow(ui->Tabla_Principal->currentRow());
}


void MainWindow::on_Tabla_Principal_itemChanged(QTableWidgetItem *item)
{
    //Se va usar el avail list
    QString text = item->text();
    /*
    cout<<"item Changed: "<< text.toStdString() << endl;
    cout<<"Size: " << text.size() << endl;
    cout<<"campos size: " << campos->size() << endl;
    cout<<"item Column value: " << item->column() << endl;
    for(int i = 0; i < campos->size(); i++){
        cout << "campos->at(" << i << ") == " << campos->at(i).name << endl;
    }
    */

    if(text.size() > campos->at(item->column()).size){

        text.resize(campos->at(item->column()).size);
    }
    bool valid;
    switch(campos->at(item->column()).type){
        case INTF:
            text.toInt(&valid);
            break;
        case DEC:
            text.toDouble(&valid);
            break;
        default:
            valid = true;
    }
    cout <<"IS VALID? = "<< valid << endl;
    if(!valid || isKeyRepeated(campos->at(item->column())))
        text = "";
    item->setText(text);

}

bool isKeyRepeated(Campo &campo){
    if(!campo.key){
        return false;
    }
    /****************************************
     *
     *
     *
    //VALIDAR LA REPETICION DE REGISTROS
     *
     *
     *
     *
    ****************************************/
    return false;
}
string CampoString(){

}

void MainWindow::on_saveFile_triggered()
{
    output->saveHeader(campos);
}

void MainWindow::on_saveRecord_triggered()
{
    registro.setCampos(campos);
    for(int i = 0; i < ui->Tabla_Principal->columnCount(); i++){
        cout <<"guardando"<<i<<endl;
        QTableWidgetItem* temp = ui->Tabla_Principal->itemAt(ui->Tabla_Principal->currentRow(), i);
        char* tempstr;
        strcpy(tempstr, temp->text().toStdString().c_str());
        registro.setData(i,tempstr);
    }
}

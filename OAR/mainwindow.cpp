#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "campo.h"
#include "dialogcampo.h"
#include "dialogmodificarcampo.h"
#include "file.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <vector>
#include <QMessageBox>
#include <QInputDialog>
#include <QCloseEvent>
#include <fstream>
#include <string>


using namespace std;

bool isKeyRepeated(Campo&);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    file(NULL)
{
    ui->setupUi(this);
    ui->saveFile->setEnabled(false);
    ui->addField->setEnabled(false);
    ui->addRecord->setEnabled(false);
    ui->delField->setEnabled(false);
    ui->delRecord->setEnabled(false);
    ui->updateField->setEnabled(false);
    ui->updateRecord->setEnabled(false);
    ui->closeFile->setEnabled(false);
    ui->Tabla_Principal->setRowCount(ui->Tabla_Principal->rowCount() + 1);
    ui->Tabla_Principal->setDisabled(true);
    ui->saveRecord->setEnabled(false);
    escritura=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::llaveExist(){
    bool exist=false;
    for(int i=0;i<campos.size();i++){
        if(campos.at(i).key){
            exist=true;
        }
    }
    return exist;
}

int MainWindow::lookIndex(int key){
    int rrn=-1;
    return rrn;
}

void MainWindow::on_newFile_triggered()
{
    try{
        QString filename = "";
        filename = QInputDialog::getText(this,"Nuevo Archivo","Ingrese el nombre del nuevo archivo:");
        string text = filename.toStdString();
        if(filename != ""){
            if(file == NULL || file->isOpen()){
                delete file;
            }
            file = new File(text, text, false);
            ui->addField->setEnabled(true);
            ui->delField->setEnabled(true);
            ui->updateField->setEnabled(true);
            ui->closeFile->setEnabled(true);
            ui->importFiles->setEnabled(false);
            ui->newFile->setEnabled(false);
            ui->Tabla_Principal->setRowCount(1);
            ui->Tabla_Principal->setEnabled(true);
        }
    }catch (...) {
        qDebug() << "Error al crear el archivo" << endl;
    }
}

int MainWindow::Availability(){
    return file->getRRN();
}

void MainWindow::on_addField_triggered()
{
    try{
        if(ui->Tabla_Principal->isEnabled()){
            DialogCampo dialog(this->campos,ui->Tabla_Principal,this);
            dialog.exec();
            ui->saveFile->setEnabled(true);
        }else{
            QMessageBox Box;
            Box.setText("¡Debe crear un nuevo archivo para agregar campos!");
            Box.exec();
        }
    }catch(...){
    }
}

void MainWindow::on_delField_triggered()
{
    QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!selected.isEmpty()){
        int x=ui->Tabla_Principal->currentColumn();
        campos.erase(campos.begin()+x);
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
    }else{
        ui->Tabla_Principal->setRowCount(ui->Tabla_Principal->rowCount()+1);
        ui->addRecord->setEnabled(false);
        ui->saveRecord->setEnabled(true);
    }

}

void MainWindow::on_delRecord_triggered()
{
    QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!selected.isEmpty() && ui->Tabla_Principal->rowCount()>1)
        //Buscar offset en el indice
        int rrn=lookIndex(0);//hay que agarrar la llave de la tabla
        //Marcar como borrado en el Archivo y se Actualiza el Avail List
        file->deleteRecord(rrn);

        ui->Tabla_Principal->removeRow(ui->Tabla_Principal->currentRow());
}


void MainWindow::on_Tabla_Principal_itemChanged(QTableWidgetItem *item)
{
    if(ui->updateRecord->isEnabled()){
        QString text = item->text();
        if(text.size() > campos.at(item->column()).size){
            text.resize(campos.at(item->column()).size);
        }
        bool valid;
        switch(campos.at(item->column()).type){
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
        if(!valid || isKeyRepeated(campos.at(item->column())))
            text = "";
        item->setText(text);
    }else{
        item->setText("");
    }


}

bool isKeyRepeated(Campo &campo){
    if(!campo.key){
        return false;
    }
    /****************************************
     *
     *
     *
    //VALIDAR LA REPETICION DE REGISTROS CON EL INDICE1
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
    try{
        if(llaveExist()){
        if(ui->Tabla_Principal->isEnabled()){
            if(escritura && campos.size()>0){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Guardar", "Al guardar no podra agregar mas campos. ¿Esta seguro que desea guardar?",
                                              QMessageBox::Yes |QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    file->saveHeader(campos);
                    escritura=false;
                    ui->addRecord->setEnabled(true);
                    ui->delRecord->setEnabled(true);
                    ui->updateRecord->setEnabled(true);
                    ui->saveFile->setEnabled(false);
                    ui->addField->setEnabled(false);
                    ui->delField->setEnabled(false);
                    ui->updateField->setEnabled(false);
                    ui->Tabla_Principal->removeRow(0);
                }
            }
        }
        }else{
            QMessageBox Box;
            Box.setText("¡Debe haber un campo llave!");
            Box.exec();
        }
    }catch(...){
    }
}

void MainWindow::on_saveRecord_triggered()
{
    try{
        //Si existen campos
        if(campos.size()>0){
            cout<<"entre"<<endl;
            stringstream ss;
            for(int i=0;i<ui->Tabla_Principal->columnCount();i++){
                QString temp;
                temp=ui->Tabla_Principal->item(ui->Tabla_Principal->rowCount()-1,i)->text();
                ss<<left<<setw(campos.at(i).size) << temp.toStdString();
            }
            //Se mira el Avail List
            int RRN = file->getRRN();
            cout << ss.str() << endl;
            if(RRN==0){
                file->appendRecord(ss.str());
            }else{
                file->addRecord(ss.str(), RRN);
            }
            ui->addRecord->setEnabled(true);
            ui->saveRecord->setEnabled(false);
            /*Actualizar el indice

                ++++++++++++++++++
                +                +
                +                +
                +                +
                +                +
                +                +
                ++++++++++++++++++

            */
        }
    }catch(...){
        qDebug() << "Error al agregar registro" << endl;
    }
}

void MainWindow::on_closeFile_triggered()
{
    delete file;
    ui->setupUi(this);
    ui->saveFile->setEnabled(false);
    ui->addField->setEnabled(false);
    ui->addRecord->setEnabled(false);
    ui->delField->setEnabled(false);
    ui->delRecord->setEnabled(false);
    ui->updateField->setEnabled(false);
    ui->updateRecord->setEnabled(false);
    ui->closeFile->setEnabled(false);
    ui->Tabla_Principal->setRowCount(0);
    ui->Tabla_Principal->setDisabled(true);
    ui->saveRecord->setEnabled(false);
}

void MainWindow::on_exitProgram_triggered()
{
    delete file;
    QApplication::quit();
}
void MainWindow::closeEvent (QCloseEvent *event)
{
    delete file;
    event->accept();
}

void MainWindow::on_importFiles_triggered()
{

    QFileDialog dialog;
    this->ui->Tabla_Principal->setEnabled(true);
    QString pathExport = dialog.getOpenFileName(this, tr("Cargar Archivo"),
                                         "",
                                         tr("Registros (*.OAR)"));
    string text = pathExport.toStdString();
    if(file == NULL || file->isOpen()){
        delete file;
    }
    file = new File(text, text, true);
    campos = file->getCampos();
    int recordCount = file->recordCount();
    qDebug() << recordCount << endl;
    cout << campos.at(0).name << endl;
    for(int i = 0; i < recordCount; i++){
        file->getRecord(i);

    }
    qDebug() << "Finished on_importFiles_triggered() function";
}

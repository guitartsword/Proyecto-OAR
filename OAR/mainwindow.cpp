#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "campo.h"
#include "dialogcampo.h"
#include "dialogmodificarcampo.h"
#include "file.h"
#include "btree.h"
#include "node.h"
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
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    ui->searchRecord->setEnabled(false);
    ui->exportExcel->setEnabled(false);
    ui->crossFiles->setEnabled(false);
    escritura=true;
    forceInput = false;
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Autollenar(){
    cerr<<"Autogenerar"<<endl;
    ifstream names("./city.txt", ios::in);
    for(int i=0; i < 99; i++){
        stringstream ss;
        int key=i+1;
        string nombre;
        getline(names,nombre);
        nombre=nombre.substr(0,30);
        ss<<left<<setw(2) << key;
        ss<<left<<setw(30) << nombre;
        cout<<ss.str()<<endl;
        file->appendRecord(key, ss.str());
    }
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

/*REVISAR ESTA FUNCION, VER DONDE SE USA Y QUE HACE
 *
 *
 *
 *
*/
unsigned int MainWindow::lookIndex(unsigned int key){
    unsigned int rrn=0;
    return rrn;
}

void MainWindow::on_newFile_triggered()
{
    try{
        QString filename = "";
        filename = QInputDialog::getText(this,"Nuevo Archivo","Ingrese el nombre del nuevo archivo:");
        string text = filename.toStdString();
        if(filename != ""){
            file = new File(text, text, false);
            ui->addField->setEnabled(true);
            ui->delField->setEnabled(true);
            ui->updateField->setEnabled(true);
            ui->closeFile->setEnabled(true);
            ui->importFiles->setEnabled(false);
            ui->exportExcel->setEnabled(true);
            ui->newFile->setEnabled(false);
            ui->Tabla_Principal->setRowCount(1);
            ui->Tabla_Principal->setEnabled(true); 
            ui->L_Nombre->setText(filename);
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
            DialogCampo dialog(&(this->campos),ui->Tabla_Principal,this);
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
    try{
        QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
        if(!selected.isEmpty()){
            DialogModificarCampo dialog(&(this->campos),ui->Tabla_Principal,this);
            dialog.exec();
        }else{
            QMessageBox Box;
            Box.setText("¡No se ha seleccionado ninguna columna!");
            Box.exec();
        }
    }catch(...){
        qDebug()<<"Error al abrir la ventana modificar";
    }
}

void MainWindow::on_addRecord_triggered()
{
    if(ui->Tabla_Principal->columnCount()<1){
        QMessageBox Box;
        Box.setText("¡Se necesita al menos un campo!");
        Box.exec();
    }else{
        ui->Tabla_Principal->setRowCount(ui->Tabla_Principal->rowCount()+1);
        ui->addRecord->setEnabled(false);
        ui->saveRecord->setEnabled(true);
    }

}

void MainWindow::on_delRecord_triggered()
{
    int key;
    QModelIndexList tableSelection = ui->Tabla_Principal->selectionModel()->selectedIndexes();
    if(!tableSelection.isEmpty() && ui->Tabla_Principal->rowCount()>1){

        //Obtener el valor de la llave de la tabla
        for(int i = 0; i < campos.size(); i++){
            if(campos.at(i).key){
                key = ui->Tabla_Principal->item(ui->Tabla_Principal->currentRow(),i)->text().toInt();
                break;
            }
        }
        //Buscar offset/RRN en el indice
        //Marcar como borrado en el Archivo y se Actualiza el Avail List
        cout << "KEY search and to delete = " << key << endl;
        if(file->deleteRecord(key))
            ui->Tabla_Principal->removeRow(ui->Tabla_Principal->currentRow());
    }
}


void MainWindow::on_Tabla_Principal_itemChanged(QTableWidgetItem *item)
{
    if(ui->updateRecord->isEnabled() && !forceInput){
        QString text = item->text();
        if(text.size() > campos.at(item->column()).size){
            text.resize(campos.at(item->column()).size);
        }
        bool valid =true;
        switch(campos.at(item->column()).type){
        case INTF:
            text.toInt(&valid);
            valid = true;
            break;
        case DEC:
            text.toDouble(&valid);
            break;
        default:
            valid = true;
        }

        if(campos.at(item->column()).key && valid && !ui->importFiles->isEnabled()){
            if(isKeyRepeated(text.toInt())){
                valid=false;
            }
        }
        if(!valid)
            text = "";
        item->setText(text);
    }else if(!forceInput){
        item->setText("");
    }
    //NO PERMITIR CAMBIAR LA LLAVE O SI?
}

bool MainWindow::isKeyRepeated(int key){
    return file->arbol.keyExist(file->arbol.root,key);
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
                    ui->searchRecord->setEnabled(true);
                    ui->crossFiles->setEnabled(true);
                    //Autollenar();

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
            int key;
            stringstream ss;
            for(int i=0;i<ui->Tabla_Principal->columnCount();i++){
                QString temp;
                temp=ui->Tabla_Principal->item(ui->Tabla_Principal->rowCount()-1,i)->text();
                ss<<left<<setw(campos.at(i).size) << temp.toStdString();
                if(campos.at(i).key){
                    key = temp.toInt();
                }
            }
            //Se mira el Avail List
            int RRN = file->getRRN();
            cout << ss.str() << endl;
            if(RRN==0){
                cout << ss.str() << endl;
                file->appendRecord(key, ss.str());
                cout << ss.str() << endl;
            }else{
                file->addRecord(key, ss.str(), RRN);
            }
            cout << "FIN DE ESCRITURA" << endl;
            ui->addRecord->setEnabled(true);
            ui->saveRecord->setEnabled(false);
        }
    }catch(...){
        qDebug() << "Error al agregar registro" << endl;
    }
}

void MainWindow::on_closeFile_triggered()
{
    if(file->isOpen() || file != NULL){
        delete file;
        cout << "dile deleted" << endl;
    }
    ui->importFiles->setEnabled(true);
    ui->exportExcel->setEnabled(false);
    ui->saveFile->setEnabled(false);
    ui->addField->setEnabled(false);
    ui->addRecord->setEnabled(false);
    ui->delField->setEnabled(false);
    ui->delRecord->setEnabled(false);
    ui->updateField->setEnabled(false);
    ui->updateRecord->setEnabled(false);
    ui->closeFile->setEnabled(false);
    ui->crossFiles->setEnabled(false);
    //RESTART EVERYTHING
    ui->Tabla_Principal->setColumnCount(0);
    ui->Tabla_Principal->setRowCount(0);
    ui->Tabla_Principal->setDisabled(true);
    campos.clear();
    escritura = true;
    //FINISH
    ui->saveRecord->setEnabled(false);
    ui->searchRecord->setEnabled(false);
    ui->newFile->setEnabled(true);
    ui->L_Nombre->setText("");
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
    if(!text.empty()){
        cout << "Creating file at path: " << text << endl;
        string name = text.substr(0,text.size()-4);
        name = name.substr(name.rfind("/")+1);
        cout << "File Name = " << name << endl;
        file = new File(text, name, true);
        ui->L_Nombre->setText(name.c_str());
        cout << "Try to get campos..." << endl;
        campos = file->getCampos();
        cout << "SUCCESS" << endl;
        //Necesario habilitar para poder modificar la tabla
        ui->updateRecord->setEnabled(true);
        ui->Tabla_Principal->setEnabled(true);

        //Asigna la cantidad de columnas y le pone su nombre respectivo
        ui->Tabla_Principal->setColumnCount(campos.size());
        for(int i = 0; i < campos.size(); i++){
            QString nombre = campos.at(i).name;
            if(campos.at(i).key){
                ui->Tabla_Principal->setHorizontalHeaderItem(i,new QTableWidgetItem(nombre+" (Llave) "));
            }else{
                ui->Tabla_Principal->setHorizontalHeaderItem(i,new QTableWidgetItem(nombre));
            }
        }

        //Asigna la cantidad de registros en la fila
        int recordCount = file->recordCount();
        ui->Tabla_Principal->setRowCount(recordCount);
        //Escribe el registro en la tabla
        int tablePos=0;
        for(int i = 1; i <= recordCount; i++){
            char** data;
            try{

                data = file->getRecord(i,true);

                for(short j = 0; j < campos.size(); j++){
                    QString tabletext = data[j];
                    ui->Tabla_Principal->setItem(tablePos, j, new QTableWidgetItem(tabletext));
                    delete data[j];
                }
                delete[] data;
                tablePos++;
            }catch (const char* exception) {
                cerr << exception <<endl;
                ui->Tabla_Principal->removeRow(i-1);
            }
        }
        ui->closeFile->setEnabled(true);
        ui->importFiles->setEnabled(false);
        ui->exportExcel->setEnabled(true);
        ui->newFile->setEnabled(false);
        ui->addRecord->setEnabled(true);
        ui->delRecord->setEnabled(true);
        ui->saveFile->setEnabled(false);
        ui->addField->setEnabled(false);
        ui->delField->setEnabled(false);
        ui->searchRecord->setEnabled(true);
        ui->updateField->setEnabled(false);
        ui->crossFiles->setEnabled(true);
        qDebug() << "Finished on_importFiles_triggered() function";
    }
}

void MainWindow::on_updateRecord_triggered()
{
    try{
        QModelIndexList tableSelection = ui->Tabla_Principal->selectionModel()->selectedIndexes();
        if(!tableSelection.isEmpty()){
            QString filename = "";
            filename = QInputDialog::getText(this,"Nuevo Archivo","Ingrese la llave del registro a modificar:");
            int key = filename.toInt();
            /*for(int i = 0; i < campos.size(); i++){
                if(campos.at(i).key)
                    key = atoi(ui->Tabla_Principal->item(ui->Tabla_Principal->currentRow(),i)->text().toStdString().c_str());
            }*/
            unsigned int rrn = file->searchIndex(key);
            cout << "RRN = " << rrn << endl;
            cout << "key searched = " << key << endl;
            if(rrn == 0){
                QMessageBox Box;
                Box.setText("¡No se encontro el registro");
                Box.exec();
            }else{
                QMessageBox Box;
                Box.setText("¡Se modifico el registro correctamente!");
                try{
                    stringstream ss;
                    int key;
                    for(int i=0;i<ui->Tabla_Principal->columnCount();i++){
                        QString temp;
                        temp=ui->Tabla_Principal->item(ui->Tabla_Principal->currentRow(),i)->text();
                        ss<<left<<setw(campos.at(i).size) << temp.toStdString();
                        if(campos.at(i).key){
                            if(key != temp.toInt())
                                throw "La llave no debe cambiar";
                        }
                    }
                    file->addRecord(key, ss.str(),rrn);
                }catch(const char* error){
                    Box.setText(error);
                }
                Box.exec();
            }
        }else{
            QMessageBox Box;
            Box.setText("¡No selecciono ningun registro para modificar!");
            Box.exec();
        }
    }catch(...){
        QMessageBox Box;
        Box.setText("¡No se encontro el registro!");
        Box.exec();
    }
}

void MainWindow::on_searchRecord_triggered()
{
    QString filename = "";
    filename = QInputDialog::getText(this,"Nuevo Archivo","Ingrese la llave del registro a modificar:");
    int key = filename.toInt();
    try{
        int rrn = file->searchIndex(key);
        cout << "RRN" << rrn << endl;
        char** record = file->getRecord(rrn, true);
        ui->Tabla_Principal->setColumnCount(campos.size());
        ui->Tabla_Principal->setRowCount(1);
        forceInput = true;
        for(int i = 0; i < campos.size(); i++){
            cout << record[i] << endl;
            ui->Tabla_Principal->setItem(0,i,new QTableWidgetItem(record[i]));
        }
        forceInput = false;
    }catch(...){
        QMessageBox Box;
        Box.setText("No se encontro el registro");
        Box.exec();
    }
}

void MainWindow::on_exportExcel_triggered()
{
    QFileDialog dialog;
    QString pathExport = dialog.getSaveFileName(this, tr("Exportar Archivo"),
                                         "",
                                         tr("Microsoft Excel (*.xlsm)"));
    if(!pathExport.endsWith(".xlsm"))
        pathExport += ".xlsm";
    ofstream exportFile(pathExport.toStdString().c_str());
    int recordCount = file->recordCount();
    int i;
    for(i = 0; i < campos.size()-1; i++){
        exportFile << campos.at(i).name << ",";
    }
    exportFile << campos.at(i).name << endl;
    for(i = 1; i <= recordCount; i++){
        char** data;
        try{
            data = file->getRecord(i,true);
            for(int j = 0; j < campos.size()-1; j++){
                exportFile << data[j] << ",";
                delete data[j];
            }
            exportFile << data[campos.size()-1] << endl;
            delete data[campos.size()-1];
            delete[] data;
        }catch (const char* exception) {
            cerr << exception <<endl;
        }
    }
}

void MainWindow::on_crossFiles_triggered()
{
    if(ui->Tabla_Principal->isEnabled()){
        QModelIndexList selected = ui->Tabla_Principal->selectionModel()->selectedIndexes();
        if(!selected.isEmpty()){
            QString pathExport = QFileDialog::getOpenFileName(this, tr("Cargar Archivo"),
                                                 "",
                                                 tr("Registros (*.OAR)"));

            string path = pathExport.toStdString();
            if(!path.empty()){
                string name = path.substr(0,path.size()-4);
                name = name.substr(name.rfind("/")+1);
                File crossFile(path, name, true);
                if(crossFile.isOpen()){
                    cout << "create column" << endl;
                    ui->Tabla_Principal->setColumnCount(ui->Tabla_Principal->columnCount()+1);
                    ui->Tabla_Principal->setHorizontalHeaderItem(ui->Tabla_Principal->columnCount() - 1,new QTableWidgetItem("Cruzar: Data"));
                    for(int i = 0; i < ui->Tabla_Principal->rowCount(); i++){
                        cout << "inset data at = " << i << endl;
                        int keyToSearch = ui->Tabla_Principal->item(i,ui->Tabla_Principal->currentColumn())->text().toInt();
                        cout << "key to search " << keyToSearch << endl;
                        if(crossFile.arbol.keyExist(crossFile.arbol.root, keyToSearch)){
                            cout << "Searching" << endl;
                            int RRN = crossFile.arbol.findKeyRRN(crossFile.arbol.root, keyToSearch);
                            cout << "Getting record with RRN = " << RRN << endl;
                            crossFile.getCampos();
                            char** record = crossFile.getRecord(RRN,true);
                            cout << record[1] << endl;
                            QString recordName = record[1];
                            QTableWidgetItem* data = new QTableWidgetItem(recordName);
                            cout << "row = " << i << endl;
                            cout << "column = " << ui->Tabla_Principal->columnCount()-1 << endl;
                            int j = ui->Tabla_Principal->columnCount()-1;
                            forceInput = true;
                            ui->Tabla_Principal->setItem(i,j,new QTableWidgetItem(recordName));
                            cout << "FINISH WRITING DATA" << endl;
                        }
                    }
                    forceInput = false;
                }else{
                    QMessageBox Box;
                    Box.setText("No se pudo abrir el archivo");
                    Box.exec();
                }
            }
        }else{
            QMessageBox Box;
            Box.setText("¡No se ha seleccionado ninguna columna!");
            Box.exec();
        }
    }
}

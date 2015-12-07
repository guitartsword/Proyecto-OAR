#include "dialogcampo.h"
#include "ui_dialogcampo.h"
#include "campo.h"
#include <QString>
#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <vector>
#include <QMessageBox>
using namespace std;


DialogCampo::DialogCampo(QWidget* parent):
    QDialog(parent),
    ui(new Ui::DialogCampo)
{
    ui->setupUi(this);
}

DialogCampo::DialogCampo(vector<Campo>* campos,QTableWidget* tabla, QWidget* parent):
    QDialog(parent),
    ui(new Ui::DialogCampo),
    campos(campos)
{
    this->tabla=tabla;
    ui->setupUi(this);
}

DialogCampo::~DialogCampo()
{
    delete ui;
}

bool DialogCampo::busquedaLlave(){
    if(campos->size()>0){
        bool exists=false;
        for(int i=0;i<campos->size();i++){
            if(campos->at(i).key){
                exists=true;
            }
        }
        return exists;
    }else{
        return false;
    }
}

void DialogCampo::on_CampoNuevo_clicked()
{
    QString nombre=ui->T_CampoNombre->text();
    QString tipo=ui->CB_CampoTipo->itemText(ui->CB_CampoTipo->currentIndex());
    int longitud=ui->SB_CampoLongitud->value();
    bool llave=ui->RB_CampoLlave->isChecked();
    QMessageBox Box;
    bool crear=false;
    Campo temp;
    if(nombre!=""){
        if(longitud>0){
            try{
                if(( llave!=busquedaLlave() || (!llave && !busquedaLlave()))){
                    if(tipo=="CHAR"){
                        if(!llave){
                            memcpy(temp.name, nombre.toStdString().c_str() ,30);
                            temp.type=CHAR;
                            temp.size=longitud;
                            temp.key=false;
                            crear=true;
                        }else{
                            Box.setText("¡La llave tiene que ser tipo entero!");
                            Box.exec();
                        }
                    }else if(tipo=="INTF"){
                        memcpy(temp.name, nombre.toStdString().c_str() ,30);
                        temp.type=INTF;
                        temp.size=longitud;
                        temp.key=llave;
                        crear=true;
                    }else{
                        if(!llave){
                            memcpy(temp.name, nombre.toStdString().c_str() ,30);
                            temp.type=DEC;
                            temp.size=longitud;
                            temp.key=llave;
                            crear=true;
                        }else{
                            Box.setText("¡La llave tiene que ser tipo entero!");
                            Box.exec();
                        }
                    }
                    if(crear){
                        if(llave){
                            this->tabla->setColumnCount(this->tabla->columnCount()+1);
                            this->tabla->setHorizontalHeaderItem(this->tabla->columnCount()-1,new QTableWidgetItem(nombre+" (Llave) "));
                        }else{
                            this->tabla->setColumnCount(this->tabla->columnCount()+1);
                            this->tabla->setHorizontalHeaderItem(this->tabla->columnCount()-1,new QTableWidgetItem(nombre));
                        }
                        campos->push_back(temp);
                        this->setVisible(false);
                    }
                }else{
                    Box.setText("¡La llave ya existe!");
                    Box.exec();
                }
            }catch (...) {
                cout<<"error"<<endl;
            }
        }else{
            Box.setText("¡La longitud debe ser mayor que cero!");
            Box.exec();
        }
    }else{
        Box.setText("¡El nombre no puede estar vacio!");
        Box.exec();
    }
}

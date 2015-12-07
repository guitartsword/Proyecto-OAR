#include "dialogmodificarcampo.h"
#include "ui_dialogmodificarcampo.h"
#include "campo.h"
#include <QString>
#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <vector>
#include <QMessageBox>
#include <QAbstractItemModel>
#include <QDebug>

using namespace std;
DialogModificarCampo::DialogModificarCampo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModificarCampo)
{
    ui->setupUi(this);
}

DialogModificarCampo::DialogModificarCampo(vector<Campo>* campos,QTableWidget* tabla, QWidget* parent):
    QDialog(parent),
    ui(new Ui::DialogModificarCampo),
    campos(campos)
{
    ui->setupUi(this);
    this->tabla=tabla;
    Campo temp=campos->at(tabla->currentColumn());
    ui->T_ModificarNombre->setText(temp.name);
    ui->SB_ModificarLongitud->setValue(temp.size);
    if(temp.key){
        ui->RB_ModificarLlave->setChecked(true);
    }
    if(temp.type==CHAR){
        ui->CB_ModificarTipo->setCurrentIndex(0);
    }else if(temp.type==INTF){
        ui->CB_ModificarTipo->setCurrentIndex(1);
    }else{
        ui->CB_ModificarTipo->setCurrentIndex(2);
    }
}

DialogModificarCampo::~DialogModificarCampo()
{
    delete ui;
}

bool DialogModificarCampo::busquedaLlave(){
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

void DialogModificarCampo::on_ModificarCampo_clicked()
{
    QString nombre=ui->T_ModificarNombre->text();
    QString tipo=ui->CB_ModificarTipo->itemText(ui->CB_ModificarTipo->currentIndex());
    int longitud=ui->SB_ModificarLongitud->value();
    bool llave=ui->RB_ModificarLlave->isChecked();
    bool crear=false;
    QMessageBox Box;
    Campo* temp= &(campos->at(tabla->currentColumn()));
    bool llave_antigua=temp->key;
    if(nombre!=""){
        if(longitud>0){
            try{
                if(( llave!=busquedaLlave() || (!llave && !busquedaLlave()))||(llave_antigua)){
                    if(tipo=="CHAR"){
                        if(!llave){
                            memcpy(temp->name, nombre.toStdString().c_str() ,30);
                            temp->type=CHAR;
                            temp->size=longitud;
                            temp->key=llave;
                            crear=true;
                        }else{
                            Box.setText("¡La llave tiene que ser tipo entero!");
                            Box.exec();
                        }
                    }else if(tipo=="INTF"){
                        memcpy(temp->name, nombre.toStdString().c_str() ,30);
                        temp->type=INTF;
                        temp->size=longitud;
                        temp->key=llave;
                        crear=true;
                    }else{
                        if(!llave){
                            memcpy(temp->name, nombre.toStdString().c_str() ,30);
                            temp->type=DEC;
                            temp->size=longitud;
                            temp->key=llave;
                            crear=true;
                        }else{
                            Box.setText("¡La llave tiene que ser tipo entero!");
                            Box.exec();
                        }
                    }
                    if(crear){
                        if(llave){
                            this->tabla->setHorizontalHeaderItem(this->tabla->currentColumn(),new QTableWidgetItem(nombre+" (Llave) "));
                        }else{
                            this->tabla->setHorizontalHeaderItem(this->tabla->currentColumn(),new QTableWidgetItem(nombre));
                        }
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

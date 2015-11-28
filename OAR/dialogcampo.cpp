#include "dialogcampo.h"
#include "ui_dialogcampo.h"
#include <QString>
#include <iostream>
using namespace std;

DialogCampo::DialogCampo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCampo)
{
    ui->setupUi(this);
}

DialogCampo::~DialogCampo()
{
    delete ui;
}

void DialogCampo::on_CampoNuevo_clicked()
{
    const char* nombre=ui->T_CampoNombre->text().toLatin1().data();

}

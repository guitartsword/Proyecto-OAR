#ifndef DIALOGMODIFICARCAMPO_H
#define DIALOGMODIFICARCAMPO_H
#include "campo.h"

#include <QDialog>
#include <QString>
#include <iostream>
#include <QTableWidget>
#include <QHeaderView>
#include <vector>
#include <QMessageBox>

using namespace std;
namespace Ui {
class DialogModificarCampo;
}

class DialogModificarCampo : public QDialog
{
    Q_OBJECT
    QTableWidget* tabla;
    vector<Campo>* campos;

public:
    explicit DialogModificarCampo(QWidget *parent = 0);
    explicit DialogModificarCampo(vector<Campo>*, QTableWidget*, QWidget *parent = 0);
    ~DialogModificarCampo();

private slots:

    void on_ModificarCampo_clicked();

private:
    Ui::DialogModificarCampo *ui;
    bool busquedaLlave();
};

#endif // DIALOGMODIFICARCAMPO_H

#ifndef DIALOGCAMPO_H
#define DIALOGCAMPO_H
#include "Campo.h"
#include <QDialog>
#include <QTableWidget>
#include <vector>
using namespace std;

namespace Ui {
class DialogCampo;
}

class DialogCampo : public QDialog
{
    QTableWidget* tabla;
    vector<FieldDefinition>* campos;
    Q_OBJECT

public:
    explicit DialogCampo(QWidget *parent = 0);
    explicit DialogCampo(vector<FieldDefinition>*, QTableWidget*, QWidget *parent = 0);
    ~DialogCampo();

private slots:
    void on_CampoNuevo_clicked();

private:
    Ui::DialogCampo *ui;
    bool busquedaLlave();
};

#endif // DIALOGCAMPO_H

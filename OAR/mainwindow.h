#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Campo.h"
#include <QMainWindow>
#include <vector>
#include <QTableWidget>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<FieldDefenition> campos;
    bool borrar_campo;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNuevo_triggered();

    void on_CrearCampo_triggered();

    void on_actionBorrar_triggered();

    void on_Tabla_Principal_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

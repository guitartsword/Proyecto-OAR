#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Campo.h"
//#include "file.h"
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
    vector<FieldDefinition>* campos;
    int Avail_offset;
//    vector<File>* Files;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_newFile_triggered();

    int Availability();

    void on_addField_triggered();

    void on_delField_triggered();

    void on_updateField_triggered();

    void on_addRecord_triggered();

    void on_Tabla_Principal_itemChanged(QTableWidgetItem*);

    void on_delRecord_triggered();

    void on_saveFile_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

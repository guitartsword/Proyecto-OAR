#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "campo.h"
#include "file.h"
#include "record.h"
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
    vector<Campo> campos;
    File* file;
    bool escritura;//Se utiliza para escribir solo una vez el header
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

    void on_saveRecord_triggered();

    void on_closeFile_triggered();

    void on_exitProgram_triggered();

    void on_importFiles_triggered();

private:
    Ui::MainWindow *ui;
    void closeEvent (QCloseEvent *event);
};

#endif // MAINWINDOW_H

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
    vector<FieldDefenition>* campos;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_newFile_triggered();

    void on_addField_triggered();

    void on_delField_triggered();

    void on_updateField_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

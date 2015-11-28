#ifndef DIALOGCAMPO_H
#define DIALOGCAMPO_H

#include <QDialog>

namespace Ui {
class DialogCampo;
}

class DialogCampo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCampo(QWidget *parent = 0);
    ~DialogCampo();

private slots:
    void on_CampoNuevo_clicked();

private:
    Ui::DialogCampo *ui;
};

#endif // DIALOGCAMPO_H

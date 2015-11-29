/********************************************************************************
** Form generated from reading UI file 'dialogcampo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCAMPO_H
#define UI_DIALOGCAMPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogCampo
{
public:
    QComboBox *CB_CampoTipo;
    QLineEdit *T_CampoNombre;
    QPushButton *CampoNuevo;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *SB_CampoLongitud;
    QLabel *label_3;
    QRadioButton *RB_CampoLlave;

    void setupUi(QDialog *DialogCampo)
    {
        if (DialogCampo->objectName().isEmpty())
            DialogCampo->setObjectName(QStringLiteral("DialogCampo"));
        DialogCampo->resize(355, 251);
        CB_CampoTipo = new QComboBox(DialogCampo);
        CB_CampoTipo->setObjectName(QStringLiteral("CB_CampoTipo"));
        CB_CampoTipo->setGeometry(QRect(50, 90, 91, 26));
        T_CampoNombre = new QLineEdit(DialogCampo);
        T_CampoNombre->setObjectName(QStringLiteral("T_CampoNombre"));
        T_CampoNombre->setGeometry(QRect(50, 40, 231, 21));
        CampoNuevo = new QPushButton(DialogCampo);
        CampoNuevo->setObjectName(QStringLiteral("CampoNuevo"));
        CampoNuevo->setGeometry(QRect(230, 210, 113, 32));
        label = new QLabel(DialogCampo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 121, 16));
        label_2 = new QLabel(DialogCampo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 70, 121, 16));
        SB_CampoLongitud = new QSpinBox(DialogCampo);
        SB_CampoLongitud->setObjectName(QStringLiteral("SB_CampoLongitud"));
        SB_CampoLongitud->setGeometry(QRect(190, 123, 48, 31));
        label_3 = new QLabel(DialogCampo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 121, 16));
        RB_CampoLlave = new QRadioButton(DialogCampo);
        RB_CampoLlave->setObjectName(QStringLiteral("RB_CampoLlave"));
        RB_CampoLlave->setGeometry(QRect(60, 170, 111, 20));

        retranslateUi(DialogCampo);

        QMetaObject::connectSlotsByName(DialogCampo);
    } // setupUi

    void retranslateUi(QDialog *DialogCampo)
    {
        DialogCampo->setWindowTitle(QApplication::translate("DialogCampo", "Dialog", 0));
        CB_CampoTipo->clear();
        CB_CampoTipo->insertItems(0, QStringList()
         << QApplication::translate("DialogCampo", "CHAR", 0)
         << QApplication::translate("DialogCampo", "INTF", 0)
         << QApplication::translate("DialogCampo", "DEC", 0)
        );
        CampoNuevo->setText(QApplication::translate("DialogCampo", "Aceptar", 0));
        label->setText(QApplication::translate("DialogCampo", "Nombre del Campo", 0));
        label_2->setText(QApplication::translate("DialogCampo", "Tipo de Campo", 0));
        label_3->setText(QApplication::translate("DialogCampo", "Longitud del Campo", 0));
        RB_CampoLlave->setText(QApplication::translate("DialogCampo", "Llave Primaria", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogCampo: public Ui_DialogCampo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCAMPO_H

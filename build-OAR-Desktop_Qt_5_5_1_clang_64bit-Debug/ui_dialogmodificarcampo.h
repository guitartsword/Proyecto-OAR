/********************************************************************************
** Form generated from reading UI file 'dialogmodificarcampo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODIFICARCAMPO_H
#define UI_DIALOGMODIFICARCAMPO_H

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

class Ui_DialogModificarCampo
{
public:
    QLineEdit *T_ModificarNombre;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ModificarCampo;
    QLabel *label_4;
    QRadioButton *RB_ModificarLlave;
    QSpinBox *SB_ModificarLongitud;
    QComboBox *CB_ModificarTipo;

    void setupUi(QDialog *DialogModificarCampo)
    {
        if (DialogModificarCampo->objectName().isEmpty())
            DialogModificarCampo->setObjectName(QStringLiteral("DialogModificarCampo"));
        DialogModificarCampo->resize(369, 331);
        T_ModificarNombre = new QLineEdit(DialogModificarCampo);
        T_ModificarNombre->setObjectName(QStringLiteral("T_ModificarNombre"));
        T_ModificarNombre->setGeometry(QRect(20, 80, 331, 21));
        label = new QLabel(DialogModificarCampo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 191, 31));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(DialogModificarCampo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 59, 16));
        label_3 = new QLabel(DialogModificarCampo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 170, 121, 16));
        ModificarCampo = new QPushButton(DialogModificarCampo);
        ModificarCampo->setObjectName(QStringLiteral("ModificarCampo"));
        ModificarCampo->setGeometry(QRect(230, 280, 113, 32));
        label_4 = new QLabel(DialogModificarCampo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 121, 16));
        RB_ModificarLlave = new QRadioButton(DialogModificarCampo);
        RB_ModificarLlave->setObjectName(QStringLiteral("RB_ModificarLlave"));
        RB_ModificarLlave->setGeometry(QRect(30, 220, 111, 20));
        SB_ModificarLongitud = new QSpinBox(DialogModificarCampo);
        SB_ModificarLongitud->setObjectName(QStringLiteral("SB_ModificarLongitud"));
        SB_ModificarLongitud->setGeometry(QRect(160, 163, 48, 31));
        CB_ModificarTipo = new QComboBox(DialogModificarCampo);
        CB_ModificarTipo->setObjectName(QStringLiteral("CB_ModificarTipo"));
        CB_ModificarTipo->setGeometry(QRect(20, 130, 91, 26));

        retranslateUi(DialogModificarCampo);

        QMetaObject::connectSlotsByName(DialogModificarCampo);
    } // setupUi

    void retranslateUi(QDialog *DialogModificarCampo)
    {
        DialogModificarCampo->setWindowTitle(QApplication::translate("DialogModificarCampo", "Dialog", 0));
        label->setText(QApplication::translate("DialogModificarCampo", "Modificar Campo", 0));
        label_2->setText(QApplication::translate("DialogModificarCampo", "Nombre", 0));
        label_3->setText(QApplication::translate("DialogModificarCampo", "Longitud del Campo", 0));
        ModificarCampo->setText(QApplication::translate("DialogModificarCampo", "Guardar", 0));
        label_4->setText(QApplication::translate("DialogModificarCampo", "Tipo de Campo", 0));
        RB_ModificarLlave->setText(QApplication::translate("DialogModificarCampo", "Llave Primaria", 0));
        CB_ModificarTipo->clear();
        CB_ModificarTipo->insertItems(0, QStringList()
         << QApplication::translate("DialogModificarCampo", "CHAR", 0)
         << QApplication::translate("DialogModificarCampo", "INTF", 0)
         << QApplication::translate("DialogModificarCampo", "DEC", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class DialogModificarCampo: public Ui_DialogModificarCampo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODIFICARCAMPO_H

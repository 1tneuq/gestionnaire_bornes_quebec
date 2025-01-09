/********************************************************************************
** Form generated from reading UI file 'SupprimerEmployeUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMEREMPLOYEUI_H
#define UI_SUPPRIMEREMPLOYEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimerEmployeUI
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *identifiantSupprimer;
    QLabel *label_2;

    void setupUi(QDialog *SupprimerEmployeUI)
    {
        if (SupprimerEmployeUI->objectName().isEmpty())
            SupprimerEmployeUI->setObjectName(QString::fromUtf8("SupprimerEmployeUI"));
        SupprimerEmployeUI->resize(400, 233);
        buttonBox = new QDialogButtonBox(SupprimerEmployeUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 160, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SupprimerEmployeUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 141, 41));
        identifiantSupprimer = new QSpinBox(SupprimerEmployeUI);
        identifiantSupprimer->setObjectName(QString::fromUtf8("identifiantSupprimer"));
        identifiantSupprimer->setGeometry(QRect(190, 70, 91, 26));
        identifiantSupprimer->setMaximum(100000);
        label_2 = new QLabel(SupprimerEmployeUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 221, 41));

        retranslateUi(SupprimerEmployeUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), SupprimerEmployeUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SupprimerEmployeUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(SupprimerEmployeUI);
    } // setupUi

    void retranslateUi(QDialog *SupprimerEmployeUI)
    {
        SupprimerEmployeUI->setWindowTitle(QCoreApplication::translate("SupprimerEmployeUI", "SupprimerEmployeUI", nullptr));
        label->setText(QCoreApplication::translate("SupprimerEmployeUI", "Identifiant de la borne :", nullptr));
        label_2->setText(QCoreApplication::translate("SupprimerEmployeUI", "Supprimer une borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerEmployeUI: public Ui_SupprimerEmployeUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMEREMPLOYEUI_H

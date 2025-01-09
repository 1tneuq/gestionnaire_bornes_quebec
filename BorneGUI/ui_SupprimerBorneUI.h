/********************************************************************************
** Form generated from reading UI file 'SupprimerBorneUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERBORNEUI_H
#define UI_SUPPRIMERBORNEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimerBorneUI
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *supprimerBorne;
    QLabel *label_2;

    void setupUi(QDialog *SupprimerBorneUI)
    {
        if (SupprimerBorneUI->objectName().isEmpty())
            SupprimerBorneUI->setObjectName(QString::fromUtf8("SupprimerBorneUI"));
        SupprimerBorneUI->resize(400, 193);
        buttonBox = new QDialogButtonBox(SupprimerBorneUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 140, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SupprimerBorneUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 151, 21));
        supprimerBorne = new QSpinBox(SupprimerBorneUI);
        supprimerBorne->setObjectName(QString::fromUtf8("supprimerBorne"));
        supprimerBorne->setGeometry(QRect(210, 70, 111, 26));
        supprimerBorne->setMaximum(100000);
        label_2 = new QLabel(SupprimerBorneUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 20, 151, 21));

        retranslateUi(SupprimerBorneUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), SupprimerBorneUI, SLOT(validerSupprimerBorne()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SupprimerBorneUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(SupprimerBorneUI);
    } // setupUi

    void retranslateUi(QDialog *SupprimerBorneUI)
    {
        SupprimerBorneUI->setWindowTitle(QCoreApplication::translate("SupprimerBorneUI", "SupprimerBorneUI", nullptr));
        label->setText(QCoreApplication::translate("SupprimerBorneUI", "Identifiant de la borne :", nullptr));
        label_2->setText(QCoreApplication::translate("SupprimerBorneUI", "Supprimer une borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerBorneUI: public Ui_SupprimerBorneUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERBORNEUI_H

/********************************************************************************
** Form generated from reading UI file 'AjouterBorneStationnementUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERBORNESTATIONNEMENTUI_H
#define UI_AJOUTERBORNESTATIONNEMENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_AjouterBorneStationnementUI
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AjouterBorneStationnementUI)
    {
        if (AjouterBorneStationnementUI->objectName().isEmpty())
            AjouterBorneStationnementUI->setObjectName(QString::fromUtf8("AjouterBorneStationnementUI"));
        AjouterBorneStationnementUI->resize(400, 300);
        buttonBox = new QDialogButtonBox(AjouterBorneStationnementUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(AjouterBorneStationnementUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), AjouterBorneStationnementUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AjouterBorneStationnementUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(AjouterBorneStationnementUI);
    } // setupUi

    void retranslateUi(QDialog *AjouterBorneStationnementUI)
    {
        AjouterBorneStationnementUI->setWindowTitle(QCoreApplication::translate("AjouterBorneStationnementUI", "AjouterBorneStationnementUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterBorneStationnementUI: public Ui_AjouterBorneStationnementUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERBORNESTATIONNEMENTUI_H

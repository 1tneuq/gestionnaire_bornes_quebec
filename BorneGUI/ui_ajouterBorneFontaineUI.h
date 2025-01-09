/********************************************************************************
** Form generated from reading UI file 'ajouterBorneFontaineUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERBORNEFONTAINEUI_H
#define UI_AJOUTERBORNEFONTAINEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_ajouterBorneFontaineUI
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ajouterBorneFontaineUI)
    {
        if (ajouterBorneFontaineUI->objectName().isEmpty())
            ajouterBorneFontaineUI->setObjectName(QString::fromUtf8("ajouterBorneFontaineUI"));
        ajouterBorneFontaineUI->resize(400, 300);
        buttonBox = new QDialogButtonBox(ajouterBorneFontaineUI);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(ajouterBorneFontaineUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), ajouterBorneFontaineUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ajouterBorneFontaineUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(ajouterBorneFontaineUI);
    } // setupUi

    void retranslateUi(QDialog *ajouterBorneFontaineUI)
    {
        ajouterBorneFontaineUI->setWindowTitle(QCoreApplication::translate("ajouterBorneFontaineUI", "ajouterBorneFontaineUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ajouterBorneFontaineUI: public Ui_ajouterBorneFontaineUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERBORNEFONTAINEUI_H

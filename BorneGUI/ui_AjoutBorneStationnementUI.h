/********************************************************************************
** Form generated from reading UI file 'AjoutBorneStationnementUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTBORNESTATIONNEMENTUI_H
#define UI_AJOUTBORNESTATIONNEMENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutBorneStationnementUI
{
public:
    QLabel *label_prenom;
    QLineEdit *lineEdit_idVoiePublique;
    QLabel *label_nom;
    QLabel *label_dateNaissance;
    QLabel *label_titre;
    QLabel *label_codeDepartement;
    QLabel *label_quantite;
    QLabel *label_salaire;
    QLabel *label_commission;
    QSpinBox *identifiantBox;
    QLineEdit *lineEdit_nomTopographique;
    QDoubleSpinBox *doubleSpinBox_longitude;
    QDoubleSpinBox *doubleSpinBox_latitude;
    QLineEdit *lineEdit_coteRue;
    QSpinBox *numBorne;
    QPushButton *pushButton;

    void setupUi(QDialog *AjoutBorneStationnementUI)
    {
        if (AjoutBorneStationnementUI->objectName().isEmpty())
            AjoutBorneStationnementUI->setObjectName(QString::fromUtf8("AjoutBorneStationnementUI"));
        AjoutBorneStationnementUI->resize(516, 510);
        label_prenom = new QLabel(AjoutBorneStationnementUI);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(40, 140, 191, 41));
        lineEdit_idVoiePublique = new QLineEdit(AjoutBorneStationnementUI);
        lineEdit_idVoiePublique->setObjectName(QString::fromUtf8("lineEdit_idVoiePublique"));
        lineEdit_idVoiePublique->setGeometry(QRect(230, 140, 261, 31));
        label_nom = new QLabel(AjoutBorneStationnementUI);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(40, 90, 91, 41));
        label_dateNaissance = new QLabel(AjoutBorneStationnementUI);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(40, 190, 131, 41));
        label_titre = new QLabel(AjoutBorneStationnementUI);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(130, 20, 241, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_codeDepartement = new QLabel(AjoutBorneStationnementUI);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(40, 390, 151, 41));
        label_quantite = new QLabel(AjoutBorneStationnementUI);
        label_quantite->setObjectName(QString::fromUtf8("label_quantite"));
        label_quantite->setGeometry(QRect(40, 340, 141, 41));
        label_salaire = new QLabel(AjoutBorneStationnementUI);
        label_salaire->setObjectName(QString::fromUtf8("label_salaire"));
        label_salaire->setGeometry(QRect(40, 240, 91, 41));
        label_commission = new QLabel(AjoutBorneStationnementUI);
        label_commission->setObjectName(QString::fromUtf8("label_commission"));
        label_commission->setGeometry(QRect(40, 290, 91, 41));
        identifiantBox = new QSpinBox(AjoutBorneStationnementUI);
        identifiantBox->setObjectName(QString::fromUtf8("identifiantBox"));
        identifiantBox->setGeometry(QRect(230, 90, 71, 26));
        identifiantBox->setMaximum(100000);
        lineEdit_nomTopographique = new QLineEdit(AjoutBorneStationnementUI);
        lineEdit_nomTopographique->setObjectName(QString::fromUtf8("lineEdit_nomTopographique"));
        lineEdit_nomTopographique->setGeometry(QRect(230, 190, 261, 31));
        doubleSpinBox_longitude = new QDoubleSpinBox(AjoutBorneStationnementUI);
        doubleSpinBox_longitude->setObjectName(QString::fromUtf8("doubleSpinBox_longitude"));
        doubleSpinBox_longitude->setGeometry(QRect(230, 250, 151, 26));
        doubleSpinBox_longitude->setDecimals(14);
        doubleSpinBox_longitude->setMinimum(-180.000000000000000);
        doubleSpinBox_longitude->setMaximum(180.000000000000000);
        doubleSpinBox_latitude = new QDoubleSpinBox(AjoutBorneStationnementUI);
        doubleSpinBox_latitude->setObjectName(QString::fromUtf8("doubleSpinBox_latitude"));
        doubleSpinBox_latitude->setGeometry(QRect(230, 290, 151, 26));
        doubleSpinBox_latitude->setDecimals(14);
        doubleSpinBox_latitude->setMinimum(-180.000000000000000);
        doubleSpinBox_latitude->setMaximum(180.000000000000000);
        lineEdit_coteRue = new QLineEdit(AjoutBorneStationnementUI);
        lineEdit_coteRue->setObjectName(QString::fromUtf8("lineEdit_coteRue"));
        lineEdit_coteRue->setGeometry(QRect(230, 390, 261, 31));
        numBorne = new QSpinBox(AjoutBorneStationnementUI);
        numBorne->setObjectName(QString::fromUtf8("numBorne"));
        numBorne->setGeometry(QRect(230, 350, 71, 26));
        numBorne->setMaximum(10000);
        pushButton = new QPushButton(AjoutBorneStationnementUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 460, 181, 28));

        retranslateUi(AjoutBorneStationnementUI);
        QObject::connect(pushButton, SIGNAL(clicked()), AjoutBorneStationnementUI, SLOT(validerBorneStationnement()));

        QMetaObject::connectSlotsByName(AjoutBorneStationnementUI);
    } // setupUi

    void retranslateUi(QDialog *AjoutBorneStationnementUI)
    {
        AjoutBorneStationnementUI->setWindowTitle(QCoreApplication::translate("AjoutBorneStationnementUI", "AjoutBorneStationnementUI", nullptr));
        label_prenom->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Identifiant de la voie publique:", nullptr));
        label_nom->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Identifiant :", nullptr));
        label_dateNaissance->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Nom topographique :", nullptr));
        label_titre->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "AJout d\342\200\231une borne de stationnement", nullptr));
        label_codeDepartement->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "C\303\264t\303\251 de la rue :", nullptr));
        label_quantite->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Num\303\251ro de la borne :", nullptr));
        label_salaire->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Longitude :", nullptr));
        label_commission->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Latitude :", nullptr));
        pushButton->setText(QCoreApplication::translate("AjoutBorneStationnementUI", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutBorneStationnementUI: public Ui_AjoutBorneStationnementUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTBORNESTATIONNEMENTUI_H

/********************************************************************************
** Form generated from reading UI file 'AjoutBorneFontaineUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTBORNEFONTAINEUI_H
#define UI_AJOUTBORNEFONTAINEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutBorneFontaineUI
{
public:
    QLabel *label_salaire;
    QLabel *label_nom;
    QLineEdit *lineEdit_nomTopographique_stat;
    QLineEdit *lineEdit_ville_stat;
    QLabel *label_codeDepartement;
    QLabel *label_commission;
    QLabel *label_dateNaissance;
    QLabel *label_titre;
    QLabel *label_prenom;
    QLineEdit *lineEdit_idVoiePublique_stat;
    QLabel *label_quantite;
    QSpinBox *identifiant_statBox;
    QDoubleSpinBox *doubleSpinBox_latitude_stat;
    QDoubleSpinBox *doubleSpinBox_longitude_stat;
    QLineEdit *lineEdit_arrondissement_stat;
    QPushButton *pushButton;

    void setupUi(QDialog *AjoutBorneFontaineUI)
    {
        if (AjoutBorneFontaineUI->objectName().isEmpty())
            AjoutBorneFontaineUI->setObjectName(QString::fromUtf8("AjoutBorneFontaineUI"));
        AjoutBorneFontaineUI->resize(519, 511);
        label_salaire = new QLabel(AjoutBorneFontaineUI);
        label_salaire->setObjectName(QString::fromUtf8("label_salaire"));
        label_salaire->setGeometry(QRect(30, 230, 91, 41));
        label_nom = new QLabel(AjoutBorneFontaineUI);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(30, 80, 91, 41));
        lineEdit_nomTopographique_stat = new QLineEdit(AjoutBorneFontaineUI);
        lineEdit_nomTopographique_stat->setObjectName(QString::fromUtf8("lineEdit_nomTopographique_stat"));
        lineEdit_nomTopographique_stat->setGeometry(QRect(220, 180, 261, 31));
        lineEdit_ville_stat = new QLineEdit(AjoutBorneFontaineUI);
        lineEdit_ville_stat->setObjectName(QString::fromUtf8("lineEdit_ville_stat"));
        lineEdit_ville_stat->setGeometry(QRect(220, 330, 261, 31));
        label_codeDepartement = new QLabel(AjoutBorneFontaineUI);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(30, 380, 151, 41));
        label_commission = new QLabel(AjoutBorneFontaineUI);
        label_commission->setObjectName(QString::fromUtf8("label_commission"));
        label_commission->setGeometry(QRect(30, 280, 91, 41));
        label_dateNaissance = new QLabel(AjoutBorneFontaineUI);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(30, 180, 131, 41));
        label_titre = new QLabel(AjoutBorneFontaineUI);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(170, 10, 241, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_prenom = new QLabel(AjoutBorneFontaineUI);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(30, 130, 191, 41));
        lineEdit_idVoiePublique_stat = new QLineEdit(AjoutBorneFontaineUI);
        lineEdit_idVoiePublique_stat->setObjectName(QString::fromUtf8("lineEdit_idVoiePublique_stat"));
        lineEdit_idVoiePublique_stat->setGeometry(QRect(220, 130, 261, 31));
        label_quantite = new QLabel(AjoutBorneFontaineUI);
        label_quantite->setObjectName(QString::fromUtf8("label_quantite"));
        label_quantite->setGeometry(QRect(30, 330, 91, 41));
        identifiant_statBox = new QSpinBox(AjoutBorneFontaineUI);
        identifiant_statBox->setObjectName(QString::fromUtf8("identifiant_statBox"));
        identifiant_statBox->setGeometry(QRect(220, 80, 81, 26));
        identifiant_statBox->setMaximum(100000);
        doubleSpinBox_latitude_stat = new QDoubleSpinBox(AjoutBorneFontaineUI);
        doubleSpinBox_latitude_stat->setObjectName(QString::fromUtf8("doubleSpinBox_latitude_stat"));
        doubleSpinBox_latitude_stat->setGeometry(QRect(220, 280, 151, 26));
        doubleSpinBox_latitude_stat->setDecimals(14);
        doubleSpinBox_latitude_stat->setMinimum(-180.000000000000000);
        doubleSpinBox_latitude_stat->setMaximum(180.000000000000000);
        doubleSpinBox_longitude_stat = new QDoubleSpinBox(AjoutBorneFontaineUI);
        doubleSpinBox_longitude_stat->setObjectName(QString::fromUtf8("doubleSpinBox_longitude_stat"));
        doubleSpinBox_longitude_stat->setGeometry(QRect(220, 240, 151, 26));
        doubleSpinBox_longitude_stat->setDecimals(14);
        doubleSpinBox_longitude_stat->setMinimum(-180.000000000000000);
        doubleSpinBox_longitude_stat->setMaximum(180.000000000000000);
        lineEdit_arrondissement_stat = new QLineEdit(AjoutBorneFontaineUI);
        lineEdit_arrondissement_stat->setObjectName(QString::fromUtf8("lineEdit_arrondissement_stat"));
        lineEdit_arrondissement_stat->setGeometry(QRect(220, 380, 261, 31));
        pushButton = new QPushButton(AjoutBorneFontaineUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 450, 181, 28));

        retranslateUi(AjoutBorneFontaineUI);
        QObject::connect(pushButton, SIGNAL(clicked()), AjoutBorneFontaineUI, SLOT(validerBorneFontaine()));

        QMetaObject::connectSlotsByName(AjoutBorneFontaineUI);
    } // setupUi

    void retranslateUi(QDialog *AjoutBorneFontaineUI)
    {
        AjoutBorneFontaineUI->setWindowTitle(QCoreApplication::translate("AjoutBorneFontaineUI", "AjoutBorneFontaineUI", nullptr));
        label_salaire->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Longitude :", nullptr));
        label_nom->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Identifiant :", nullptr));
        label_codeDepartement->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Arrondissement :", nullptr));
        label_commission->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Latitude :", nullptr));
        label_dateNaissance->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Nom topographique :", nullptr));
        label_titre->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "AJout d\342\200\231une borne fontaine", nullptr));
        label_prenom->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Identifiant de la voie publique:", nullptr));
        label_quantite->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Ville :", nullptr));
        pushButton->setText(QCoreApplication::translate("AjoutBorneFontaineUI", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutBorneFontaineUI: public Ui_AjoutBorneFontaineUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTBORNEFONTAINEUI_H

/********************************************************************************
** Form generated from reading UI file 'borneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNEGUI_H
#define UI_BORNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_borneGUI
{
public:
    QAction *actionAjouter_une_borne_fontaine;
    QAction *actionAjouter_une_borne_de_stationnement;
    QAction *actionSupprimer_une_borne_fontaine;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_borne;
    QMenu *menuSupprimer_une_borne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *borneGUI)
    {
        if (borneGUI->objectName().isEmpty())
            borneGUI->setObjectName(QString::fromUtf8("borneGUI"));
        borneGUI->resize(640, 612);
        actionAjouter_une_borne_fontaine = new QAction(borneGUI);
        actionAjouter_une_borne_fontaine->setObjectName(QString::fromUtf8("actionAjouter_une_borne_fontaine"));
        actionAjouter_une_borne_de_stationnement = new QAction(borneGUI);
        actionAjouter_une_borne_de_stationnement->setObjectName(QString::fromUtf8("actionAjouter_une_borne_de_stationnement"));
        actionSupprimer_une_borne_fontaine = new QAction(borneGUI);
        actionSupprimer_une_borne_fontaine->setObjectName(QString::fromUtf8("actionSupprimer_une_borne_fontaine"));
        actionQuitter = new QAction(borneGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(borneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(30, 20, 571, 541));
        borneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(borneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_borne = new QMenu(menuMenu);
        menuAjouter_une_borne->setObjectName(QString::fromUtf8("menuAjouter_une_borne"));
        menuSupprimer_une_borne = new QMenu(menuMenu);
        menuSupprimer_une_borne->setObjectName(QString::fromUtf8("menuSupprimer_une_borne"));
        borneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(borneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        borneGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_une_borne->menuAction());
        menuMenu->addAction(menuSupprimer_une_borne->menuAction());
        menuMenu->addAction(actionQuitter);
        menuAjouter_une_borne->addAction(actionAjouter_une_borne_fontaine);
        menuAjouter_une_borne->addAction(actionAjouter_une_borne_de_stationnement);
        menuSupprimer_une_borne->addAction(actionSupprimer_une_borne_fontaine);

        retranslateUi(borneGUI);
        QObject::connect(actionAjouter_une_borne_fontaine, SIGNAL(triggered()), borneGUI, SLOT(dialogBorneFontaine()));
        QObject::connect(actionAjouter_une_borne_de_stationnement, SIGNAL(triggered()), borneGUI, SLOT(dialogBorneStationnement()));
        QObject::connect(actionSupprimer_une_borne_fontaine, SIGNAL(triggered()), borneGUI, SLOT(dialogSupprimerBorne()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), borneGUI, SLOT(close()));

        QMetaObject::connectSlotsByName(borneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *borneGUI)
    {
        borneGUI->setWindowTitle(QCoreApplication::translate("borneGUI", "borneGUI", nullptr));
        actionAjouter_une_borne_fontaine->setText(QCoreApplication::translate("borneGUI", "Ajouter une borne fontaine", nullptr));
        actionAjouter_une_borne_de_stationnement->setText(QCoreApplication::translate("borneGUI", "Ajouter une borne de stationnement", nullptr));
        actionSupprimer_une_borne_fontaine->setText(QCoreApplication::translate("borneGUI", "Supprimer une borne fontaine", nullptr));
        actionQuitter->setText(QCoreApplication::translate("borneGUI", "Quitter", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("borneGUI", "Menu", nullptr));
        menuAjouter_une_borne->setTitle(QCoreApplication::translate("borneGUI", "Ajouter une borne", nullptr));
        menuSupprimer_une_borne->setTitle(QCoreApplication::translate("borneGUI", "Supprimer une borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borneGUI: public Ui_borneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNEGUI_H

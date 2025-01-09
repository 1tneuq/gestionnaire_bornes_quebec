/*
 * \File: AjoutBorneStationnementUI.cpp
 * \Author: Tristan Gourrand & 1tneuq
 * \brief: Prototype de la classe AjoutBorneStationnementUI.
 * \date Created on 16 avril 2024, 19 h 50
 */

#include "AjoutBorneStationnementUI.h"

AjoutBorneStationnementUI::AjoutBorneStationnementUI ()
{
  widget.setupUi (this);
}

AjoutBorneStationnementUI::~AjoutBorneStationnementUI () { }

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la borne de stationnement par le widget à cet effet.
 * \return Un int qui représente le l'indentifiant de la borne.
 */
unsigned int AjoutBorneStationnementUI::reqIdentifiant() const{
    return widget.identifiantBox -> value () ;
}

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la voie publique de la borne de stationnement par le widget à cet effet.
 * \return Un QString qui représente le l'indentifiant de la voie publique de la borne.
 */
QString AjoutBorneStationnementUI::reqIdentifiantVoiePublique() const {
  return widget.lineEdit_idVoiePublique -> text() ;
}

/**
 * \brief Méthode accesseur récupérant le nom topographqiue de la borne de stationnement par le widget à cet effet.
 * \return Un QString qui représente le nom topographique de la  borne.
 */
QString AjoutBorneStationnementUI::reqNomTopographique() const {
  return widget.lineEdit_nomTopographique -> text() ; 
}

/**
 * \brief Méthode accesseur récupérant la longitude de la borne de stationnement par le widget à cet effet.
 * \return Un double qui représente la longitude de la  borne.
 */
double AjoutBorneStationnementUI::reqLongitude() const {
  return widget.doubleSpinBox_longitude -> value() ;
}

/**
 * \brief Méthode accesseur récupérant la latitude de la borne de stationnement par le widget à cet effet.
 * \return Un double qui représente la latitude de la  borne.
 */
double AjoutBorneStationnementUI::reqLatitude() const {
  return widget.doubleSpinBox_latitude -> value() ;
}

/**
 * \brief Méthode accesseur récupérant le numero de la borne de stationnement par le widget à cet effet.
 * \return Un int qui représente le numero de la  borne de stationnement.
 */
int AjoutBorneStationnementUI::reqNumBorne() const {
  return widget.numBorne -> value() ;
}

/**
 * \brief Méthode accesseur récupérant le cote de la rue de la borne de stationnement par le widget à cet effet.
 * \return Un QString qui représente le cote de la rue de la  borne de stationnement.
 */
QString AjoutBorneStationnementUI::reqCoteRue() const {
  return widget.lineEdit_coteRue -> text() ;
}

/**
 * \brief Méthode validant les invariants de la classe borne de stationnement.
 * \return Le message d'erreur approprie ou accept les entres de l'utilisateur.
 */
void AjoutBorneStationnementUI::validerBorneStationnement() {
  if(reqIdentifiant() == 0) {
      QString message("L'indentifiant ne peut pas etre null.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  if(reqNomTopographique().isEmpty()) {
      QString message("Le nom topographique ne doit pas etre vide.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  if(reqCoteRue().isEmpty()) {
      QString message("Le cote de rue ne doit pas etre vide.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  if(!tp1::validePointCardinal(reqCoteRue().toStdString())) {
      QString message("Le cote de rue doit etre un point cardinal (N, S, E, O)") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  accept() ;
}


/*
 * \File: AjoutBorneFontaineUI.cpp
 * \Author: Tristan Gourrand & 1tneuq
 * \brief: Prototype de la classe AjoutBorneFontaineUI.
 * \date: Created on 16 avril 2024, 10 h 39
 */



#include "AjoutBorneFontaineUI.h"

AjoutBorneFontaineUI::AjoutBorneFontaineUI ()
{
  widget.setupUi (this);
}

AjoutBorneFontaineUI::~AjoutBorneFontaineUI () { }

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la borne fontaine par le widget à cet effet.
 * \return Un int qui représente le l'indentifiant de la borne.
 */
unsigned int AjoutBorneFontaineUI::reqIdentifiant() const{
    return widget.identifiant_statBox -> value () ;
}

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la voie publique de la borne fontaine par le widget à cet effet.
 * \return Un QString qui représente le l'indentifiant de la voie publique de la borne.
 */
QString AjoutBorneFontaineUI::reqIdentifiantVoiePublique() const {
  return widget.lineEdit_idVoiePublique_stat -> text() ;
}

/**
 * \brief Méthode accesseur récupérant le nom topographqiue de la borne fontaine par le widget à cet effet.
 * \return Un QString qui représente le nom topographique de la  borne.
 */
QString AjoutBorneFontaineUI::reqNomTopographique() const {
  return widget.lineEdit_nomTopographique_stat -> text() ; 
}

/**
 * \brief Méthode accesseur récupérant la longitude de la borne fontaine par le widget à cet effet.
 * \return Un double qui représente la longitude de la  borne.
 */
double AjoutBorneFontaineUI::reqLongitude() const {
  return widget.doubleSpinBox_longitude_stat -> value() ;
}

/**
 * \brief Méthode accesseur récupérant la latitude de la borne fontaine par le widget à cet effet.
 * \return Un double qui représente la latitude de la  borne.
 */
double AjoutBorneFontaineUI::reqLatitude() const {
  return widget.doubleSpinBox_latitude_stat -> value() ;
}

/**
 * \brief Méthode accesseur récupérant la ville de la borne fontaine par le widget à cet effet.
 * \return Un QString qui représente ls ville de la  borne fontaine.
 */
QString AjoutBorneFontaineUI::reqVille() const {
  return widget.lineEdit_ville_stat -> text() ;
}

/**
 * \brief Méthode accesseur récupérant l'arrondissement de la borne fontaine par le widget à cet effet.
 * \return Un QString qui représente l'arrondissement de la  borne fontaine.
 */
QString AjoutBorneFontaineUI::reqArrondissement() const {
  return widget.lineEdit_arrondissement_stat -> text() ;
}

/**
 * \brief Méthode validant les invariants de la classe borne fontaine.
 * \return Le message d'erreur approprie ou accept les entres de l'utilisateur.
 */
void AjoutBorneFontaineUI::validerBorneFontaine() {
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
  if(reqVille().isEmpty()) {
      QString message("La ville ne doit pas etre vide.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  if(reqVille() == "Québec" && reqArrondissement().isEmpty()) {
      QString message("L'arrondissement ne peut pas etre vide si la ville est quebec.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  
  accept() ;
}
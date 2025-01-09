/*
 * \File:   borneGUI.cpp
 * \Author: Tristan Gourrand & 1tneuq
 * \brief: Prototype de la classe borneGUI.
 * \date: Created on 15 avril 2024, 10 h 37
 */

#include "borneGUI.h"


borneGUI::borneGUI (borneQuebec::RegistreBorne &p_registreBorne) : m_registreBorne(p_registreBorne)
{
  widget.setupUi (this);
}

borneGUI::~borneGUI () { }

/**
 * \brief Cette methode ouvre l'interface utilisateur pour l'ajout d'une borne fontaine.
 * \return L'ajout d'une borne fontaine dans le registre de borne.
 */
void borneGUI::dialogBorneFontaine() {
  AjoutBorneFontaineUI borneFontaineUI ;
  if(borneFontaineUI.exec()){
      std::string nomTopogrpahique = borneFontaineUI.reqNomTopographique().toStdString() ;
      borneQuebec::BorneFontaine borneFontaine(borneFontaineUI.reqIdentifiant (), 
                                               borneFontaineUI.reqIdentifiantVoiePublique().toStdString(),
                                               nomTopogrpahique,
                                               borneFontaineUI.reqLongitude(),
                                               borneFontaineUI.reqLatitude(),
                                               borneFontaineUI.reqVille().toStdString(),
                                               borneFontaineUI.reqArrondissement().toStdString()) ;
      try {
      m_registreBorne.ajouteBorne (borneFontaine) ;
      }catch (BorneDejaPresenteException& erreur) {
            QString message = erreur.what ();
            QMessageBox::information (this,"ERREUR",message);
      }
      widget.affichage->setText (m_registreBorne.reqRegistreBorneFormate().c_str()) ;
    }
}

/**
 * \brief Cette methode ouvre l'interface utilisateur pour l'ajout d'une borne de stationnement.
 * \return L'ajout d'une borne de stationnement dans le registre de borne.
 */
void borneGUI::dialogBorneStationnement() {
  AjoutBorneStationnementUI borneStationnementUI ;
  if(borneStationnementUI.exec()){
      std::string nomTopogrpahique = borneStationnementUI.reqNomTopographique().toStdString() ;
      borneQuebec::BorneStationnement borneStationnement(borneStationnementUI.reqIdentifiant (), 
                                               borneStationnementUI.reqIdentifiantVoiePublique().toStdString(),
                                               nomTopogrpahique,
                                               borneStationnementUI.reqLongitude(),
                                               borneStationnementUI.reqLatitude(),
                                               borneStationnementUI.reqNumBorne(),
                                               borneStationnementUI.reqCoteRue().toStdString()) ;
      try {
      m_registreBorne.ajouteBorne(borneStationnement) ;
      }catch (BorneDejaPresenteException& erreur) {
            QString message = erreur.what ();
            QMessageBox::information (this,"ERREUR",message);
      }
      widget.affichage->setText (m_registreBorne.reqRegistreBorneFormate().c_str()) ;
    }
}

/**
 * \brief Cette methode ouvre l'interface utilisateur pour la suppression d'une borne.
 * \return La suppression d'une borne dans le registre de borne.
 */
void borneGUI::dialogSupprimerBorne() {
  SupprimerBorneUI supprimerBorneUI ;
  if(supprimerBorneUI.exec()){
      try {
          m_registreBorne.supprimeBorne(supprimerBorneUI.reqIdentifiant()) ;
      }catch (BorneAbsenteException& erreur) {
            QString message = erreur.what ();
            QMessageBox::information (this,"ERREUR",message);
      }
      widget.affichage->setText (m_registreBorne.reqRegistreBorneFormate().c_str()) ;
    }
}



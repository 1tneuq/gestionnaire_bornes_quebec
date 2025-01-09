
/*
 * \File: SupprimerBorneUI.cpp
 * \Author: Tristan Gourrand & 1tneuq
 * \brief: Prototype de la classe SupprimerBorneUI.
 * \date Created on 18 avril 2024, 20 h 14
 */

#include "SupprimerBorneUI.h"

SupprimerBorneUI::SupprimerBorneUI ()
{
  widget.setupUi (this);
}

SupprimerBorneUI::~SupprimerBorneUI () { }

/**
 * \brief Méthode accesseur récupérant l'indentifiant pour la suppression d'une borne par le widget à cet effet.
 * \return Un unsigned int qui représente le l'indentifiant de la borne.
 */
unsigned int SupprimerBorneUI::reqIdentifiant() const{
    return widget.supprimerBorne -> value () ;
}

/**
 * \brief Méthode validant que l'indentifiant est non null.
 * \return Le message d'erreur approprie ou accept l'entre de l'utilisateur.
 */
void SupprimerBorneUI::validerSupprimerBorne() {
  if(reqIdentifiant() == 0 ) {
      QString message("L'identifiant ne doit pas etre null.") ;
      QMessageBox::information(this, "Erreur", message) ;
      return ;
    }
  accept() ;
}

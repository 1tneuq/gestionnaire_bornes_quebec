/* 
 * \File:   SupprimerBorneUI.h
 * \Author: Tristan Gourrand & Quentin Lacombe
 * \brief Prototype de la classe SupprimerBorneUI.
 * \date Created on 18 avril 2024, 20 h 14
 */

#ifndef _SUPPRIMERBORNEUI_H
#define _SUPPRIMERBORNEUI_H

#include "ui_SupprimerBorneUI.h"
#include "borneGUI.h"

/**
 * \class SupprimerBorneUI
 * \brief Classe SupprimerBorneUI dérivée de la classe QDialog
 */
class SupprimerBorneUI : public QDialog
{
  Q_OBJECT
public:
  SupprimerBorneUI ();
  virtual ~SupprimerBorneUI ();
  unsigned int reqIdentifiant() const ;
  
  private slots :
    void validerSupprimerBorne() ;
  
private:
  Ui::SupprimerBorneUI widget;
};

#endif /* _SUPPRIMERBORNEUI_H */

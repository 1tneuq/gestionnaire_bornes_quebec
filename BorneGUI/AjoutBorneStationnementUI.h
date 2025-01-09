/* 
 * \File: AjoutBorneStationnementUI.h
 * \brief Prototype de la classe AjoutBorneStationnementUI
 * \Author: Tristan Gourrand & Quentin Lacombe
 * \date Created on 16 avril 2024, 19 h 50
 */

#ifndef _AJOUTBORNESTATIONNEMENTUI_H
#define _AJOUTBORNESTATIONNEMENTUI_H

#include "ui_AjoutBorneStationnementUI.h"
#include "borneGUI.h"

/**
 * \class AjoutBorneStationnementUI
 * \brief Classe AjoutBorneStationnementUI dérivée de la classe QDialog
 */
class AjoutBorneStationnementUI : public QDialog
{
  Q_OBJECT
public:
  AjoutBorneStationnementUI ();
  virtual ~AjoutBorneStationnementUI ();
  unsigned int reqIdentifiant() const;
  QString reqIdentifiantVoiePublique() const;
  QString reqNomTopographique() const;
  double reqLongitude() const;
  double reqLatitude() const;
  int reqNumBorne() const;
  QString reqCoteRue() const;
  
  private slots :
    void validerBorneStationnement() ;
  
private:
  Ui::AjoutBorneStationnementUI widget;
};

#endif /* _AJOUTBORNESTATIONNEMENTUI_H */

/* 
 * \File: AjoutBorneFontaineUI.h
 * \brief Prototype de la classe AjoutBorneFontaineUI
 * \Author: Tristan Gourrand & Quentin Lacombbe
 * \date Created on 16 avril 2024, 10 h 39
 */

#ifndef _AJOUTBORNEFONTAINEUI_H
#define _AJOUTBORNEFONTAINEUI_H

#include "ui_AjoutBorneFontaineUI.h"
#include "borneGUI.h"

/**
 * \class AjoutBorneFontaineUI
 * \brief Classe AjoutBorneFontaineUI dérivée de la classe QDialog
 */
class AjoutBorneFontaineUI : public QDialog
{
  Q_OBJECT
public:
  AjoutBorneFontaineUI ();
  virtual ~AjoutBorneFontaineUI ();
  unsigned int reqIdentifiant() const;
  QString reqIdentifiantVoiePublique() const;
  QString reqNomTopographique() const;
  double reqLongitude() const;
  double reqLatitude() const;
  QString reqVille() const;
  QString reqArrondissement() const;
  
 private slots :
   void validerBorneFontaine() ; 
  
private:
  Ui::AjoutBorneFontaineUI widget;
};

#endif /* _AJOUTBORNEFONTAINEUI_H */

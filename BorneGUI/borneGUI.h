/* 
 * \File: borneGUI.h
 * \Author: Tristan Gourrand & Quentin Lacombe
 * \brief Prototype de la classe borneGUI.
 * \date Created on 15 avril 2024, 10 h 37
 */

#ifndef _BORNEGUI_H
#define _BORNEGUI_H

#include "ui_borneGUI.h"
#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "AjoutBorneFontaineUI.h"
#include "AjoutBorneStationnementUI.h"
#include "SupprimerBorneUI.h"
#include "validationFormat.h"
#include <QMessageBox>


/**
 * \class borneGUI
 * \brief Classe borneGUI dérivée de la classe QMainWindow
 */
class borneGUI : public QMainWindow
{
  Q_OBJECT
public:
  borneGUI (borneQuebec::RegistreBorne& p_registreBorne);
  virtual ~borneGUI ();
  
private slots :
  void dialogBorneFontaine() ;
  void dialogBorneStationnement() ;
  void dialogSupprimerBorne() ;
    
private:
  Ui::borneGUI widget;
  borneQuebec::RegistreBorne &m_registreBorne ;
};

#endif /* _BORNEGUI_H */

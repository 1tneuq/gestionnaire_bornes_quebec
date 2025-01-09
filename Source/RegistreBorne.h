/**
 * \file RegistreBorne.h
 * \brief Prototype de la classe RegistreBorne
 * \author Tristan Gourrand & Quentin Lacombe
 * \date Created on 29 mars 2024, 14 h 37
*/

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H

#include "Borne.h"
#include <vector>
#include "BorneException.h"
#include <algorithm>

namespace borneQuebec {
/**
 * \class RegistreBorne
 * \brief Classe RegistreBorne composée de Borne
 */
class RegistreBorne {
public :
  RegistreBorne(std::string p_nomRegistreBorne) ;
  RegistreBorne(const RegistreBorne& p_registreBorne) ;
  virtual ~RegistreBorne () ;
  RegistreBorne& operator= (const RegistreBorne& p_registreBorne) ;
  std::string reqNomRegistreBorne() const ;
  int reqNombreBorneEnregistre() const ;
  void ajouteBorne(const Borne& p_borne);
  void supprimeBorne(int p_identifiant);
  std::string reqRegistreBorneFormate () const ;
   
private :
  std::string m_nomRegistreBorne ;
  std::vector<std::unique_ptr<Borne>> m_bornes;
  void verifieInvariant () const ;
};
} // fin namespace borneQuebec

#endif /* REGISTREBORNE_H */


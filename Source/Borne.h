/*
 * \file Borne.h
 * \brief Prototype de la classe Borne
 * \author Tristan Gourrand
 * \date Created on 6 mars 2024, 13 h 39
*/

#ifndef BORNE_H
#define BORNE_H

#include <string>
#include <iostream>
#include <sstream>
#include "ContratException.h"
#include <cctype>
#include <memory>
namespace borneQuebec {
/**
 * \class Borne
 * \brief Classe de base abstraite Borne
 */
class Borne {
public :
  Borne(const unsigned int p_identifiant, const std::string& p_identifiantVoiePublique, std::string& p_nomTopographique, const double p_longitude, const double p_latitude) ;
  virtual ~Borne () ;
  int reqIdentifiant () const ;
  std::string reqIdentifiantVoiePublique() const ;
  std::string reqNomTopographique() const ;
  double reqLongitude() const ;
  double reqLatitude() const ;
  virtual std::string reqBorneFormate() const=0 ;
  virtual std::unique_ptr<Borne> clone() const=0 ;
  
  void asgNomTopographique(const std::string& p_nomTopographique) ;
  
  bool operator==(const Borne & p_borne) const;
  Borne& operator= (const Borne& p_borne) ;
  
  bool contientNumero(const std::string& p_numero) const ; 

private :
  unsigned int m_identifiant ;
  std::string m_identifiantVoiePublique ;
  std::string m_nomTopographique ;
  double m_longitude ;
  double m_latitude ;
  void verifieInvariant () const ;
  
};
} //Namespace borneQuebec

#endif /* BORNE_H */


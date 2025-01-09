/*
 * \file BorneFontaine.h
 * \brief Prototype de la classe Borne fontaine
 * \author Tristan Gourrand
 * \date Created on 7 mars 2024, 15 h 32
*/

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H
#include"Borne.h"

namespace borneQuebec {
  /**
 * \class BorneFontaine
 * \brief Classe BorneFontaine dérivée de la classe Borne.
 */
class BorneFontaine : public Borne {
  
public :
  BorneFontaine(const unsigned int p_identifiant,
                const std::string& p_identifiantVoiePublique,
                std::string& p_nomTopographique,
                const double p_longitude, const double p_latitude, 
                const std::string& p_ville,
                const std::string& p_arrondissement);
  BorneFontaine(const BorneFontaine& p_BorneFontaine) ;
  virtual ~BorneFontaine() ;
  std::string reqVille() const ;
  std::string reqArrondissement() const ;
  virtual std::string reqBorneFormate() const;
  virtual std::unique_ptr<Borne> clone() const;
  bool operator==(const BorneFontaine & p_borneFontaine) const;
  BorneFontaine& operator= (const BorneFontaine& p_borneFontaine);
  
private :
  std::string m_ville ;
  std::string m_arrondissement ;
  
  void verifieInvariant() const ;

};
} // Namespace borneQuebec
#endif /* BORNEFONTAINE_H */



/*
 * \file BorneStationnement.h
 * \brief Prototype de la classe Borne stationnement
 * \author Tristan Gourrand
 * \date Créé le 16 mars 2024, 16 h 59
*/

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H
#include "Borne.h"
#include "validationFormat.h"

namespace borneQuebec {
   /**
 * \class BorneStationnement
 * \brief Classe BorneStationnement dérivée de la classe Borne.
 */
class BorneStationnement : public Borne {
  public :
    BorneStationnement(const unsigned int p_identifiant, const std::string& p_identifiantVoiePublique, 
                       std::string& p_nomTopographique, 
                       const double p_longitude, const double p_latitude,
                       const int& p_numBorne, const std::string& p_coteRue) ;
    BorneStationnement(const BorneStationnement &p_borneStationnement);
    ~BorneStationnement() ;
    int reqNumBorne() const ;
    virtual std::string reqBorneFormate() const;
    std::string reqCoteRue() const ;
    virtual std::unique_ptr<Borne> clone() const;
    bool operator==(const BorneStationnement& p_borneStationnement) const; 
    BorneStationnement& operator= (const BorneStationnement& p_borneStationnement);
    
    int compterNombreChiffre(int p_numero) const;
    
  private :
    int m_numBorne; 
    std::string m_coteRue;
    void verifieInvariant() const ;
      
            
};
} //borneQuebec tp2



#endif /* BORNESTATIONNEMENT_H */


/**
 * \file BorneFontaine.cpp
 * \brief Implementation de la classe BorneFontaine
 * \author Tristan Gourrand
 * \date 7/3/2024
 */

#include "BorneFontaine.h"
using namespace std ;

/**
 *\brief Constructeur avec paramètres. On construit un objet Borne fontaine à partie de valeurs passées en paramètres. Les 
    attributs sont assignés seulement si la borne fontaine est considérée comme valide. Autrement, une erreur d'assertion
    est générée.
 *\param[in] p_identifiant Un entier non signé qui represente l'identifiant de la borne.
 *\param[in] p_identifiantVoiePublique Un string qui represente l’identifiant de la voie publique sur laquelle la borne est située
 *\param[in] p_nomTopographic Un string qui represente le nom topographique de centre de chaussée.
 *\param[in] p_longitude Un double qui represente la longitude de l'objet borne.
 *\param[in] p_lattitude Un double qui représente la lattitude de l'objet borne.
 *\param[in] p_ville Un string qui indique la ville ou la borne fontaine se trouve.
 *\param[in] p_arrondissement Un string qui indique l'arrondissement ou la borne fontaine se trouve.
 *\pre L'attribut m_arrondissement ne doit pas etre vide si la valeur de l'atribut m_ville est Québec.
 *\post L'objet construit a été initialié à partir des valeurs passés en paramètres.
 *\return Un objet borne fontaine
 */
namespace borneQuebec {
BorneFontaine::BorneFontaine(const unsigned int p_identifiant, 
                             const string& p_identifiantVoiePublique,
                             string& p_nomTopographique, 
                             const double p_longitude, const double p_latitude, 
                             const string& p_ville, const string& p_arrondissement) : 
Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), 
        m_ville(p_ville), m_arrondissement(p_arrondissement) {
  if (p_ville == "Québec") {
      PRECONDITION(!p_arrondissement.empty()) ;
    }
      POSTCONDITION(m_ville == p_ville) ;
      POSTCONDITION(m_arrondissement == p_arrondissement) ;
      INVARIANTS() ; 
}

/**
 * \brief constructeur copie de borne fontaine. Il fait une copie en profondeur
 * \param [in] p_BorneFontaine la borne fontaine dont on veut construire une copie.
 */
BorneFontaine::BorneFontaine(const BorneFontaine& p_BorneFontaine) : 
Borne(p_BorneFontaine), m_ville(p_BorneFontaine.m_ville), m_arrondissement(p_BorneFontaine.m_arrondissement){
}

/**
 * \brief destructeur de la classe Borne Fontaine.
 */
BorneFontaine::~BorneFontaine ()
{
  cout << "Destructeur appelé" << endl ;
}

/*
 * \brief Permet de faire une copie allouée sur le monceau de l'objet courant
 */
unique_ptr<Borne> BorneFontaine::clone() const {
  return unique_ptr < Borne > (new BorneFontaine (*this));// Appel du constructeur copie
}

/**
 * \brief surcharge de l'opérateur == pour permettre de vérifier les équalités d'un objet borne fontaine.
 * \param[in] p_bornefontaine à comparer à la borne fontaine courante.
 * \return un booléen indiquant si les deux bornes sont égales ou non.
 */
bool BorneFontaine::operator==(const BorneFontaine & p_borneFontaine) const {
    return Borne::operator==(p_borneFontaine) &&
           m_ville == p_borneFontaine.m_ville &&
           m_arrondissement == p_borneFontaine.m_arrondissement;
}
/**
 *\brief L'opérateur est utilisé pour faire une copie en profondeur
 *\param[in] p_borneFontaine la borne fontaine à assigner.
 *\return l'objet courant pour les appels en cascade
 */
BorneFontaine& BorneFontaine::operator= (const BorneFontaine& p_borneFontaine) {
  if (!(this == &p_borneFontaine)) {
    Borne::operator=(p_borneFontaine) ;
    m_ville = p_borneFontaine.m_ville;
    m_arrondissement = p_borneFontaine.m_arrondissement;
    }
  return *this ;
}

/**
 * \brief Retourne la ville de la borne fontaine.
 * \return Un string qui représente la ville de la borne fontaine.
 */
string BorneFontaine::reqVille() const {
  return m_ville ;
}

/**
 * \brief Retourne l'arrondissement de la borne fontaine.
 * \return Un string qui représente l'arrondissement de la borne fontaine.
 */
string BorneFontaine::reqArrondissement() const {
  return m_arrondissement ;
}

 string BorneFontaine::reqBorneFormate() const {
  ostringstream oss ;
  oss << "Borne-fontaine" << endl 
      << "----------------------------------------------" << endl
      << Borne::reqBorneFormate () << endl
      << "Ville                   : " << m_ville << endl
      << "Arrondissement          : " << m_arrondissement << endl ;
  return oss.str() ;
}
/**
 * \brief  Vérifier les invariants de la classe BorneFontaine. Les invariants de cette classe s'assure que la borne fontaine est valide.
 */
void BorneFontaine::verifieInvariant() const {
  if (m_ville == "Québec") {
      INVARIANT(!m_arrondissement.empty()) ;
    }

}
} // Namespace borneQuebec
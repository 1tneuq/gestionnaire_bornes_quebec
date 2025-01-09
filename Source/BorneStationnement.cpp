/**
 * \file BorneStationnement.cpp
 * \brief Implementation de la classe BorneStationnement
 * \author 1tneuq
 * \date 16/3/2024
 */

#include "BorneStationnement.h"
using namespace std ;

/**
 *\brief Constructeur avec paramètres. On construit un objet Borne de stationnement à partie de valeurs passées en paramètres. Les 
    attributs sont assignés seulement si la borne de stationnement est considérée comme valide. Autrement, une erreur d'assertion
    est générée.
 *\param[in] p_identifiant Un entier non signé qui represente l'identifiant de la borne.
 *\param[in] p_identifiantVoiePublique Un string qui represente l’identifiant de la voie publique sur laquelle la borne est située
 *\param[in] p_nomTopographic Un string qui represente le nom topographique de centre de chaussée.
 *\param[in] p_longitude Un double qui represente la longitude de l'objet borne.
 *\param[in] p_lattitude Un double qui représente la lattitude de l'objet borne.
 *\param[in] p_numBorne Un int qui indique le numéro de la borne.
 *\param[in] p_coteRue Un string qui indique le côté de la rue.
 *\pre L'attribut m_numBorne doit être composé de 1 à 4 chiffres.
 *\pre La valeur valide d'un point cardinal sont N, S, E, O, « chaine vide ».
 *\post L'objet construit a été initialié à partir des valeurs passés en paramètres.
 *\return Un objet borne de stationnement
 */
namespace borneQuebec {
BorneStationnement::BorneStationnement(const unsigned int p_identifiant,
                                       const string& p_identifiantVoiePublique,
                                       string& p_nomTopographique, 
                                       const double p_longitude,const double p_latitude, 
                                       const int& p_numBorne, const string& p_coteRue) : 
Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude), 
        m_numBorne(p_numBorne), m_coteRue(p_coteRue) {
  PRECONDITION(compterNombreChiffre(p_numBorne) >= 1 && compterNombreChiffre(p_numBorne) <= 4) ;
  PRECONDITION(tp1::validePointCardinal (p_coteRue)) ;
  POSTCONDITION(m_numBorne == p_numBorne) ;
  POSTCONDITION(m_coteRue == p_coteRue) ;
  INVARIANTS() ;
}

/**
 * \brief constructeur copie de borne de stationnement. Il fait une copie en profondeur
 * \param [in] p_BorneStationnement la borne stationnement dont on veut construire une copie.
 */
BorneStationnement::BorneStationnement(const BorneStationnement &p_borneStationnement) :
Borne(p_borneStationnement), m_numBorne(p_borneStationnement.m_numBorne),
        m_coteRue(p_borneStationnement.m_coteRue) {}

/**
 * \brief destructeur de la classe Borne Fontaine.
 */
BorneStationnement::~BorneStationnement ()
{
  cout << "Destructeur appelé" << endl ;
}

/*
 * \brief Permet de faire une copie allouée sur le monceau de l'objet courant
 */
unique_ptr<Borne> BorneStationnement::clone() const {
  return unique_ptr < Borne > (new BorneStationnement (*this));
}

/**
 * \brief surcharge de l'opérateur == pour permettre de vérifier les équalités d'un objet borne stationnement.
 * \param[in] p_borneStationnement à comparer à la borne de stationnement courante.
 * \return un booléen indiquant si les deux bornes sont égales ou non.
 */
bool BorneStationnement::operator==(const BorneStationnement& p_borneStationnement) const {
  return Borne::operator==(p_borneStationnement) &&
           m_numBorne == p_borneStationnement.m_numBorne &&
           m_coteRue == p_borneStationnement.m_coteRue;
}

/**
 *\brief L'opérateur est utilisé pour faire une copie en profondeur
 *\param[in] p_borneStationnement la borne de stationnement à assigner.
 *\return l'objet courant pour les appels en cascade
 */
BorneStationnement& BorneStationnement::operator= (const BorneStationnement& p_borneStationnement) {
  if (!(this == &p_borneStationnement)) {
    Borne::operator=(p_borneStationnement) ;
    m_numBorne = p_borneStationnement.m_numBorne;
    m_coteRue = p_borneStationnement.m_coteRue;
    }
  return *this ;
}

/**
 * \brief Retourne le numéro de la borne de stationnement.
 * \return Un integer qui représente le numéro de la borne de stationnement.
 */
int BorneStationnement::reqNumBorne() const {
  return m_numBorne ;
}

/**
 * \brief Retourne le côté de la rue de la borne de stationnement.
 * \return Un string qui représente la rue de la borne de stationnement.
 */
string BorneStationnement::reqCoteRue() const {
  return m_coteRue ;
}

std::string BorneStationnement::reqBorneFormate() const{
  ostringstream oss ;
  oss << "Borne de stationnement" << endl 
      << "----------------------------------------------" << endl
      << Borne::reqBorneFormate () << endl
      << "Numero de la rue        : " << m_numBorne << endl
      << "Cote de la rue          : " << m_coteRue ;
  return oss.str() ;
}

/**
 * \brief Retourne le nombre de chiffre dans un nombre.
 * \return Un integer qui représente le nombre de chiffre dans un nombre.
 */
int BorneStationnement::compterNombreChiffre(int p_numero) const {
  string numeroString = to_string(p_numero) ;
  return numeroString.length() ;         
}

/**
 * \brief  Vérifier les invariants de la classe BorneStationnement. Les invariants de cette classe s'assure que la borne de stationnement est valide.
 */
void BorneStationnement::verifieInvariant() const {
  INVARIANT(compterNombreChiffre(m_numBorne) >= 1 && compterNombreChiffre(m_numBorne) <= 4) ;
  INVARIANT(tp1::validePointCardinal (m_coteRue)) ;
}
  
} //namespace borneQuebec

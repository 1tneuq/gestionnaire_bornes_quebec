/**
 * \file Borne.cpp
 * \brief Implementation de la classe Borne
 * \author Tristan Gourrand
 * \date 6/3/2024
 */

#include "Borne.h"

using namespace std ;
namespace borneQuebec {
/**
 * \brief Constructeur avec paramètres. On construit un objet Borne à partie de valeurs passées en paramètres. Les 
    attributs sont assignés seulement si la borne est considérée comme valide. Autrement, une erreur d'assertion
    est générée.
 * \param[in] p_identifiant Un entier non signé qui represente l'identifiant de la borne.
 * \param[in] p_nomTopographic Un string qui represente le nom topographique de centre de chaussée.
 * \param[in] p_longitude Un double qui represente la longitude de l'objet borne.
 * \param[in] p_lattitude Un double qui représente la lattitude de l'objet borne.
 * \param[in] p_identifiantVoiePublique Un string qui represente l’identifiant de la voie publique sur laquelle la borne est située
 * \pre m_nomTopographique ne doit pas être vide.
 * \pre Si m__identifiantVoiePublique est non vide, l'attribut doit contenir un numéro.
 * \post L'objet construit a été initialié à partir des valeurs passés en paramètres.
 * \return Un objet borne
 */
Borne::Borne (const unsigned int p_identifiant, const string& p_identifiantVoiePublique, string& p_nomTopographique, const double p_longitude, const double p_latitude) :
  m_identifiant(p_identifiant), m_identifiantVoiePublique (p_identifiantVoiePublique), m_nomTopographique (p_nomTopographique), m_longitude (p_longitude), m_latitude (p_latitude) {
  
  PRECONDITION(!p_nomTopographique.empty());
  PRECONDITION(contientNumero(p_identifiantVoiePublique)) ;
  POSTCONDITION(m_identifiant == p_identifiant) ;
  POSTCONDITION(m_identifiantVoiePublique == p_identifiantVoiePublique) ;
  POSTCONDITION(m_nomTopographique == p_nomTopographique) ;
  POSTCONDITION(m_longitude == p_longitude) ;
  POSTCONDITION(m_latitude == p_latitude) ;
  INVARIANTS() ;
}

/**
 * \brief destructeur de la classe Borne.
 */
Borne::~Borne ()
{
  cout << "Destructeur appelé" << endl ;
}

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la borne.
 * \return Un entier qui représente l'indentifiant de la borne.
 */
int Borne::reqIdentifiant() const {
  return m_identifiant ;
}

/**
 * \brief Méthode accesseur récupérant l'indentifiant de la voie publique de la borne.
 * \return Un string qui représente le l'indentifiant de la voie publique de la borne.
 */
string Borne::reqIdentifiantVoiePublique() const {
  return m_identifiantVoiePublique ;
}

/**
 * \brief Méthode accesseur récupérant le nom topographique de la borne.
 * \return Un string qui représente le nom topographique de la borne.
 */
string Borne::reqNomTopographique() const {
  return m_nomTopographique ;
}

/**
 * \brief Méthode accesseur récupérant la longitude de la borne.
 * \return Un double  qui représente la longitude de la borne.
 */
double Borne::reqLongitude() const {
  return m_longitude ;
}

/**
 * \brief Méthode accesseur récupérant la latitude de la borne.
 * \return Un double qui représente la latitude de la borne.
 */
double Borne::reqLatitude() const {
  return m_latitude ;
}

/**
 * \brief Méthode accesseur récupérant une borne formatée dans une chaîne de caracères.
 * \return la borne formatée dans une chaîne de caractères.
 */
string Borne::reqBorneFormate() const {
  ostringstream oss ;
  oss << "Identifiant de la borne : " << m_identifiant << endl 
      << "Voie public             : " << m_identifiantVoiePublique << endl 
      << "Nom topographique       : " << m_nomTopographique << endl 
      << "Latitude                : " << m_latitude << endl 
      << "Longitude               : " << m_longitude ;
  return oss.str() ;    
}

/**
 * \brief Assigne un nom topographique à l'objet courant.
 * \param[in] p_nomTopographique est un string qui représente le nom topographique d'une borne.
 * \pre p_nomTopographique ne doit pas être vide.
 * \post p_nomTopographique prend la valeur du paramètre reçu en entrée.
 */
void Borne::asgNomTopographique(const string& p_nomTopographique) {
  PRECONDITION(!p_nomTopographique.empty());
  m_nomTopographique = p_nomTopographique ;
  POSTCONDITION(m_nomTopographique == p_nomTopographique) ;
  INVARIANTS() ;
}

/**
 * \brief surcharge de l'opérateur == pour permettre de vérifier les équalités d'un objet borne.
 * \param[in] p_borne à comparer à la borne courante.
 * \return un booléen indiquant si les deux bornes sont égales ou non.
 */
bool Borne::operator==(const Borne & p_borne) const{
  return m_identifiant == p_borne.m_identifiant && m_identifiantVoiePublique == p_borne.m_identifiantVoiePublique
          && m_nomTopographique == p_borne.m_nomTopographique && m_longitude == p_borne.m_longitude
          && m_latitude == p_borne.m_latitude ;
}

/**
 *\brief L'opérateur est utilisé pour faire une copie en profondeur
 *\param[in] p_borne la borne à assigner.
 *\return l'objet courant pour les appels en cascade
 */
Borne& Borne::operator=(const Borne& p_borne) {
  if (!(this == &p_borne)) {
      m_identifiant = p_borne.m_identifiant;
      m_identifiantVoiePublique = p_borne.m_identifiantVoiePublique ;
      m_nomTopographique = p_borne.m_nomTopographique ;
      m_longitude = p_borne.m_longitude ;
      m_latitude = p_borne.m_latitude ;  
    }
  return *this ;
}

/**
 * \brief  Vérifier les invariants de la classe Borne. Les invariants de cette classe s'assure que la borne est valide.
 */
void Borne::verifieInvariant() const {
  INVARIANT(!m_nomTopographique.empty());
  INVARIANT(contientNumero(m_identifiantVoiePublique)) ;
}

/**
 * \brief Method qui determine si un string contient que des chiffres. 
 * \param[in] p_string La chaine de caracteres a verifier.
 * \return un booléen indiquant si la chaine de caractere contient que des chiffres.
 */
bool Borne::contientNumero(const string& p_numero) const {
  bool resultat = true ;
  for (char caractere : p_numero) {
      if (!isdigit(caractere)) {
          resultat = false ;
          break ;
        }
    }
  return resultat ;
}
}//Namespace borneQuebec
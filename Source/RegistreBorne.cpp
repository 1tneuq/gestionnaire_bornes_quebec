/**
 * \file RegistreBorne.cpp
 * \brief Implementation de la classe RegistreBorne
 * \author Tristan Gourrand & 1tneuq
 * \date 29/3/2024
 */
#include "RegistreBorne.h"

using namespace std ;
namespace borneQuebec {
/**
 * \brief Constructeur avec paramètres. On construit un objet RegistreBorne à partie de valeurs passées en paramètres. Les 
    attributs sont assignés seulement si le RegistreBorne est considérée comme valide. Autrement, une erreur d'assertion
    est générée.

 * \param[in] p_nomRegistreBorne Un string qui represente le nom du registre de bornes.
 * \pre p_nomRegistreBorne ne doit pas être vide.
 * \post L'objet construit a été initialié à partir des valeurs passés en paramètres.
 * \return Un objet registre borne.
 */
  
  RegistreBorne::RegistreBorne(string p_nomRegistreBorne) : m_nomRegistreBorne (p_nomRegistreBorne)
  {
    PRECONDITION (!p_nomRegistreBorne.empty()) ;
    POSTCONDITION (m_nomRegistreBorne == p_nomRegistreBorne) ;
    INVARIANTS ();
    
  }
  
  /**
 * \brief constructeur copie de RegistreBorne, c'est une forme canonique de coplien. Il faut faire une copie en profondeur
 * \param [in] p_registreBorne le registre de borne auquel on veut construire une copie.
 */
 RegistreBorne::RegistreBorne(const RegistreBorne& p_registreBorne) : 
 m_nomRegistreBorne(p_registreBorne.m_nomRegistreBorne){
   for (const auto & element : p_registreBorne.m_bornes) {
       m_bornes.push_back((*element).clone());
     }
 }
 
 /**
 * \brief destructeur de la classe registre borne.
 */
RegistreBorne::~RegistreBorne ()
{
  cout << "Destructeur appelé" << endl ;
}
 
 /**
 *\brief L'opérateur est utilisé pour faire une copie en profondeur
 *\param[in] p_RegistreBorne la borne fontaine à assigner.
 *\return l'objet courant pour les appels en cascade
 */
 RegistreBorne& RegistreBorne::operator= (const RegistreBorne& p_registreBorne) {
  if (!(this == &p_registreBorne)) {
    m_nomRegistreBorne = p_registreBorne.m_nomRegistreBorne;
    m_bornes.clear() ;
    for (const auto & element : p_registreBorne.m_bornes) {
       m_bornes.push_back((*element).clone());
     }
    }
  return *this ;
}
  
  /**
 * \brief Méthode accesseur récupérant le nom du registre de borne.
 * \return Un string qui représente le nom du registre de borne.
 */
  std::string RegistreBorne::reqNomRegistreBorne() const {
    return m_nomRegistreBorne ;
  }
  
  /*
   *\brief Ajoute une borne au vecteur de bornes la classe RegistreBorne 
   * \param[in] p_borne une borne.
   */
  void RegistreBorne::ajouteBorne(const Borne& p_borne) {
     auto iter = find_if(m_bornes.begin(), m_bornes.end(), [&p_borne](const unique_ptr<Borne>& elem) {
        return elem->reqIdentifiant() == p_borne.reqIdentifiant();
    });
    if (iter != m_bornes.end()) {
        throw BorneDejaPresenteException("Une borne avec l'identifiant " + to_string(p_borne.reqIdentifiant()) + " est deja presente.");
    }
    m_bornes.push_back(p_borne.clone());
  }
  
  /*
   *\brief Supprime une borne du vecteur de bornes la classe RegistreBorne 
   * \param[in] p_identifiant l'indentifiant de la borne à supprimer.
   */
  void RegistreBorne::supprimeBorne(int p_identifiant) {
    auto iter = find_if(m_bornes.begin(), m_bornes.end(), [p_identifiant](const unique_ptr<Borne>& elem) {
        return elem->reqIdentifiant() == p_identifiant;
    });
    if (iter == m_bornes.end()) {
        throw BorneAbsenteException("La borne avec l'identifiant " + to_string(p_identifiant) + " est absente du registre.");
    }
    m_bornes.erase(iter);
}

  
  /*
   * \brief Déterminer combien de borne sont enregistrée.
   * \return Le nombre de borne enregistrée.
   */
  int RegistreBorne::reqNombreBorneEnregistre() const {
    return m_bornes.size() ;
  }

  /**
 * \brief converti les données de l'équipe dans une chaîne de caractères formatée
 * \return un objet string contenant les données formatées
 */
string RegistreBorne::reqRegistreBorneFormate () const
{
  ostringstream oss;
  oss << "Registre : " << m_nomRegistreBorne << endl;
  for (const auto & element : m_bornes)
    {
      oss << element->reqBorneFormate () ;
    }
  return oss.str ();
}

/**
 * \brief  Vérifier les invariants de la classe RegistreBorne. Les invariants de cette classe s'assure que le registre de bornes est valide.
 */
  void RegistreBorne::verifieInvariant () const {
    INVARIANT(!m_nomRegistreBorne.empty());
  }
  
} // fin de namespace bornQuebec

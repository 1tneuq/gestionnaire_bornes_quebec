/**
 * \file registreBorneTesteur.cpp
 * \author Tristan Gourrand & 1tneuq
 * \version 0.2
 * \date Cree le 29 mars 2024, 15:51.
 * \brief Test unitaire de la classe RegistreBorne.
 * A tester:
 *         RegistreBorne(std::string p_nomRegistreBorne) ;
 *         string RegistreBorne::reqNomRegistreBorne() const ;
 *         int reqNombreBorneEnregistre() const ;
 *         void ajouteBorne(const Borne& p_borne);
 *         std::string reqRegistreBorneFormate () const ;
 *         RegistreBorne& operator= (const RegistreBorne& p_registreBorne)
 */

#include<gtest/gtest.h>
#include "RegistreBorne.h"
#include "BorneFontaine.h"
using namespace std;
using namespace borneQuebec;

/**
 * \brief Test du constructeur avec paramètres
 * 	Cas valides: constructeurParametreValide Création d'un objet RegistreBorne avec des valeurs valides
 * 	             et vérifiacation de tous les attributs.
 *	Cas invalides: constructeurParametreInvalide
 *		   nomInvalide Le nom du registre est vide.
 */
TEST (RegistreBorne, constructeurParametreValide) {
  RegistreBorne rg1("Registre de test") ;
  ASSERT_EQ("Registre de test", rg1.reqNomRegistreBorne()) ;
}

TEST(RegistreBorne, constructeurParametreInvalide) {
  ASSERT_THROW(RegistreBorne rg1(""), PreconditionException) <<
          "Le nom du registre ne doit pas etre vide.";      
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe RegistreBorne.
 */
class UnRegistreBorne : public ::testing::Test
{
public:
	UnRegistreBorne():f_unRegistreBorne("Registre de borne test"){}
	RegistreBorne f_unRegistreBorne;
};

/**
 * \brief Test de la méthode stirng reqnomRegistreBorne() const;
 *        Cas valides: reqnomRegistreBorne vérifier le retour du nom.
 *        Cas invalides: aucun.
 */
TEST_F(UnRegistreBorne,reqnomRegistreBorne)
{
	ASSERT_EQ("Registre de borne test",f_unRegistreBorne.reqNomRegistreBorne());
}

/**
 * \brief Test de la méthode int reqNombreBorneEnregistre() const;
 *        Cas valides: reqNombreBorneEnregistre vérifier du nombre de borne.
 *        Cas invalides: aucun.
 */
TEST_F(UnRegistreBorne,reqNombreBorneEnregistre)
{
	ASSERT_EQ(0,f_unRegistreBorne.reqNombreBorneEnregistre());
}

/**
 * \brief Test de la méthode ajouteBorne(const Borne& p_borne)
 * 		  Cas valide : ajouteBorneValide assigner une nouvelle borne.
 * 		  Cas invalide : la borne existe déjà dans le registre.
 */
TEST_F(UnRegistreBorne,ajouteBorne)
{
        string nomTopographique = "1er Avenue" ;
        BorneFontaine bf1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, "Montréal","La Hautes-Saint-Charles") ;
        f_unRegistreBorne.ajouteBorne(bf1) ;
	ASSERT_EQ(1, f_unRegistreBorne.reqNombreBorneEnregistre());
        ASSERT_THROW(f_unRegistreBorne.ajouteBorne(bf1), BorneDejaPresenteException);
}

/**
 * \brief Test de la méthode supprimerBorne(int identifiantBorne)
 *        Cas valide: supprimer une borne existante.
 *        Cas invalide: tenter de supprimer une borne qui n'existe pas.
 */
TEST_F(UnRegistreBorne, supprimerBorne) {
        ASSERT_EQ(0, f_unRegistreBorne.reqNombreBorneEnregistre());
        ASSERT_THROW(f_unRegistreBorne.supprimeBorne(100003), BorneAbsenteException);
}

/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objet registre borne.
 *        Cas invalides: aucun.
 */
TEST_F(UnRegistreBorne,registreBorneFormate) {
        string nomTopographique = "1er Avenue" ;
        BorneFontaine bf1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, "Montreal","La Hautes-Saint-Charles") ;
        f_unRegistreBorne.ajouteBorne(bf1) ;
        ostringstream registreBorneFormate ;
        registreBorneFormate << "Registre : " << f_unRegistreBorne.reqNomRegistreBorne() << endl
               << "Borne-fontaine" << endl 
               << "----------------------------------------------" << endl
               << "Identifiant de la borne : " << bf1.reqIdentifiant() << endl
               << "Voie public             : " << bf1.reqIdentifiantVoiePublique() << endl
               << "Nom topographique       : " << bf1.reqNomTopographique() << endl
               << "Latitude                : " << bf1.reqLatitude()<< endl
               << "Longitude               : " << bf1.reqLongitude() << endl 
               << "Ville                   : " << bf1.reqVille() << endl
               << "Arrondissement          : " << bf1.reqArrondissement() << endl ;
        //registreBorneFormate << "Registre : " << f_unRegistreBorne.reqNomRegistreBorne() << endl
        //                     << bf1.reqBorneFormate() ;
        ASSERT_EQ(registreBorneFormate.str(), f_unRegistreBorne.reqRegistreBorneFormate());
}

/**
 * \brief Test de la méthode RegistreBorne& operator= (const RegistreBorne& p_registreBorne)
 *        Cas valides: operatorAssignationValide vérifier l'assignation entre deux objets registre borne.
 *        Cas invalides: aucun.
 */
TEST_F(UnRegistreBorne,operatorAssignationValide) {
        string nomTopographique = "1er Avenue" ;
        BorneFontaine bf1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, "Montréal","La Hautes-Saint-Charles") ;
        f_unRegistreBorne.ajouteBorne(bf1) ;
        RegistreBorne registreTest = f_unRegistreBorne ;
	ASSERT_EQ(registreTest.reqRegistreBorneFormate() , f_unRegistreBorne.reqRegistreBorneFormate());
}




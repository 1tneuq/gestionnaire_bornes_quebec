/**
 * \file borneFontaineTesteur.cpp
 * \author 1tneuq
 * \version 0.1
 * \date Créé le 16 mars 2024, 15 h 39
 * \brief Test unitaire de la classe Borne.
 * A tester:
 *         Borne(unsigned int p_identifiant, string p_nomTopographique, 
                double p_longitude, double p_latitude, string p_ville,
                string p_arrondissement, string p_identifiantVoiePublique="");
 *         string reqVille() const;
 *         string reqArrondissement() const;
 *         string reqBorneFormate () const ;
 *         BorneFontaine& operator= (const BorneFontaine& p_borneFontaine)
 *         bool operator==(const BorneFontaine & p_borneFontaine) const;
 */

#include<gtest/gtest.h>
#include "BorneFontaine.h"
using namespace std;
using namespace borneQuebec;

/**
 * \brief Test du constructeur avec paramètres
 * 	Cas valides: constructeurParametreValide Création d'un objet Borne fontaine avec des valeurs valides
 * 	             et vérifiacation de tous les attributs.
 *	Cas invalides: constructeurParametreInvalide
 *		   arrondissementInvalide L'arrondissement est vide quand la ville est Québec.
 */
TEST (BorneFontaine, constructeurParametreValide) {
  string nomTopographique = "1er Avenue";
  BorneFontaine bf1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, "Montréal","La Hautes-Saint-Charles") ;
  ASSERT_EQ("Montréal", bf1.reqVille()) ;
  ASSERT_EQ("La Hautes-Saint-Charles", bf1.reqArrondissement ()) ;
}

TEST(BorneFontaine, constructeurParametreInvalide) {
  string nomTopographique = "1er Avenue";
  ASSERT_THROW(BorneFontaine bf1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, "Québec",""), PreconditionException) <<
          "Si la ville est Québec l'arrondissement ne peut pas être vide.";      
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Borne.
 */
string nomTopographique = "1er Avenue" ;
class UneBorneFontaine : public ::testing::Test
{
public:
	UneBorneFontaine():f_uneBorneFontaine(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792,"Montréal","La Hautes-Saint-Charles"){}
	BorneFontaine f_uneBorneFontaine;
};

/**
 * \brief Test de la méthode string reqVille() const;
 *        Cas valides: reqInvalide vérifier le retour de la ville.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneFontaine,reqVille)
{
	ASSERT_EQ("Montréal",f_uneBorneFontaine.reqVille());
}

/**
 * \brief Test de la méthode int reqArrondissement() const;
 *        Cas valides: reqInvalide vérifier le retour de l'arrondissement,
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneFontaine,reqArrondissement)
{
	ASSERT_EQ("La Hautes-Saint-Charles",f_uneBorneFontaine.reqArrondissement());
}

/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objet borne formaté.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneFontaine,reqBorneFormate) {
  ostringstream borneFontaineFormate ;
  borneFontaineFormate << "Borne-fontaine" << endl 
               << "----------------------------------------------" << endl
               << "Identifiant de la borne : " << f_uneBorneFontaine.reqIdentifiant() << endl
               << "Voie public             : " << f_uneBorneFontaine.reqIdentifiantVoiePublique() << endl
               << "Nom topographique       : " << f_uneBorneFontaine.reqNomTopographique() << endl
               << "Latitude                : " << f_uneBorneFontaine.reqLatitude()<< endl
               << "Longitude               : " << f_uneBorneFontaine.reqLongitude() << endl 
               << "Ville                   : " << f_uneBorneFontaine.reqVille() << endl
               << "Arrondissement          : " << f_uneBorneFontaine.reqArrondissement() << endl ;
	ASSERT_EQ(borneFontaineFormate.str(), f_uneBorneFontaine.reqBorneFormate());
}

/**
 * \brief Test de la méthode BorneFontaine& operator= (const BorneFontaine& p_borneFontaine)
 *        Cas valides: operatorAssignationValide vérifier l'assignation entre deux objets bornes fontaines.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneFontaine,operatorAssignationValide) {
        string nomTopographique = "1er Avenue" ;
        BorneFontaine borneTest = f_uneBorneFontaine ;
	ASSERT_EQ(borneTest.reqBorneFormate() , f_uneBorneFontaine.reqBorneFormate ());
}

/**
 * \brief Test de la méthode bool operator==(const BorneFontaine & p_borneFontaine) const;
 *        Cas valides: operatorEgaliteValide vérifier l'égalité entre deux objets bornes.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneFontaine,operatorEgaliteValide) {
        string nomTopographique = "1er Avenue" ;
        BorneFontaine uneBorneFontaineTest(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792,"Montréal","La Hautes-Saint-Charles") ;
	ASSERT_EQ(uneBorneFontaineTest, f_uneBorneFontaine);
}


/**
 * \file borneStationnementTesteur.cpp
 * \author 1tneuq
 * \version 0.1
 * \date Créé le 16 mars 2024, 17 h 54.
 * \brief Test unitaire de la classe Borne.
 * A tester:
 *         Borne(unsigned int p_identifiant, string p_nomTopographique, int p_numBorne, string p_coteRue, string p_identifiantVoiePublique="");
 *         int reqNumBorne() const;
 *         string reqCoteRue() const;
 *         string reqBorneFormate () const ;
 *         BorneStationnement& operator= (const BorneStationnement& p_borneStationnement)
 *         bool operator==(const BorneStationnement & p_borneStationnement) const;
 */
#include<gtest/gtest.h>
#include "BorneStationnement.h"


using namespace borneQuebec;
using namespace std; 

/**
 * \brief Test du constructeur avec paramètres
 * 	Cas valides: constructeurParametreValide Création d'un objet Borne de stationnement avec des valeurs valides
 * 	             et vérifiacation de tous les attributs.
 *	Cas invalides: constructeurParametreInvalide
 *		   numBorneInvalide Le numéro de la borne ne doit pas dépasser 4 chiffres.
 *                 côtéRueInvalide Le côté de la rue doit être un point cardinal N, S, E, O
 */
TEST (BorneStationnement, constructeurParametreValide) {
  string nomTopographique = "1er Avenue";
  BorneStationnement bs1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, 4005, "E") ;
  ASSERT_EQ(4005, bs1.reqNumBorne ()) ;
  ASSERT_EQ("E", bs1.reqCoteRue()) ;
}

TEST(BorneStationnement, constructeurParametreInvalideTropPetit) {
  string nomTopographique = "1er Avenue";
  ASSERT_THROW(BorneStationnement bs2(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, 45454, "E"), PreconditionException) <<
          "Le numéro de la borne ne doit pas dépasser 4 chiffres.";
}

TEST(BorneStationnement, constructeurParametreCôtéRueInvalide) {
  string nomTopographique = "1er Avenue";
  ASSERT_THROW(BorneStationnement bs2(100001, "100", nomTopographique,-71.23627057605484,46.82899800269792, 45454, "W"), PreconditionException) <<
          "Le côté de rue doit etre un point cardinal comprit dans l'ensembble N, S, E, O.";
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe BorneStationnement.
 */
string nomTopographique = "1er Avenue";
class UneBorneStationnement : public ::testing::Test
{
public:
	UneBorneStationnement():f_uneBorneStationnement(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, 4005, "E"){}
	BorneStationnement f_uneBorneStationnement;
};

/**
 * \brief Test de la méthode int reqNumBorne() const;
 *        Cas valides: reqNumBorne vérifier le retour du numéro de la borne de stationnement.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneStationnement,reqNumBorne)
{
	ASSERT_EQ(4005,f_uneBorneStationnement.reqNumBorne());
}

/**
 * \brief Test de la méthode int reqCoteRue() const;
 *        Cas valides: reqCoteRue vérifier le retour du côté de la rue de la borne de stationnement.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneStationnement,reqCoteRue)
{
	ASSERT_EQ("E",f_uneBorneStationnement.reqCoteRue());
}

/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objet borne formaté.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneStationnement,reqBorneFormate) {
  ostringstream oss ;
  oss << "Borne de stationnement" << endl 
      << "----------------------------------------------" << endl
      << "Identifiant de la borne : " << f_uneBorneStationnement.reqIdentifiant() << endl
      << "Voie public             : " << f_uneBorneStationnement.reqIdentifiantVoiePublique() << endl
      << "Nom topographique       : " << f_uneBorneStationnement.reqNomTopographique() << endl
      << "Latitude                : " << f_uneBorneStationnement.reqLatitude()<< endl
      << "Longitude               : " << f_uneBorneStationnement.reqLongitude() << endl
      << "Numero de la rue        : " << f_uneBorneStationnement.reqNumBorne() << endl
      << "Cote de la rue          : " << f_uneBorneStationnement.reqCoteRue() ;
	ASSERT_EQ(oss.str(), f_uneBorneStationnement.reqBorneFormate());
}

/**
 * \brief Test de la méthode bool operator==(const BorneStationnement & p_borneStationnement) const;
 *        Cas valides: operatorEgaliteValide vérifier l'égalité entre deux objets bornesStationnement.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneStationnement,operatorEgaliteValide) {
        string nomTopographique = "1er Avenue" ;
        BorneStationnement uneBorneStationnementTest(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792, 4005, "E") ;
	ASSERT_EQ(uneBorneStationnementTest, f_uneBorneStationnement);
}


/**
 * \brief Test de la méthode BorneStationnement& operator= (const BorneStationnement& p_borneStationnement)
 *        Cas valides: operatorAssignationValide vérifier l'assignation entre deux objets bornes de stationnements.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorneStationnement,operatorAssignationValide) {
        string nomTopographique = "1er Avenue" ;
        BorneStationnement borneTest = f_uneBorneStationnement ;
	ASSERT_EQ(borneTest.reqBorneFormate() , f_uneBorneStationnement.reqBorneFormate ());
}




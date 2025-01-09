/**
 * \file borneTesteur.cpp
 * \author 1tneuq
 * \version 0.1
 * \date Cree le 8 mars 2024, 19 h 02.
 * \brief Test unitaire de la classe Borne.
 * A tester:
 *         Borne(unsigned int p_identifiant, string p_nomTopographique, double p_longitude, double p_latitude, string p_identifiantVoiePublique);
 *         int reqIdentifiant() const;
 *         string reqNomTopographique() const;
 *         float reqLongitude() const;
 *         float reqLatitude() const;
 *         string reqIdentifiantVoiePublique() const;
 *         string reqBorneFormate () const ;
 *         bool operator==(const Borne & p_borne) const;
 *         Borne& operator= (const Borne& p_borne)
 */

#include<gtest/gtest.h>
#include "Borne.h"
using namespace std;
using namespace borneQuebec;

/**
 * \class BorneDeTest
 * \brief Classe de test permettant de tester la classe abstraite Borne
 */
class BorneDeTest : public Borne
{

public:


  BorneDeTest (const unsigned int& p_identifiant, 
               const std::string& p_identifiantVoiePublique, 
               std::string& p_nomTopographique, 
               const  double& p_longitude, const double& p_latitude) :
  Borne (p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude) { };
  
  virtual std::unique_ptr<Borne> clone() const {
    return unique_ptr < Borne > (new BorneDeTest (*this));
  }

  virtual string reqBorneFormate() const
  {
    return Borne::reqBorneFormate();
  }


} ;
/**
 * \brief Test du constructeur avec paramètres
 * 	Cas valides: constructeurParametreValide Création d'un objet Borne avec des valeurs valides
 * 	             et vérifiacation de tous les attributs.
 *	Cas invalides: constructeurParametreInvalide
 *		   nomTopographicInvalide Le nom topographique est vide.
 *		   identifiantVoiePubliqueInvalide L'identifiant de la voie publique n'est pas un numéro.
 */
TEST (Borne, constructeurParametreValide) {
  string nomTopographique = "1er Avenue" ;
  BorneDeTest b1(100001, "100328", nomTopographique,-71.23627057605484,46.82899800269792) ;
  ASSERT_EQ(100001, b1.reqIdentifiant()) ;
  ASSERT_EQ("100328", b1.reqIdentifiantVoiePublique()) ;
  ASSERT_EQ("1er Avenue", b1.reqNomTopographique()) ;
  ASSERT_EQ(-71.23627057605484, b1.reqLongitude()) ;
  ASSERT_EQ(46.82899800269792, b1.reqLatitude()) ;
}

TEST(Borne, constructeurParametreNomTopographicInvalide) {
  string nomTopographiqueVide = "" ;
  ASSERT_THROW(BorneDeTest b2(100001, "", nomTopographiqueVide,-71.23627057605484, 46.82899800269792), PreconditionException) <<
          "Le nom topographique doit etre non vide." ;
}

TEST(Borne, constructeurParametreIdentifiantVoiePubliqueInvalide) {
  string nomTopographique = "1er Avenue" ;
  ASSERT_THROW(BorneDeTest b3(100001, "six", nomTopographique, -71.23627057605484, 46.82899800269792),PreconditionException) <<
          "L'indentifiant de la voir publique doit etre un numro.";
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Borne.
 */
string nomTopographique = "1er Avenue" ;
class UneBorne : public ::testing::Test
{
public:
	UneBorne():f_uneBorne(100001,"100328", nomTopographique,-71.23627057605484,46.82899800269792){}
	BorneDeTest f_uneBorne;
};

/**
 * \brief Test de la méthode int reqIdentifiant() const;
 *        Cas valides: reqIdentifiant vérifier le retour de l'indentifiant
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqIdentifiant)
{
	ASSERT_EQ(100001,f_uneBorne.reqIdentifiant());
}

/**
 * \brief Test de la méthode float reqLatitude() const;
 *        Cas valides: reqNomTopographique vérifier le retour de la latitude.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqIdentifiantVoiePublique)
{
	ASSERT_EQ("100328",f_uneBorne.reqIdentifiantVoiePublique());
}

/**
 * \brief Test de la méthode int reqNomTopographique() const;
 *        Cas valides: reqNomTopographique vérifier le retour de du nom topographique.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqNomTopographique)
{
	ASSERT_EQ("1er Avenue",f_uneBorne.reqNomTopographique());
}

/**
 * \brief Test de la méthode double reqLongitude() const;
 *        Cas valides: reqNomTopographique vérifier le retour de la longitude.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqLongitude)
{
	ASSERT_EQ(-71.23627057605484,f_uneBorne.reqLongitude());
}

/**
 * \brief Test de la méthode double reqLatitude() const;
 *        Cas valides: reqNomTopographique vérifier le retour de la latitude.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqLatitude)
{
	ASSERT_EQ(46.82899800269792,f_uneBorne.reqLatitude());
}


/**
 * \brief Test de la méthode string reqBorneFormate()
 *        Cas valides: vérifier le retour des information sur l'objet borne formaté.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,reqBorneFormate) {
  ostringstream borneFormate ;
  borneFormate << "Identifiant de la borne : " << f_uneBorne.reqIdentifiant() << endl
               << "Voie public             : " << f_uneBorne.reqIdentifiantVoiePublique() << endl
               << "Nom topographique       : " << f_uneBorne.reqNomTopographique() << endl
               << "Latitude                : " << f_uneBorne.reqLatitude()<< endl
               << "Longitude               : " << f_uneBorne.reqLongitude() ;
	ASSERT_EQ(borneFormate.str(), f_uneBorne.reqBorneFormate());
}

/**
 * \brief Test de la méthode asgNomTopographique(string& p_nomTopographique)
 * 		  Cas valide : asgNomTopographiqueValide assigner un nom topographique valide.
 * 		  Cas invalide : asgNomTopographiqueInvalide assigner un nom topographique vide.
 */
TEST_F(UneBorne,asgNomTopographiqueValide)
{
        string nomTopographiqueAssignation = "Boulevard Cardinal-Villeneuve" ;
	f_uneBorne.asgNomTopographique(nomTopographiqueAssignation);
	ASSERT_EQ("Boulevard Cardinal-Villeneuve",f_uneBorne.reqNomTopographique());
}

TEST_F(UneBorne,asgNomTopographiqueInvalide)
{
        string nomTopographiqueVide = "" ;
	ASSERT_THROW(f_uneBorne.asgNomTopographique(nomTopographiqueVide), PreconditionException) <<
                "Le nom topographique ne doit pas etre vide." ;
}

/**
 * \brief Test de la méthode bool operator==(const Borne & p_borne) const;
 *        Cas valides: operatorEgaliteValide vérifier l'égalité entre deux objets bornes.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,operatorEgaliteValide) {
        string nomTopographique = "1er Avenue" ;
        BorneDeTest uneBorne(100001,"100328", nomTopographique,-71.23627057605484,46.82899800269792) ;
	ASSERT_EQ(uneBorne, f_uneBorne);
}

/**
 * \brief Test de la méthode bool Borne& operator= (const Borne& p_borne)
 *        Cas valides: operatorAssignationValide vérifier l'assignation entre deux objets bornes.
 *        Cas invalides: aucun.
 */
TEST_F(UneBorne,operatorAssignationValide) {
        string nomTopographique = "1er Avenue" ;
        BorneDeTest borneTest = f_uneBorne ;
	ASSERT_EQ(borneTest.reqBorneFormate() , f_uneBorne.reqBorneFormate ());
}

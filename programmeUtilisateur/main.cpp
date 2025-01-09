
#include <cstdlib>
#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include <iostream>
#include <string>
using namespace std;


void saisirInformationBorne(unsigned int& p_identifiant,
                            string& p_identifiantVoiePublique,
                            string& p_nomTopographique,
                            double& p_longitude, double& p_latitude) {
  cout << "Entrez l'identifiant de la borne valide:" << endl ;
  char buffer [256] ;
  cin >> p_identifiant ;
  cin.ignore() ;
  cout << "Entrez l'identifiant de la Voie Publique de la borne valide:" << endl ;
  cin.getline(buffer, 255) ; 
  p_identifiantVoiePublique = buffer ;
  cout << "Entrez le nom topographique valide:" << endl ;
  cin.getline(buffer, 255) ;
  p_nomTopographique = buffer ;
  cout << "Entrez la longitude:" << endl ;
  cin >> p_longitude ;
  cin.ignore() ;
  cout << "Entrez la latitude:" << endl ; 
  cin >> p_latitude ;
  cin.ignore() ;
}
int
main ()
{
  bool continuer = true ;
  borneQuebec::RegistreBorne registreDeBorne("bornes de l'agglomération de la ville de Québec") ;
  while (continuer) {
      ostringstream menu ;
      menu << "[1] Ajouter une borne fontaine et une borne de stationnement." << endl 
           << "[2] Afficher les bornes du registre." << endl    
           << "[3] Arreter le programme." << endl ;
      cout << menu.str() ;
      int choix ;
      cin >> choix ;
      cin.ignore() ;
      switch (choix) {
          case 1 : {
            // Creation des variables pour la saisie des informations.
            unsigned int identifiant ;
            string identifiantVoiePublique ;
            string nomTopographique ;
            double longitude ;
            double latitude ;
            //Saisir les informations de la borne fontaine.
            cout << "Enregistrement d’une borne fontaine :" << endl ;
            saisirInformationBorne(identifiant,
                                   identifiantVoiePublique,
                                   nomTopographique,
                                   longitude,latitude) ;
            char buffer[256] ;             
            cout << "Entrez le nom de la ville :" << endl ;
            string ville ;
            cin.getline(buffer, 255) ;
            ville = buffer ;
            cout << "Entrez le nom de l'arrondissement :" << endl ;
            string arrondissement ;
            cin.getline(buffer, 255) ;
            arrondissement = buffer ;
            //Creer la borne fontaine a partir des informations donnees.
            borneQuebec::BorneFontaine bf1(identifiant, identifiantVoiePublique, 
                                       nomTopographique, longitude,latitude,
                                       ville, arrondissement) ;
            //Saisir les information de la borne de stationnement.
            cout << "Enregistrement d’une borne de stationnement :" << endl ;
            registreDeBorne.ajouteBorne(bf1) ;
            saisirInformationBorne(identifiant,
                                   identifiantVoiePublique,
                                   nomTopographique,
                                   longitude,latitude) ;
            cout << "Entrez le numéro de la borne de stationnement:" << endl ;
            int numBorne ;
            cin >> numBorne ;
            cin.ignore() ;
            cout << "Entrez le cote de la rue (N, S, E, O) :" << endl ;
            string coteRue ;
            cin.getline(buffer, 255) ;
            coteRue = buffer ;
            //Creer la borne de stationnement a partir des informations donnees.
            borneQuebec::BorneStationnement bs1(identifiant, identifiantVoiePublique, 
                                                nomTopographique, longitude,latitude,
                                                numBorne, coteRue) ;
            registreDeBorne.ajouteBorne(bs1) ;
            cout << registreDeBorne.reqRegistreBorneFormate() ;
            break ;
          }
        case 2 :
          cout << "Contenu du registre :" <<endl ;
          cout << registreDeBorne.reqRegistreBorneFormate () ;
          break ;
            
        case 3 :
          continuer = false ;
          break ;
          
        default :
          cout << " Choix invalide." << endl  ;
          break ;
         
        }
    }
  
  return 0;
}


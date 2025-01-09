#include "validationFormat.h"

using namespace std;
namespace tp1 {
bool validePointCardinal(const std::string& p_cardinalite)
{
  bool valeur_boolean = false;
  array<string, 5>cardinalitePossible{"N", "S", "E", "O"};
  
  for (auto cardinalite_valide : cardinalitePossible)
    {
      if (p_cardinalite == cardinalite_valide || p_cardinalite.empty())
        {
          valeur_boolean = true ;
          break ; 
        }
  
    }
  
  return valeur_boolean ;
  
}

bool valideLigneCVSBorneStationnement (const std::string& p_ligne)
{
 istringstream chaine(p_ligne);
 
 string id ;
 string no_borne ;
 string cote_rue ;
 string id_voie_publique ;
 string nom_topographique ;
 string longitude_str ;
 string latitude_str ;
 
 getline(chaine, id, ',');
 getline(chaine, no_borne, ',');
 getline(chaine, cote_rue, ',');
 getline(chaine, id_voie_publique, ',');
 getline(chaine, nom_topographique, ',');
 getline(chaine, longitude_str, ',');
 getline(chaine, latitude_str, ',');
 
 bool valeur_boolean = false;
 
 if (!longitude_str.empty() && !latitude_str.empty() && compterNombreVirgule(p_ligne))
   {
     int longitude = stoi(longitude_str);
     int latitude = stoi(latitude_str);
     
    if (!id.empty() && !no_borne.empty() && validePointCardinal(cote_rue) && 
    (id_voie_publique.size() == 6 || id_voie_publique.empty()) &&
    !nom_topographique.empty() && longitude == LONGITUDE && latitude == LATITUDE)
      {
        valeur_boolean = true ;
      }

    }
   
 return valeur_boolean ;
   
}
bool valideFichierBornesStationnement(std::istream& p_fluxBornesStationnement) 
{
    std::string ligne_borne;
    int num_ligne = 0;
    bool valeur_boolean = true;
    getline(p_fluxBornesStationnement, ligne_borne);

    while (std::getline(p_fluxBornesStationnement, ligne_borne)) {
        if (!valideLigneCVSBorneStationnement(ligne_borne)) {
            valeur_boolean = false;
            break;
        }
        ++num_ligne;
    }

    return valeur_boolean;
}
bool compterNombreVirgule(const std::string& p_ligne)
{
  int nb_virgule = 0;
  bool valeur_boolean = true;
  for (auto car : p_ligne)
    {
      if (car == ',')
        {
          nb_virgule ++;        
        }
    }
  if (nb_virgule != NB_MAX_VIRGULE)
    {
      valeur_boolean = false;
    }
  return valeur_boolean;
  
}
}//Namespace tp1
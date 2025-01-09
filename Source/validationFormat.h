
#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace tp1 {
const int LONGITUDE = -71;
const int LATITUDE = 46;
const int NB_MAX_VIRGULE = 6;
bool compterNombreVirgule(const std::string& p_ligne);
bool validePointCardinal(const std::string& p_cardinalite);
bool valideLigneCVSBorneStationnement (const std::string& p_ligne);
bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement);
}



#endif /* VALIDATIONFORMAT_H */


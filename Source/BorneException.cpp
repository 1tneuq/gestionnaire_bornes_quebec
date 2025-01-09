/**
 * \file   BorneException.cpp
 * \brief  Implantation de la classe BorneException et de ses héritiers
 * \author 1tneuq
 * \date 17 avril 2024
 */

#include "BorneException.h"
#include <sstream>

using namespace std;

/**
 * \brief Constructeur de BorneException
 * \param p_raison Le message d'erreur à transmettre à la classe de base runtime_error.
 */
BorneException::BorneException(const std::string& p_raison) : runtime_error(p_raison) {}

/**
 * \brief Constructeur de BorneDejaPresenteException
 * \param p_raison Le message d'erreur qui spécifie la nature de l'exception.
 */
BorneDejaPresenteException::BorneDejaPresenteException(const std::string& p_raison)
: BorneException(p_raison) {}

/**
 * \brief Constructeur de BorneAbsenteException
 * \param p_raison Le message d'erreur qui spécifie la nature de l'exception.
 */
BorneAbsenteException::BorneAbsenteException(const std::string& p_raison)
: BorneException(p_raison) {}

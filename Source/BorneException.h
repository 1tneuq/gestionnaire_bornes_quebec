/**
 * \file   BorneException.h
 * \brief  Fichier contenant la déclaration de la classe BorneException et de ses héritiers
 * \author Quentin Lacombe
 * \date 17 avril 2024
 */

#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class BorneException
 * \brief Classe de base pour les exceptions liées aux bornes, héritant de std::runtime_error.
 */
class BorneException : public std::runtime_error {
public:
    explicit BorneException(const std::string& raison);
};

/**
 * \class BorneDejaPresenteException
 * \brief Exception lancée lorsque la borne ajoutée existe déjà.
 */
class BorneDejaPresenteException : public BorneException {
public:
    explicit BorneDejaPresenteException(const std::string& raison);
};

/**
 * \class BorneAbsenteException
 * \brief Exception lancée lorsqu'une tentative est faite pour supprimer une borne qui n'existe pas.
 */
class BorneAbsenteException : public BorneException {
public:
    explicit BorneAbsenteException(const std::string& raison);
};

#endif // BORNEEXCEPTION_H



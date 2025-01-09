/*
 * \File:   main.cpp
 * \Author: Tristan Gourrand & 1tneuq
 * \brief: Programme principal.
 * \date: Created on 15 avril 2024, 10 h 34
 */

#include <QApplication>
#include "borneGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  borneQuebec::RegistreBorne registreBorne("Registre de borne") ;
  borneGUI fenetre(registreBorne) ;
  fenetre.show() ;

  return app.exec ();
}

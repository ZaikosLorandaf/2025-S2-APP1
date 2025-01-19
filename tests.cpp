/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"
#include "canevas.h"
#include "carre.h"
#include "cercle.h"
#include "rectangle.h"
#include <cassert>

void Tests::tests_unitaires_formes() {
}

void Tests::tests_unitaires_couche() {
}

void Tests::tests_unitaires_vecteur() {
}

void Tests::tests_unitaires_canevas() {
  /*auto canevas =  Canevas{};*/
  /*assert(canevas.ajouterCouche());*/
}

void Tests::tests_unitaires()
{
  // Fait tous les tests unitaires
  tests_unitaires_formes();
  tests_unitaires_couche();
  tests_unitaires_vecteur();
  tests_unitaires_canevas();
}

void Tests::tests_application()
{
  // Fait tous les tests applicatifs
  tests_application_cas_01();
  tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
  std::cout << "TESTS APPLICATION (CAS 01)" << std::endl;
  Canevas c;

  std::cout << "\nETAPE 1 & 2\n";
  c.afficher(cout);
  std::cout << "L'aire de la couche est: "
    << c.aire() << std::endl;


  std::cout << "\nETAPE 3 & 5\n";
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();

  c.afficher(cout);


  std::cout << "\nETAPE 6 & 9\n";
  c.activateLayer(1);
  c.addShape(new Cercle(0,1,5));
  c.addShape(new Carre(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));

  c.activateLayer(0);
}

void Tests::tests_application_cas_02()
{
  std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;
  // Il faut ajouter les operations realisant ce scenario de test.
}

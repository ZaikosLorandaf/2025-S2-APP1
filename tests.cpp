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

  std::cout << "\n\nETAPE 1 & 2\n";
  c.display(cout);
  std::cout << "L'aire du canevas est: "
    << c.area() << std::endl;


  std::cout << "\n\nETAPE 3 & 5\n";
  //~~~~~~~~~~~ Step 3 ~~~~~~~~~~~//
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();

  //~~~~~~~~~~~ Step 4 ~~~~~~~~~~~//
  c.display(cout);

  //~~~~~~~~~~~ Step 5 ~~~~~~~~~~~//
  std::cout << "\nL'aire du canevas est: "
    << c.area() << std::endl;


  //~~~~~~~~~~~ Step 6 ~~~~~~~~~~~//
  std::cout << "\n\nETAPE 6 & 9\n";
  c.activateLayer(1);
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));

  //~~~~~~~~~~~ Step 7 ~~~~~~~~~~~//
  c.activateLayer(0);
  c.addShape(new Rectangle(0,0,12,3));

  //~~~~~~~~~~~ Step 8 ~~~~~~~~~~~//
  c.display(cout);

  //~~~~~~~~~~~ Step 9 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c.area() << std::endl;
}

void Tests::tests_application_cas_02()
{
  std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;
  // Il faut ajouter les operations realisant ce scenario de test.
}

/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "canevas.h"
#include "couche.h"

// sinon il est detruit a la fin de la func, donc c;est ca ou alors tu le met en pointeur et itsVecteur = new Vecteur();
Canevas::Canevas(): itsVecteur{}{
}

Canevas::~Canevas() {
}

bool Canevas::ajouterCouche() {
  Couche* c = new Couche{};
  // add couche ?
  itsVecteur.addCouche(c);
  if (activeLayer == -1) {
    activerCouche(itsVecteur.getCurrentSize());
    activeLayer = itsVecteur.getCurrentSize();
    itsVecteur.getCouche(activeLayer)->setState(STATE_ACTIVE);
  }
  return true;
}

bool Canevas::retirerCouche(int index) {
  if (index < 0 || index > itsVecteur.getCurrentSize())
    return false;
  itsVecteur.removeCouche(index);
  return true;
}

bool Canevas::reinitialiser() {
  itsVecteur.~Vecteur();
  itsVecteur = Vecteur();
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::reinitialiserCouche(int index) {
  if (itsVecteur.getCouche(index)->getState() == STATE_ACTIVE)
    return false;
  return itsVecteur.getCouche(index)->reset();
}

bool Canevas::activerCouche(int index) {
  if (activeLayer != NO_LAYER_ACTIVE)
    return false;
  return itsVecteur.getCouche(index)->setState(STATE_ACTIVE);
  activeLayer = index;
}

bool Canevas::desactiverCouche(int index) {
  if (index != activeLayer)
    return false;
  activeLayer = NO_LAYER_ACTIVE;
  return itsVecteur.getCouche(index)->setState(STATE_INACTIVE);
}

bool Canevas::ajouterForme(Forme *p_forme) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  itsVecteur.getCouche(activeLayer)->addForme(p_forme);
  return true;
}

bool Canevas::retirerForme(int index) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  itsVecteur.getCouche(activeLayer)->removeForme(index);
  return true;
}

double Canevas::aire() {
  int areaSum{0};
  for (int i = 0; i < itsVecteur.getCurrentSize(); i++)
    areaSum += itsVecteur.getCouche(i)->getArea();
  return areaSum;
}

bool Canevas::translater(int deltaX, int deltaY) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  return itsVecteur.getCouche(activeLayer)->translation(deltaX, deltaY);
}

void Canevas::afficher(ostream & s) {
  if (itsVecteur.getCurrentSize() == 1
      && itsVecteur.getCouche(0)->getState() == STATE_INIT) {
    std::cout << "---- Aucune Couche ----\n";
    return;
  }

  for (int i = 0; i < itsVecteur.getCurrentSize(); i++) {
    std::cout << "---- Couche " << i << " ----" << std::endl;
    std::cout << "Etat: ";

    switch (itsVecteur.getCouche(i)->getState()) {
      case 0:
        std::cout << "Initialised\n";
        break;
      case 1:
        std::cout << "Active\n";
        break;
      case 2:
        std::cout << "Inactive\n";
        break;
    };

    std::cout << itsVecteur.getCouche(i)->getState() << std::endl;
    for (int j = 0; j < itsVecteur.getCouche(i)->getIndex(); j++)
      itsVecteur.getCouche(i)->getForme(j)->afficher(s);
  }
}


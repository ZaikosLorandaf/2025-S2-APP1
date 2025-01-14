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

#define NO_LAYER_ACTIVE -1

Canevas::Canevas() {
  itsVecteur = Vecteur();
}

Canevas::~Canevas() {
}

bool Canevas::ajouterCouche() {
  Couche* c = itsVecteur.getCouche(itsVecteur.getCurrentSize());
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
  for (int i = 0; i < itsVecteur.getCurrentSize(); i++) {
    std::cout << "---- Couche " << i << " ----" << std::endl;
    for (int j = 0; j < itsVecteur.getCouche(i)->getIndex(); j++)
      itsVecteur.getCouche(i)->getForme(j)->afficher(s);
  }
}


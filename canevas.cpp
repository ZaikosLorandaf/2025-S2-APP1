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

Canevas::Canevas() {
  itsVecteur = new Vecteur();
}

Canevas::~Canevas() {
delete itsVecteur;
}

bool Canevas::ajouterCouche() {
  Couche* newCouche = new Couche();
  itsVecteur->addCouche(newCouche);
  return true;
}

bool Canevas::retirerCouche(int index) {
  itsVecteur->removeCouche(index);
  return true;
}

bool Canevas::reinitialiser() {
  delete itsVecteur;
  itsVecteur = new Vecteur();
  return true;
}

bool Canevas::reinitialiserCouche(int index) {
  itsVecteur[index].getCouche(index)->reset();
  itsVecteur[index].getCouche(index)->changeState(STATE_INIT);
  return true;
}

bool Canevas::activerCouche(int index) {
  itsVecteur[index].getCouche(index)->changeState(STATE_ACTIVE);
  return true;
}

bool Canevas::desactiverCouche(int index) {
  itsVecteur[index].getCouche(index)->changeState(STATE_INACTIVE);
  return true;
}

bool Canevas::ajouterForme(Forme *p_forme) {
  return true;
}

bool Canevas::retirerForme(int index) {
  return true;
}

double Canevas::aire() {
  return 0.0;
}

bool Canevas::translater(int deltaX, int deltaY) {
  return true;
}

void Canevas::afficher(ostream & s) {
}

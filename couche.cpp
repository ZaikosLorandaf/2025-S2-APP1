/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Sarah Gosselin
 * Date : Jan 2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"
#include "forme.h"

Couche::Couche() {
  state = STATE_INIT;
}

int Couche::getState(){
  return state;
}

bool Couche::addForme(Forme* f) {
  if (state == STATE_INACTIVE)
    return false;
  if (indexFormes > MAX_FORMES)
    return false;
  formes[indexFormes] = f;
  indexFormes++;
  return true;
}

Forme* Couche::removeForme(int index) {
  if (index >= indexFormes)
    return NULL;
  Forme* f = formes[index];
  for (int i = index; i < indexFormes; i++)
    formes[i] = formes[i+1];
  formes[indexFormes] = NULL;
  indexFormes--;
  return f;
}

Forme* Couche::getForme(int index) {
  if (index > indexFormes)
    return NULL;
  return formes[index];
}

double Couche::getArea() {
  if (state == STATE_INACTIVE)
    return false;
  double sum{0};
  for (int i = 0; i < indexFormes; i++)
    sum += formes[i]->aire();
  return sum;
}

bool Couche::translation(int deltaX, int deltaY) {
  if (state == STATE_INACTIVE)
    return false;
  for (int i = 0; i < indexFormes; i++) {
    formes[i]->translater(deltaX, deltaY);
  };
  return true;
}

bool Couche::reset() {
  state = STATE_INIT;
  return true;
};

bool Couche::changeState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}


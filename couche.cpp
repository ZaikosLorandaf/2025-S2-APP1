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

Layer::Layer() {
  state = STATE_INIT;
}

int Layer::getStateLay() {
  return state;
}

bool Layer::addForme(Forme* f) {
  if (indexFormes > MAX_FORMES)
    return false;
  formes[indexFormes] = f;
  indexFormes++;
  return true;
}

Forme* Layer::removeForme(int index) {
  if (index >= indexFormes)
    return NULL;
  Forme* f = formes[index];
  for (int i = index; i < indexFormes; i++)
    formes[i] = formes[i+1];
  formes[indexFormes] = NULL;
  indexFormes--;
  return f;
}

Forme* Layer::getForme(int index) {
  if (index > indexFormes)
    return NULL;
  return formes[index];
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < indexFormes; i++)
    sum += formes[i]->aire();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < indexFormes; i++) {
    formes[i]->translater(deltaX, deltaY);
  };
  return true;
}

bool Layer::reset() {
  for (int i = 0; i < MAX_FORMES; i++)
    formes[i] = NULL;
  state = STATE_INIT;
  return true;
};

bool Layer::setState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}

int Layer::getIndex() {
  return indexFormes;
}

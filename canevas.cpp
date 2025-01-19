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
#include "vecteur.h"
#include <csignal>

Canevas::Canevas(): vector() {}
Canevas::~Canevas() {}

bool Canevas::addLayerCan() {
  Layer* l = new Layer();
  vector.addLayerVec(l);
  /*if (activeLayer == -1) {*/
  /*  activeLayer = vector.getCurrentSize();*/
  /*  activateLayer(activeLayer);*/
  /*  vector.getLayer(activeLayer)->setState(STATE_ACTIVE);*/
  /*}*/
  return true;
}

bool Canevas::removeLayerCan(int index) {
  if (index < 0 || index > vector.getCurrentSize())
    return false;
  vector.removeLayer(index);
  return true;
}

bool Canevas::reset() {
  vector.~Vector();
  vector = Vector();
  activeLayer = NO_LAYER_ACTIVE;
  return true;
}

bool Canevas::resetLayer(int index) {
  if (vector.getLayer(index)->getStateLay() == STATE_ACTIVE)
    return false;
  return vector.getLayer(index)->reset();
}

bool Canevas::activateLayer(int index) {
  /*if (activeLayer != NO_LAYER_ACTIVE)*/
  /*  return false;*/
  deactivateLayer(activeLayer);
  activeLayer = index;
  return vector.getLayer(index)->setState(STATE_ACTIVE);
}

bool Canevas::deactivateLayer(int index) {
  if (index != activeLayer)
    return false;
  activeLayer = NO_LAYER_ACTIVE;
  return vector.getLayer(index)->setState(STATE_INACTIVE);
}

bool Canevas::addShape(Forme *p_forme) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  vector.getLayer(activeLayer)->addForme(p_forme);
  return true;
}

bool Canevas::retirerForme(int index) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  vector.getLayer(activeLayer)->removeForme(index);
  return true;
}

double Canevas::aire() {
  int areaSum{0};
  for (int i = 0; i < vector.getCurrentSize(); i++)
    areaSum += vector.getLayer(i)->getArea();
  return areaSum;
}

bool Canevas::translater(int deltaX, int deltaY) {
  if (activeLayer == NO_LAYER_ACTIVE)
    return false;
  return vector.getLayer(activeLayer)->translation(deltaX, deltaY);
}

void Canevas::afficher(ostream & s) {
  if (vector.getCurrentSize() == -1) {
    std::cout << "---- Aucune Couche ----\n";
    return;
  }

  for (int i = 0; i <= vector.getCurrentSize(); i++) {
    std::cout << "---- Couche " << i << " ----" << std::endl;
    std::cout << "Etat: ";

    switch (vector.getLayer(i)->getStateLay()) {
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

    if (vector.getLayer(i)->getIndex() == -1) {
      std::cout << "Couche: vide" << std::endl;
    } else {
      for (int j = 0; j < vector.getLayer(i)->getIndex(); j++)
        vector.getLayer(i)->getForme(j)->afficher(s);
    }
  }
}


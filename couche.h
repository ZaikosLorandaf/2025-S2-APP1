/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet, Sarah Gosselin
 * Date: 13 juin 2024 (creation)
 * Modifie par : Sarah Gosselin
 * Date : Jan 2025
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec
 *    les specifications de Graphicus. Ce fichier fait partie de
 *    la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H

#define STATE_INIT 0
#define STATE_ACTIVE 1
#define STATE_INACTIVE 2


#include "forme.h"

const int MAX_FORMES = 5;

class Layer {
  public:
    Layer();
    int getStateLay();
    bool addForme(Forme* f);
    Forme* removeForme(int index);
    Forme* getForme(int index);
    double getArea();
    bool translation(int deltaX, int deltaY);
    bool reset();
    bool setState(int s);
    int getIndex();
  private:
    Forme* formes[MAX_FORMES];
    int indexFormes;
    int state{0};
};

#endif

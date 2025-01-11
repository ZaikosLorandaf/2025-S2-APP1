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

#include "forme.h"

const int MAX_FORMES = 5;

class Couche {
  public:
    int addForme(Forme* f);
    int removeForme(int index);
    Forme* getForme(int index);
  private:
    Forme* formes[MAX_FORMES];
    int itsIndex {0};
};

#endif

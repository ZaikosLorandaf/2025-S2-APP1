/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe Canevas. La classe Canevas gere un
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"

#define NO_LAYER_ACTIVE -1

using namespace std;

class Canevas
{
  public:
    Canevas();
    ~Canevas();

    bool addLayerCan();
    bool removeLayerCan(int index);

    bool reset();
    bool resetLayer(int index);

    bool activateLayer(int index);
    bool deactivateLayer(int index);

    bool addShape(Forme *p_forme);
    bool retirerForme(int index);

    double aire();
    bool translater(int deltaX, int deltaY);
    void afficher(ostream & s);

  private:
    Vector vector;
    int activeLayer{-1};
};

#endif

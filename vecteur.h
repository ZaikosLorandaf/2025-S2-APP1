#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include "couche.h"
#include "forme.h"

#define INIT_VEC_SIZE 1

class Vecteur {
  public:
    Vecteur();
    ~Vecteur();
    bool addCouche(Couche* c);
    int getCurrentSize();
    void increaseSize();
    bool vider();
    Couche* removeCouche(int index);
    Couche* getCouche(int index);
    void destroyerOfLayers();
  private:
    Couche* itsCouches[INIT_VEC_SIZE]{NULL};
    int capacity{INIT_VEC_SIZE};
    int currentSizeIndex{0};
};

#endif

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
    bool removeCouche(int index);
  private:
    Couche* couches[INIT_VEC_SIZE]{nullptr};
    int capacity{INIT_VEC_SIZE};
    int currentSize{0};
};

#endif

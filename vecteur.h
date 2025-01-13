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
    bool removeCouche(int index);
    bool vider(int index);
    bool getCurrentIndex();
    void increaseSize();
  private:
    Couche* couches[INIT_VEC_SIZE]{nullptr};
    int capacity{INIT_VEC_SIZE};
    int currentSize{0};
};

#endif

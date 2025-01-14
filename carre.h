#ifndef __carre_H__
#define __carre_H__

#include "coordonnee.h"
#include "forme.h"
#include "rectangle.h"

class Carre: public Rectangle {
  public:
    Carre();
    Carre(Coordonnee xy, int l);
    Carre(int x, int y, int l);
    ~Carre();

    void afficher(ostream &s) override;
};
#endif

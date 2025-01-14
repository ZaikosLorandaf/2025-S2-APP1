#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"

class Cercle: public Forme {
  public:
    Cercle();
    Cercle(Coordonnee xy, int r);
    Cercle(int x, int y, int r);
    ~Cercle();

    int getRadius();
    void setRadius(int r);

    double aire() override;
    void afficher(ostream &s) override;
  private:
      int itsRadius;
      int itsX;
      int itsY;
};

#endif

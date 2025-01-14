#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "forme.h"

class Rectangle: public Forme {
  public:
    Rectangle();
    Rectangle(Coordonnee xy, int l, int w);
    Rectangle(int x, int y, int l, int w);
    ~Rectangle();

    int getLength();
    void setLength(int l);

    int getWidth();
    void setWidth(int w);

    double aire() override;

    void afficher(ostream &s) override;

  private:
    int itsLength;
    int itsWidth;
};
#endif

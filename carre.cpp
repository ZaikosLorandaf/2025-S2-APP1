#include "carre.h"
#include "rectangle.h"


Carre::Carre():Rectangle(){}
Carre::Carre(Coordonnee xy, int l):Rectangle(xy, l, l) {}
Carre::~Carre(){}



void Carre::afficher(ostream &s) {
  s << "Rectangle (x=" << getAncrage().x
    << ", y=" << getAncrage().y
    << ", aire=" << area(getLength(), getLength())
    << ")" << std::endl;
}



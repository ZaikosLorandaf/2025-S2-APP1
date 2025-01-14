#include "cercle.h"
#include <cmath>
#include <math.h>

Cercle::Cercle(){}
Cercle::Cercle(Coordonnee xy, int r):Forme(xy.x, xy.y) {
  setRadius(r);
}
Cercle::Cercle(int x, int y, int r):Forme(x, y) {
  setRadius(r);
}
Cercle::~Cercle(){};

int Cercle::getRadius() {
  return itsRadius;
}

void Cercle::setRadius(int r){
  itsRadius = r;
}

double Cercle::aire() {
  return itsRadius*itsRadius*M_PI;
}

void Cercle::afficher(ostream &s) {
  s << "Cercle ( x=" << getAncrage().x
    << ", y=" << getAncrage().y
    << ", r=" << getRadius()
    << ", aire=" << aire()
    << ")" << std::endl;
}

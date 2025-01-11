#include "cercle.h"
#include <cmath>
#include <math.h>

Cercle::Cercle(){}
Cercle::Cercle(Coordonnee xy, int r):Forme(xy.x, xy.y) {
  setRadius(r);
}
Cercle::~Cercle(){};

int Cercle::getRadius() {
  return itsRadius;
}

void Cercle::setRadius(int r){
  itsRadius = r;
}

double Cercle::area(int r) {
  return r*r*M_PI;
}

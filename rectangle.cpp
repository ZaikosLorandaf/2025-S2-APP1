#include "rectangle.h"

Rectangle::Rectangle(){
  setLength(1);
  setAncrage(ancrage);
}
Rectangle::Rectangle(Coordonnee xy, int l, int w):Forme(xy.x, xy.y) {
  setLength(l);
  setWidth(w);
}
Rectangle::Rectangle(int x, int y, int l, int w):Forme(x, y) {
  setLength(l);
  setWidth(w);
}
Rectangle::~Rectangle(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
int Rectangle::getLength() {
  return itsLength;
}

void Rectangle::setLength(int l) {
  itsLength = l;
}

int Rectangle::getWidth() {
  return itsWidth;
}

void Rectangle::setWidth(int w) {
  itsWidth = w;
}

double Rectangle::aire() {
  return itsLength * itsWidth;
}

void Rectangle::afficher(ostream &s) {
  s << "Rectangle (x=" << getAncrage().x
    << ", y=" << getAncrage().y
    << ", l=" << getLength()
    << ", h=" << getWidth()
    << ", aire=" << aire()
    << ")" << std::endl;
}

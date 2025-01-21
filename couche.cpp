#include "couche.h"
#include "forme.h"

Layer::Layer() {
  state = STATE_INIT;
}

int Layer::getStateLay() {
  return state;
}

bool Layer::addShapeLay(Shape* f) {
  if (sizeIndex >= MAX_FORMES-1)
    return false;
  sizeIndex++;
  formes[sizeIndex] = f;
  return true;
}

Shape* Layer::removeForme(int index) {
  if (index >= sizeIndex)
    return NULL;
  Shape* f = formes[index];
  for (int i = index; i <= sizeIndex; i++)
    formes[i] = formes[i+1];
  formes[sizeIndex] = NULL;
  sizeIndex--;
  return f;
}

Shape* Layer::getShapeLay(int index) {
  if (index > sizeIndex)
    return NULL;
  return formes[index];
}

double Layer::getArea() {
  double sum{0};
  for (int i = 0; i < sizeIndex; i++)
    sum += formes[i]->area();
  return sum;
}

bool Layer::translation(int deltaX, int deltaY) {
  for (int i = 0; i < sizeIndex; i++) {
    formes[i]->moveOrigin(deltaX, deltaY);
  };
  return true;
}

bool Layer::reset() {
  for (int i = 0; i < MAX_FORMES; i++)
    formes[i] = NULL;
  state = STATE_INIT;
  return true;
};

bool Layer::setState(int s) {
  if (s > 2 || s < 0)
    return false;
  state = s;
  return true;
}

int Layer::getIndex() {
  return sizeIndex;
}

/*void Layer::display(ostream &s) {*/
/**/
/*  s << "Etat: ";*/
/*  switch (state) {*/
/*    case 0:*/
/*      s << "Initialised\n";*/
/*      break;*/
/*    case 1:*/
/*      s << "Active\n";*/
/*      break;*/
/*    case 2:*/
/*      s << "Inactive\n";*/
/*      break;*/
/*  };*/
/**/
/*  if (sizeIndex == -1) {*/
/*    s << "Couche: vide" << std::endl;*/
/*  } else {*/
/*    for (int i = 0; i <= sizeIndex; i++)*/
/*      formes[i]->display(s);*/
/*  }*/
/*}*/

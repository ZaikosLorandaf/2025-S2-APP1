#include "vecteur.h"
#include "couche.h"

Vecteur::Vecteur() {
  Couche* couches = new Couche[capacity];
}

Vecteur::~Vecteur() {
  vider();
  delete[] *couches;
}

bool Vecteur::addCouche(Couche* c) {
  if (c == NULL)
    return false;
  if (currentSize == capacity)
    increaseSize();
  capacity++;
  couches[capacity] = c;
  return true;
}

void Vecteur::increaseSize() {
  capacity *= 2;
  Couche* newCouche = new Couche[capacity];
  for (int i = 0; i <= currentSize; i++)
    newCouche[i] = *couches[i];
  *couches = newCouche;
  delete[] newCouche;
}

int Vecteur::getCurrentSize() {
  return currentSize;
}

bool Vecteur::vider() {
  for (int i = 0; i < currentSize; i++)
    couches[i] = NULL;
  capacity = INIT_VEC_SIZE;
  Couche* newCouche = new Couche[capacity];
  *couches = newCouche;
  delete[] newCouche;
  return true;
}

#include "vecteur.h"

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
  couches* = newCouche;
  delete[] newCouche;
}


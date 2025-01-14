#include "vecteur.h"
#include "couche.h"

Vecteur::Vecteur() {
  Couche* couches = new Couche[capacity];
}

Vecteur::~Vecteur() {
  vider();
  delete[] *itsCouches;
}

bool Vecteur::addCouche(Couche* c) {
  if (c == NULL)
    return false;
  if (currentSizeIndex == capacity)
    increaseSize();
  currentSizeIndex++;
  itsCouches[currentSizeIndex] = c;
  return true;
}

void Vecteur::increaseSize() {
  capacity *= 2;
  Couche* newCouche = new Couche[capacity];
  for (int i = 0; i <= currentSizeIndex; i++)
    newCouche[i] = *itsCouches[i];
  *itsCouches = newCouche;
  delete[] newCouche;
}

int Vecteur::getCurrentSize() {
  return currentSizeIndex;
}

bool Vecteur::vider() {
  for (int i = 0; i < currentSizeIndex; i++)
    itsCouches[i] = NULL;
  capacity = INIT_VEC_SIZE;
  Couche* newCouche = new Couche[capacity];
  *itsCouches = newCouche;
  delete[] newCouche;
  return true;
}

Couche* Vecteur::removeCouche(int index) {
  if (index < 0 || index > currentSizeIndex)
    return NULL;
  Couche* c = itsCouches[index];
  if (index == currentSizeIndex) {
    itsCouches[index] = NULL;
    return c;
  }
  for (int i = index; i < currentSizeIndex; i++)
    itsCouches[i] = itsCouches[i+1];
  itsCouches[currentSizeIndex] = NULL;
  currentSizeIndex--;
  return c;
}

Couche* Vecteur::getCouche(int index) {
  return itsCouches[index];
}


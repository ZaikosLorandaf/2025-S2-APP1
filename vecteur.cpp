#include "vecteur.h"

Vector::Vector() {
  capacity = INIT_VEC_SIZE;
  currentMaxIndex = -1; // Since indexes at every layer added
  vector = new Layer*[capacity];
}
Vector::~Vector() {
  vider();
  delete[] vector;
}


bool Vector::addLayerVec(Layer* c) {
  if (c == NULL)
    return false;
  if (currentMaxIndex == capacity)
    increaseSize();
  vector[currentMaxIndex] = c;
  currentMaxIndex++;
  return true;
}

void Vector::increaseSize() {
  capacity *= 2;
  Layer newCouche[capacity];
  for (int i = 0; i <= currentMaxIndex; i++)
    newCouche[i] = *vector[i];
  *vector = newCouche;
}

int Vector::getCurrentSize() {
  return currentMaxIndex;
}

bool Vector::vider() {
  for (int i = 0; i < currentMaxIndex; i++)
    vector[i] = NULL;
  capacity = INIT_VEC_SIZE;
  Layer* newCouche = new Layer[capacity];
  *vector = newCouche;
  delete[] newCouche;
  return true;
}

Layer* Vector::removeLayer(int index) {
  if (index < 0 || index > currentMaxIndex)
    return NULL;
  Layer* c = vector[index];
  if (index == currentMaxIndex) {
    vector[index] = NULL;
    return c;
  }
  for (int i = index; i < currentMaxIndex; i++)
    vector[i] = vector[i+1];
  vector[currentMaxIndex] = NULL;
  currentMaxIndex--;
  return c;
}

Layer* Vector::getLayer(int index) {
  return vector[index];
}


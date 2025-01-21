#include "vecteur.h"

MyVector::MyVector() {
  capacity = INIT_VEC_SIZE;
  currentMaxIndex = -1; // Start with empty vector
  vector = new Layer*[capacity];
}

MyVector::~MyVector() {
  vider();
  delete[] vector;
}

bool MyVector::addLayerVec(Layer* c) {
  if (c == NULL)
    return false;
  if (currentMaxIndex == capacity-1)
    increaseSize();
  currentMaxIndex++;
  vector[currentMaxIndex] = c;
  return true;
}

void MyVector::increaseSize() {
  capacity *= 2;
  Layer** newTemp = new Layer*[capacity];
  for (int i = 0; i <= currentMaxIndex; i++)
    newTemp[i] = vector[i];
  delete[] vector;
  vector = newTemp;
}

int MyVector::getCurrentSize() {
  return currentMaxIndex;
}

bool MyVector::vider() {
  for (int i = 0; i < currentMaxIndex; i++)
    vector[i] = NULL;
  capacity = INIT_VEC_SIZE;
  Layer* newCouche = new Layer[capacity];
  *vector = newCouche;
  delete[] newCouche;
  return true;
}

Layer* MyVector::removeLayer(int index) {
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

Layer* MyVector::getLayer(int index) {
  return vector[index];
}


/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Sarah Gosselin
 * Date : Jan 2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

int Couche::addForme(Forme* f) {
  if (itsIndex > MAX_FORMES)
    return 1;
  formes[itsIndex] = f;
  return 0;
}

int Couche::removeForme(int index) {
  if (index >= itsIndex)
    return 1;
  for (int i = index; i < index; i++)
    formes[i] = formes[i+1];
  return 0;
}

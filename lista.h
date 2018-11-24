#ifndef LISTA_H
#define LISTA_H
#include "nodolista.h"

template <class T>
class Lista {
    NodoLista<T> *cabeza;
public:
    Lista<T>(){ cabeza= nullptr ;}

  void Insertar(T dato);

  int Longitud();

  T getI(int i);

};
#endif

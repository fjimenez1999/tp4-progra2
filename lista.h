#ifndef LISTA_H
#define LISTA_H
using namespace std;
#include "nodolista.h"

template <class T>
class Lista {
    NodoLista<T> *cabeza ;
public:
    Lista<T>(){ cabeza= nullptr ;}

  void Insertar(T dato) {
    NodoLista<T>* n = new NodoLista<T>(dato) ;
    NodoLista<T>* t= cabeza ;
    cabeza = n ;
    cabeza->setSiguiente(t);
  }

  int Longitud() {
    NodoLista<T> *n= cabeza ;
    int c=0 ;
    while (n!=nullptr){
        c++;
        n= n->getSiguiente();
    }
    return c;
  }

  T getI(int i) {
    NodoLista<T> *n= cabeza ;
    int c=0 ;
    while (n!=nullptr&& c<i){
        c++;
        n= n->getSiguiente();
    }
    return n!=nullptr?n->getDato():nullptr;
  }

};
#endif

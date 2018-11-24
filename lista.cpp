#include "lista.h"
template<class T>
void Lista<T>::Insertar(T dato) {
    if(cabeza == nullptr){
         NodoLista<T> *n = new NodoLista<T>(dato);
         cabeza = n;
    }else if(cabeza != nullptr){
        NodoLista<T>* nodoActual = cabeza;
        while(nodoActual->getSiguiente() != nullptr){
            nodoActual = nodoActual->getSiguiente();
        }
        NodoLista<T>* n = new NodoLista<T>(dato);
        nodoActual->setSiguiente(n);
    }
}

template<class T>
int Lista<T>::Longitud() {
  NodoLista<T> *n= cabeza ;
  int c=0 ;
  while (n!=nullptr){
      c++;
      n= n->getSiguiente();
  }
  return c;
}

template<class T>
T Lista<T>::getI(int i) {
  NodoLista<T> *n= cabeza ;
  int c=0 ;
  while(n!=nullptr && c<i){
      n = n->getSiguiente();
      c++;
  }
  return n!=nullptr?n->getDato():nullptr;
}

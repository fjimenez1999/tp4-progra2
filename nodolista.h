#ifndef NODOLISTA_H
#define NODOLISTA_H

template <class T>
class NodoLista {
    T dato;
    NodoLista<T>* siguiente = nullptr;
public:
    NodoLista(T d){
        dato= d ;
        siguiente= nullptr;
    }

    T getDato() {return dato ;}
    void setSiguiente(NodoLista<T> *s) {siguiente= s ;}
    NodoLista<T>* getSiguiente() {return siguiente;}
};
#endif

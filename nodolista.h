#pragma once
#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include <QTextStream>
using namespace std;

template <class T>
class NodoLista {
    T dato ;
    NodoLista<T>* siguiente ;
public:
    NodoLista(T d){
        dato= d ;
        siguiente= nullptr;
    }

    T getDato() {
        return dato ;
    }
    void setSiguiente(NodoLista<T> *s) {
        siguiente= s ;
    }
    NodoLista<T>* getSiguiente() {return siguiente;}
};
#endif

#ifndef REDNEURONAL_H
#define REDNEURONAL_H
#include "capa.h"
class RedNeuronal{
    Lista<Capa*> *capas ;
    RedNeuronal() ;
    int AgregarCapa(int cNeuronas) ;
    //Categoria clasificar(dato) ;
    void Entrenar(int datos) ;
};
#endif // REDNEURONAL_H

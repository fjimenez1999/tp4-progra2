#ifndef CAPA_H
#define CAPA_H
#include "neurona.h"
class Capa{

    Lista<Neurona*> *neuronas;
public:
    Capa(int cNeuronas);
    int AgregarNeurona(Neurona *neurona) ;
};
#endif // CAPA_H

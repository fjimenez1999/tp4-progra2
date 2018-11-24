#ifndef CAPA_H
#define CAPA_H
#include "neurona.h"
class Capa{
    Lista<Neurona*> *neuronas = new Lista<Neurona*>;
public:
    Capa(int cNeuronas);
    int AgregarNeurona() ;
    void ModificarCapa(float nuevaCarga, int posicion);
    int CantidadNeuronas();
    Neurona* ConsultarNeurona(int indice);
};
#endif // CAPA_H

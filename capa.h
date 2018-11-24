#ifndef CAPA_H
#define CAPA_H
#include "neurona.h"
class Capa{

    Lista<Neurona*> *neuronas;
public:
    Capa(int cNeuronas);
    int AgregarNeurona(char tipo , float carga, float umbral) ;
    void ModificarCapa(float nuevaCarga, int posicion);
    int CantidadNeuronas();
    Neurona* ConsultarNeurona(int indice);
};
#endif // CAPA_H

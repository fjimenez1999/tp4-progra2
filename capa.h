#ifndef CAPA_H
#define CAPA_H
#include "neurona.h"
#include <QTime>
class Capa{
    Lista<Neurona*> *neuronas = new Lista<Neurona*>;
public:
    Capa(int cNeuronas,uint seed1, uint seed2);
    int AgregarNeurona(uint seed1,uint seed2) ;
    void ModificarCapa(float nuevaCarga, int posicion);
    int CantidadNeuronas();
    Neurona* ConsultarNeurona(int indice);
};
#endif // CAPA_H

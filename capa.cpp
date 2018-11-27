#include "capa.h"
Capa::Capa(int cNeuronas){
    for(int i = 0; i < cNeuronas; i++){
        AgregarNeurona();
    }
}

int Capa::AgregarNeurona(){
    Neurona *n = new Neurona();
    neuronas->Insertar(n);
    return 0;
}

void Capa::ModificarCapa(double nuevaCarga, int posicion){
    neuronas->getI(posicion)->ModificarCarga(nuevaCarga);
}

int Capa::CantidadNeuronas(){
    return neuronas->Longitud();
}

Neurona* Capa::ConsultarNeurona(int indice){
    return neuronas->getI(indice);
}

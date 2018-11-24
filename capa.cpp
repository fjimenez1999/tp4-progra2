#include "capa.h"
Capa::Capa(int cNeuronas){
    for(int i = 0; i < cNeuronas; i++){
        AgregarNeurona('r',0,0);
    }
}

int Capa::AgregarNeurona(char tipo , float carga, float umbral){
    Neurona *n = new Neurona(tipo,carga,umbral);
    neuronas->Insertar(n);
    return 0;
}

void Capa::ModificarCapa(float nuevaCarga, int posicion){
    neuronas->getI(posicion)->ModificarCarga(nuevaCarga);
}

int Capa::CantidadNeuronas(){
    return neuronas->Longitud();
}

Neurona* Capa::ConsultarNeurona(int indice){
    Neurona* consultada = nullptr;
    if(indice < neuronas->Longitud() && indice >= 0){
        consultada = neuronas ->getI(indice);
    }
    return consultada;
}

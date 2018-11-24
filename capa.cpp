#include "capa.h"
Capa::Capa(int cNeuronas,uint seed1,uint seed2){
    for(int i = 0; i < cNeuronas; i++){
        AgregarNeurona(seed1,seed2);
        seed1++;
        seed2++;
    }
}

int Capa::AgregarNeurona(uint seed1, uint seed2){
    Neurona *n = new Neurona(seed1,seed2);
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
    Neurona* consultada = neuronas->getI(indice);
    /*if(indice < neuronas->Longitud() && indice >= 0){
        consultada = neuronas ->getI(indice);
    }*/
    return neuronas->getI(indice);
}

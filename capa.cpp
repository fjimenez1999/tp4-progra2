#ifndef CAPA_CPP
#define CAPA_CPP
#include "capa.h"
Capa::Capa(int cNeuronas){
    for(int i = 0; i < cNeuronas; i++){
        Neurona *n = new Neurona();
        AgregarNeurona(n);
    }
}

int Capa::AgregarNeurona(Neurona *neurona){
   neuronas->Insertar(neurona);
}

#endif // CAPA_CPP

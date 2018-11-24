#include "conexion.h"
#include "neurona.h"
Neurona::Neurona(uint seed1,uint seed2){
        QRandomGenerator *random1 =  new QRandomGenerator(seed1);
        QRandomGenerator *random2 =  new QRandomGenerator(seed2);
        this->carga=random1->bounded(1.00);
        this->umbral=random2->bounded(1.00);
}

void Neurona::AgregarConexion(Neurona *receptora,uint seed){
   Conexion *c =  new Conexion(receptora,seed);
   conexiones->Insertar(c);

}

void Neurona::ModificarCarga(float nuevaCarga){
    carga = nuevaCarga;
}

int Neurona::CantidadConexiones(){
    return conexiones->Longitud();
}
Conexion* Neurona::ConsultarConexion(int indice){
    return conexiones->getI(indice);
}


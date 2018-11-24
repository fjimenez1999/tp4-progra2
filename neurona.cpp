#include "conexion.h"
#include "neurona.h"
Neurona::Neurona(){
        QRandomGenerator *random1 =  new QRandomGenerator((uint) QTime::currentTime().msec());
        QRandomGenerator *random2 =  new QRandomGenerator((uint) QTime::currentTime().second());
        this->carga=random1->bounded(1.00);
        this->umbral=random2->bounded(1.00);
}

int Neurona::AgregarConexion(Neurona *receptora){
   Conexion *c =  new Conexion(receptora);
   conexiones->Insertar(c);
   return 0;
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


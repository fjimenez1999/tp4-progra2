#include "conexion.h"
#include "neurona.h"

Neurona::Neurona(){
        double random1 =  qrand();
        double random2 =  qrand();
        this->carga=random1/RAND_MAX*10000;
        this->carga-=(int)carga;
        this->umbral=random2/RAND_MAX*10000;
        this->umbral-=(int)umbral;
}

void Neurona::AgregarConexion(Neurona *receptora){
   Conexion *c =  new Conexion(receptora);
   conexiones->Insertar(c);

}

void Neurona::ModificarCarga(double nuevaCarga){
    carga = nuevaCarga;
}

int Neurona::CantidadConexiones(){
    return conexiones->Longitud();
}
Conexion* Neurona::ConsultarConexion(int indice){
    return conexiones->getI(indice);
}

void Neurona::ModificarPeso(int indice,double nuevoPeso){
    conexiones->getI(indice)->SetPeso(nuevoPeso);
}

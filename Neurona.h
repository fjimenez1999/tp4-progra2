#pragma once
#include "conexion.h"
#include "lista.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <QTime>

class Conexion;


class Neurona{
    double carga;
    double umbral;
    Lista<Conexion*> *conexiones = new Lista<Conexion*>;
public:
    void AgregarConexion(Neurona *receptora) ;
    Neurona();
    void ModificarCarga(double nuevaCarga);
    int CantidadConexiones();
    Conexion* ConsultarConexion(int indice);
    double GetUmbral(){return umbral;}
    double GetCarga(){return carga;}
    void ModificarPeso(int indice,double nuevoPeso);
};


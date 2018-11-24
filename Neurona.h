#pragma once

#include "conexion.h"
#include "lista.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <QRandomGenerator>
#include <QTime>

class Conexion;


class Neurona{
    float carga;
    float umbral;
    Lista<Conexion*> *conexiones = new Lista<Conexion*>;
public:
    void AgregarConexion(Neurona *receptora,uint seed) ;
    Neurona(uint seed1,uint seed2);
    void ModificarCarga(float nuevaCarga);
    int CantidadConexiones();
    Conexion* ConsultarConexion(int indice);
    float GetUmbral(){return umbral;}
    float GetCarga(){return carga;}
};



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
    int AgregarConexion(Neurona *receptora) ;
    Neurona();
    void ModificarCarga(float nuevaCarga);
    int CantidadConexiones();
    Conexion* ConsultarConexion(int indice);
    float GetUmbral(){return umbral;}
    float GetCarga(){return carga;}
};



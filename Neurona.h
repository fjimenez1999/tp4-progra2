#pragma once

#include "conexion.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <QRandomGenerator>
#include <QTime>

class Conexion;


class Neurona{
    float carga;
    float umbral;
    Lista<Conexion*> *conexiones;
public:
    int AgregarConexion(Neurona *receptora) ;
    Neurona(char tipo, float carga, float umbral);
    void ModificarCarga(float nuevaCarga);
    int CantidadConexiones();
    Conexion* ConsultarConexion(int indice);
    float GetUmbral(){return umbral;}
    float GetCarga(){return carga;}
};



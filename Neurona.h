#pragma once
#ifndef NEURONA_H
#define NEURONA_H
#include "conexion.h"
#include "lista.h"
class Neurona{
    float carga;
    float umbral;
    Lista<Conexion> *conexiones;
    int AgregarConexión(Neurona neurona, float peso) ;
};
#endif


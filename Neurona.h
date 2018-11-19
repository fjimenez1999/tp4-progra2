#pragma once //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once

#include "conexion.h"
#include "lista.h"
class Neurona{
    float carga;
    float umbral;
    Lista<Conexion> *conexiones;
public:
    int AgregarConexion(Neurona *neurona, float peso) ;
};



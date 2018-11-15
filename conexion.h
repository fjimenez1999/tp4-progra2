#pragma once
#ifndef CONEXION_H
#define CONEXION_H
#include "neurona.h"
class Conexion {
    Neurona r ;
    float peso ;
    Conexion(Neurona neurona, int peso);
};
#endif // CONEXION_H

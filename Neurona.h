#pragma once

#include "conexion.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <QRandomGenerator>
#include <QTime>

class Conexion;


class Neurona{
    QRandomGenerator *random1 =  new QRandomGenerator((uint) QTime::currentTime().msec());
    QRandomGenerator *random2 =  new QRandomGenerator((uint) QTime::currentTime().second());
    float carga = random1->bounded(1.00);
    float umbral = random2->bounded(1.00);
    Lista<Conexion> *conexiones;
public:
    int AgregarConexion(Neurona *neurona, float peso) ;
};



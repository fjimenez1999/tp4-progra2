
#pragma once  //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once
#include "neurona.h"
#include <QRandomGenerator>
#include <QTime>
class Neurona;
class Conexion {
    QRandomGenerator *random1 =  new QRandomGenerator((uint) QTime::currentTime().msec());
    Neurona *r = nullptr;
    float peso = random1->bounded(1.00);
public:
    Conexion(Neurona *neurona=nullptr){
        r=neurona;
    }
    void ModificarPeso(float nuevoPeso){
        peso = nuevoPeso;
    }
    float GetPeso(){
        return peso;
    }
    Neurona* GetReceptor(){
        return r;
    }

    Neurona* SetReceptor(Neurona* nr){
        r = nr;
    }
};

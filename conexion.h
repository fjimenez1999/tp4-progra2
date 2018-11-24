
#pragma once  //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once
#include "neurona.h"
#include <QRandomGenerator>
#include <QTime>
class Neurona;
class Conexion {
    uint seed;
    QRandomGenerator *random1;
    Neurona *r = nullptr;
    float peso;
public:
    Conexion(Neurona *neurona=nullptr,uint seed=(uint) QTime::currentTime().msec()){
        r=neurona;
        this->seed = seed;
        random1 = new QRandomGenerator(seed);
        peso = random1->bounded(1.00);
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

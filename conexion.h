#pragma once  //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once
#include "neurona.h"
#include <QTime>
class Neurona;
class Conexion {
    Neurona *r = nullptr;
    double peso;
public:
    Conexion(Neurona *neurona=nullptr){
        r=neurona;
        double random1 = qrand();
        peso = random1/RAND_MAX;
    }
    void ModificarPeso(double nuevoPeso){
        peso = nuevoPeso;
    }
    double GetPeso(){
        return peso;
    }
    Neurona* GetReceptor(){
        return r;
    }

    Neurona* SetReceptor(Neurona* nr){
        r = nr;
    }

    void SetPeso(double nuevoPeso){
        peso = nuevoPeso;
    }
};

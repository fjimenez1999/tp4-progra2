#pragma once //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once
#include "neurona.h"
class Conexion {
    Neurona *r ;
    float peso ;
public:
    Conexion(Neurona *neurona, float peso){
        r=neurona;
        this->peso=peso;
    }
};

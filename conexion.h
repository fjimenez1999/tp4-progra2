
#pragma once  //qt estaba tirando un error al usar include guards normales en archivos especificos, por eso pragma once
#include "neurona.h"
#include <QRandomGenerator>
#include <QTime>
class Neurona;
class Conexion {
    QRandomGenerator *random1 =  new QRandomGenerator((uint) QTime::currentTime().msec());
    Neurona *r ;
    float peso = random1->bounded(1.00);
public:
    Conexion(Neurona *neurona=nullptr, float peso=0){
        r=neurona;
        this->peso=peso;
    }
};

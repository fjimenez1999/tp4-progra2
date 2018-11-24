#ifndef REDNEURONAL_H
#define REDNEURONAL_H
#include "capa.h"
#include <QVector>
class RedNeuronal{   
    Lista<Capa*> *capas ;
    void RevisarCapa(int capa);
    void CrearConexiones();
public:
    RedNeuronal(QVector<int>* vector,int capas) ;
    int AgregarCapa(int cNeuronas) ;
    int AgregarCapa(Capa* capa);
    //Categoria clasificar(dato) ;
    void Entrenar(QVector<int>* datos) ;
    QVector<float>* Output();
    //metodo para crear conexiones entre todas las neuronas de la capa que sigue
};
#endif // REDNEURONAL_H

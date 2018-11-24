#ifndef REDNEURONAL_H
#define REDNEURONAL_H
#include "capa.h"
#include <QVector>
class RedNeuronal{   
    Lista<Capa*> *capas = new Lista<Capa*>;
    void RevisarCapa(int capa);
    void CrearConexiones();//metodo para crear conexiones entre todas las capas con la capa que sigue
public:
    RedNeuronal(QVector<int>* vector,int capas) ;
    int AgregarCapa(int cNeuronas) ;
    int AgregarCapa(Capa* capa);
    //Categoria clasificar(dato) ;
    void Entrenar(QVector<int>* datos) ;
    QVector<float>* Output();
    void CorregirCapas(float error);
    float CalcularError(float dato,float datoEsperado);
    QString MostrarRed();
};
#endif // REDNEURONAL_H

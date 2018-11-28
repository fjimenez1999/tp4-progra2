#include "texto.h"

Texto::Texto(QString nuevoTxt){
    txt = nuevoTxt;
}

QVector<int>* Texto::EncontrarRepetidas(){
    QVector<int>* cantidades = new QVector<int>;
    QStringList palabras = txt.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    std::sort(palabras.begin(),palabras.end());
    int contadas = 0;
    if(palabras.size() != 0){
        int cantidadPalabras = 1;
        QString palabra = palabras.at(0);
        for(int i = 1; i < palabras.count();i++){
            if(palabra != palabras.at(i) ){
                cantidades->append(cantidadPalabras);
                cantidadPalabras = 0;
                palabra = palabras.at(i);
                contadas++;
            }
            ++cantidadPalabras;
            if(i+1 == palabras.count()){
                cantidades->append(cantidadPalabras);
                cantidadPalabras = 0;
                palabra = palabras.at(i);
                contadas++;
            }
        }
    }
    return cantidades;
}

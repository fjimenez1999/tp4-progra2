#ifndef TEXTO_H
#define TEXTO_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <QtAlgorithms>

class Texto
{
    QString txt;
public:
    Texto(QString nuevoTxt);
    QVector<int>* EncontrarRepetidas();
};

#endif // TEXTO_H

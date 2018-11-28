
#include "redneuronal.h"
RedNeuronal::RedNeuronal(QVector<int>* vector, int capas){
    uint seed = (uint) QTime::currentTime().msec() ;
    srand(seed);
    for(int i = 0; i < capas ; i++){
        Capa* c = new Capa(vector->at(i));
        this->capas->Insertar(c);
    }
    CrearConexiones();
}

void RedNeuronal::Entrenar(QVector<int>* datos){ //para meter los inputs
    for(int i = 0 ; i < capas->getI(0)->CantidadNeuronas(); i++){
        capas->getI(0)->ModificarCapa((double)datos->at(i)/100,i);
    }
}

QVector<double>* RedNeuronal::Output(){ //da el resultado
    for(int i = 0 ; i < capas->Longitud(); i++){
        RevisarCapa(i);
    }
    QVector<double>* vector = new QVector<double>;
    for(int i = 0; i < capas->getI(capas->Longitud()-1)->CantidadNeuronas() ; i++){
        vector->append(capas->getI(capas->Longitud()-1)->ConsultarNeurona(i)->GetCarga());
    }
    return vector;
}

void RedNeuronal::RevisarCapa(int capa){//se utiliza en el metodo output
    Capa *capaActual = capas->getI(capa);
    for(int i = 0 ; i < capaActual->CantidadNeuronas(); i++){
        for(int j = 0; j < capaActual->ConsultarNeurona(i)->CantidadConexiones();j++){
              double umbralReceptor = capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetReceptor()->GetUmbral();
              Neurona* receptor = capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetReceptor();
              if(capaActual->ConsultarNeurona(i)->GetCarga() >= umbralReceptor){
                    double nuevaCarga = (receptor->GetCarga()) + (capaActual->ConsultarNeurona(i)->GetCarga()*capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetPeso())/100;
                    receptor->ModificarCarga(nuevaCarga);
              }
        }
    }
}

void RedNeuronal::CrearConexiones(){//crea las conexiones entre las capas
    for(int i = 0 ; i < capas->Longitud(); i++){
        if(i%1 == 0){
            Capa *capaActual = capas->getI(i);
            int nuevaCapa = i+1;
            Capa *capaSig = capas->getI(nuevaCapa);
            for(int i = 0 ; i < capaActual->CantidadNeuronas(); i++){
                if(capaSig != nullptr){
                    for(int j = 0; j <  capaSig->CantidadNeuronas();j++){
                        capaActual->ConsultarNeurona(i)->AgregarConexion(capaSig->ConsultarNeurona(j));
                    }
                }
            }
        }

    }
}

double RedNeuronal::CalcularError(double dato,double datoEsperado){
    //1-el valor absoluto
    double error = datoEsperado-dato;
    if(error == -1){
        error = 0;
    }
    return 1+error;
}

void RedNeuronal::CorregirCapas(double error){
    ModificarPesos(error);
}

QString RedNeuronal::MostrarRed(){
    QString red = "";
    for(int i = 0 ; i < capas->Longitud(); i++){
        red.append("Capa: ");
        red.append(QString::number(i));
        red.append("\n");
        for(int j = 0 ; j < capas->getI(i)->CantidadNeuronas();j++){
            red.append("Neurona: ");
            red.append(QString::number(j));
            red.append("\n");
            red.append("Carga: ");
            red.append(QString::number(capas->getI(i)->ConsultarNeurona(j)->GetCarga()));
            red.append(" Umbral: ");
            red.append(QString::number(capas->getI(i)->ConsultarNeurona(j)->GetUmbral()));
            red.append(" Cantidad de conexiones:");
            red.append(QString::number(capas->getI(i)->ConsultarNeurona(j)->CantidadConexiones()));
            red.append("\n");
            for(int k = 0; k < capas->getI(i)->ConsultarNeurona(j)->CantidadConexiones();k++){
                red.append("Conexion: ");
                red.append(QString::number(k));
                red.append("\n");
                red.append("Peso: ");
                red.append(QString::number(capas->getI(i)->ConsultarNeurona(j)->ConsultarConexion(k)->GetPeso()));
                red.append("\n");
            }
            red.append("\n");
        }
    }
    return red;
}

void RedNeuronal::ModificarPesos(double nuevoPeso){//modifica todos los pesos de las conexiones a partir del error
    for(int i =0 ; i < capas->Longitud() ; i++){
        for(int j = 0 ; j < capas->getI(i)->CantidadNeuronas() ; j++){
            for(int k = 0;k< capas->getI(i)->ConsultarNeurona(j)->CantidadConexiones(); k++){
                capas->getI(i)->ConsultarNeurona(j)->ModificarPeso(k,capas->getI(i)->ConsultarNeurona(j)->ConsultarConexion(k)->GetPeso()*nuevoPeso);
            }
        }
    }
}

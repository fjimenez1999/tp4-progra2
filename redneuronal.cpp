#include "redneuronal.h"
RedNeuronal::RedNeuronal(QVector<int>* vector, int capas){
    uint seed1 = (uint) QTime::currentTime().msec();
    uint seed2 = (uint) QTime::currentTime().second();
    for(int i = 0; i < capas ; i++){
        Capa* c = new Capa(vector->at(i),seed1,seed2);
        this->capas->Insertar(c);
        seed1+=5;
        seed2+=5;
    }
    CrearConexiones();
}

void RedNeuronal::Entrenar(QVector<int>* datos){ //para meter los inputs
    if(datos->size() == capas->getI(1)->CantidadNeuronas()){
        for(int i = 0 ; i < capas->getI(1)->CantidadNeuronas(); i++){
            capas->getI(1)->ModificarCapa(datos->at(i)/100,i);
        }
    }
}

QVector<float>* RedNeuronal::Output(){
    for(int i = 0 ; i < capas->Longitud(); i++){
        RevisarCapa(i);
    }
    QVector<float>* vector = nullptr;
    for(int i = 0; i < capas->getI(capas->Longitud()-1)->CantidadNeuronas() ; i++){
        vector->append(capas->getI(capas->Longitud()-1)->ConsultarNeurona(i)->GetCarga());
    }
    return vector;
}

void RedNeuronal::RevisarCapa(int capa){
    Capa *capaActual = capas->getI(capa);
    for(int i = 0 ; i < capaActual->CantidadNeuronas(); i++){
        for(int j = 0; j < capaActual->ConsultarNeurona(i)->CantidadConexiones();j++){
              float umbralReceptor = capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetReceptor()->GetUmbral();
              Neurona* receptor = capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetReceptor();
              if(capaActual->ConsultarNeurona(i)->GetCarga() >= umbralReceptor){
                    float nuevaCarga = (receptor->GetCarga()) + (capaActual->ConsultarNeurona(i)->GetCarga()*capaActual->ConsultarNeurona(i)->ConsultarConexion(j)->GetPeso());
                    receptor->ModificarCarga(nuevaCarga);
              }
        }
    }
}

void RedNeuronal::CrearConexiones(){
    uint seed = (uint) QTime::currentTime().minute();
    for(int i = 0 ; i < capas->Longitud(); i++){
        if(i%1 == 0){
            Capa *capaActual = capas->getI(i);
            int nuevaCapa = i+1;
            Capa *capaSig = capas->getI(nuevaCapa);
            for(int i = 0 ; i < capaActual->CantidadNeuronas(); i++){
                if(capaSig != nullptr){
                    for(int j = 0; j <  capaSig->CantidadNeuronas();j++){
                        capaActual->ConsultarNeurona(i)->AgregarConexion(capaSig->ConsultarNeurona(j),seed);
                        seed++;
                    }
                }
            }
        }

    }
}

float RedNeuronal::CalcularError(float dato,float datoEsperado){
    return datoEsperado-dato;
}

void RedNeuronal::CorregirCapas(float error){
    for(int i = 0; i < capas->Longitud(); i++){
        for(int j = 0 ; j < capas->getI(i)->CantidadNeuronas();j++){
           Neurona *n =  capas->getI(i)->ConsultarNeurona(j);
           n->ModificarCarga(n->GetCarga()+error);
        }
    }
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

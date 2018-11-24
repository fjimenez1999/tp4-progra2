#include "redneuronal.h"
RedNeuronal::RedNeuronal(QVector<int>* vector, int capas){
    if(vector->size() == capas){
        for(int i = 0; i < capas ; i++){
            Capa* c = new Capa(vector->at(i));
            this->capas->Insertar(c);
        }
        CrearConexiones();
    }
}

int RedNeuronal::AgregarCapa(int cNeuronas){
    Capa *c = new Capa(cNeuronas);
    capas->Insertar(c);
    return 0;
}

int RedNeuronal::AgregarCapa(Capa* capa){
    capas->Insertar(capa);
    return 0;
}

void RedNeuronal::Entrenar(QVector<int>* datos){
    if(datos->size() == capas->getI(1)->CantidadNeuronas()){
        for(int i = 0 ; i < capas->getI(1)->CantidadNeuronas(); i++){
            capas->getI(1)->ModificarCapa(datos->at(i),i);
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
    for(int i = 0 ; i < capas->Longitud(); i++){
        Capa *capaActual = capas->getI(i);
        Capa *capaSig = capas->getI(++i);
        for(int i = 0 ; i < capaActual->CantidadNeuronas(); i++){
            if(capaSig != nullptr){
                for(int j = 0; j <  capaSig->CantidadNeuronas();j++){
                    capaActual->ConsultarNeurona(i)->AgregarConexion(capaSig->ConsultarNeurona(j));
                }
            }
        }
    }
}



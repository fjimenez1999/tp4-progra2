#include "redneuronal.h"
int RedNeuronal::AgregarCapa(int cNeuronas){
    Capa *c = new Capa(cNeuronas);
    capas->Insertar(c);
}

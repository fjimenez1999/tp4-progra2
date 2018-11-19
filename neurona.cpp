#include "conexion.h"
#include "neurona.h"
int Neurona::AgregarConexion(Neurona *neurona, float peso){
   Conexion c(neurona,peso);
   conexiones->Insertar(c);
   return 0;
}

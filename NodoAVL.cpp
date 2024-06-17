#include "NodoAVL.h"

NodoAVL::NodoAVL(Transaccion* transaccion) 
    : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr), altura(1) {}

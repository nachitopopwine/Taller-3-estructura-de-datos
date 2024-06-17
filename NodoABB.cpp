#include "NodoABB.h"

NodoABB::NodoABB(Transaccion* transaccion) 
    : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr) {}

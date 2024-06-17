#pragma once
#include "Transaccion.h"

class NodoABB {
public:
    Transaccion* transaccion;
    NodoABB* izquierdo;
    NodoABB* derecho;

    NodoABB(Transaccion* transaccion);
};

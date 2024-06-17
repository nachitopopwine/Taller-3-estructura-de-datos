#pragma once
#include "Transaccion.h"

class NodoAVL {
public:
    Transaccion* transaccion;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(Transaccion* transaccion);
};

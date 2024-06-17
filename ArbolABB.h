#pragma once
#include "NodoABB.h"
#include <iostream>

class ArbolABB {
private:
    NodoABB* raiz;

    NodoABB* insertarNodo(NodoABB* nodo, Transaccion* transaccion);
    void inOrden(NodoABB* nodo);

public:
    ArbolABB();
    void insertar(Transaccion* transaccion);
    void mostrarInOrden();
};

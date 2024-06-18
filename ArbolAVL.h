#pragma once
#include "NodoAVL.h"
#include <iostream>

class ArbolAVL {
private:
    NodoAVL* raiz;

    int obtenerAltura(NodoAVL* nodo);
    int obtenerBalance(NodoAVL* nodo);
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    NodoAVL* insertarNodo(NodoAVL* nodo, Transaccion* transaccion);
    void preOrden(NodoAVL* nodo);

public:
    ArbolAVL();
    void insertar(Transaccion* transaccion);
    void mostrarPreOrden();
    NodoAVL* obtenerRaiz(); 
};

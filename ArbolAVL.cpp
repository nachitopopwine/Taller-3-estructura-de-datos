#include "ArbolAVL.h"

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

int ArbolAVL::obtenerAltura(NodoAVL* nodo) {
    return nodo == nullptr ? 0 : nodo->altura;
}

int ArbolAVL::obtenerBalance(NodoAVL* nodo) {
    return nodo == nullptr ? 0 : obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;
    x->derecho = y;
    y->izquierdo = T2;
    y->altura = std::max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = std::max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;
    y->izquierdo = x;
    x->derecho = T2;
    x->altura = std::max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = std::max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    return y;
}

NodoAVL* ArbolAVL::insertarNodo(NodoAVL* nodo, Transaccion* transaccion) {
    if (nodo == nullptr)
        return new NodoAVL(transaccion);

    if (transaccion->getId() < nodo->transaccion->getId())
        nodo->izquierdo = insertarNodo(nodo->izquierdo, transaccion);
    else if (transaccion->getId() > nodo->transaccion->getId())
        nodo->derecho = insertarNodo(nodo->derecho, transaccion);
    else
        return nodo;

    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));
    int balance = obtenerBalance(nodo);

    if (balance > 1 && transaccion->getId() < nodo->izquierdo->transaccion->getId())
        return rotacionDerecha(nodo);

    if (balance < -1 && transaccion->getId() > nodo->derecho->transaccion->getId())
        return rotacionIzquierda(nodo);

    if (balance > 1 && transaccion->getId() > nodo->izquierdo->transaccion->getId()) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && transaccion->getId() < nodo->derecho->transaccion->getId()) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::insertar(Transaccion* transaccion) {
    raiz = insertarNodo(raiz, transaccion);
}

void ArbolAVL::mostrarPreOrden() {
    preOrden(raiz);
}

void ArbolAVL::preOrden(NodoAVL* nodo) {
    if (nodo != nullptr) {
        nodo->transaccion->mostrarTransaccion();
        preOrden(nodo->izquierdo);
        preOrden(nodo->derecho);
    }
}

NodoAVL* ArbolAVL::obtenerRaiz() {
    return raiz;
}

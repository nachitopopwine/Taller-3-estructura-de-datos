#include "ArbolABB.h"

ArbolABB::ArbolABB() : raiz(nullptr) {}

NodoABB* ArbolABB::insertarNodo(NodoABB* nodo, Transaccion* transaccion) {
    if (nodo == nullptr)
        return new NodoABB(transaccion);

    if (transaccion->getId() < nodo->transaccion->getId())
        nodo->izquierdo = insertarNodo(nodo->izquierdo, transaccion);
    else
        nodo->derecho = insertarNodo(nodo->derecho, transaccion);

    return nodo;
}

void ArbolABB::insertar(Transaccion* transaccion) {
    raiz = insertarNodo(raiz, transaccion);
}

NodoABB* ArbolABB::obtenerRaiz() {
    return raiz;
}

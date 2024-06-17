#pragma once
#include "GestorTransacciones.h"

class InterfazUsuario {
private:
    GestorTransacciones gestor;

    void mostrarMenu();
    void opcionRegistrarTransaccion();
    void opcionBuscarTransaccion();
    void opcionDetectarTransaccionesSospechosas();
    void opcionGenerarReporte();

public:
    void iniciar();
};

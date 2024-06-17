#pragma once
#include "Transaccion.h"
#include "ArbolAVL.h"
#include "ArbolABB.h"
#include <vector>
#include <string>

class GestorTransacciones {
private:
    ArbolAVL historialTransacciones;
    ArbolABB transaccionesSospechosas;
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void guardarEnArchivo(const std::string& nombreArchivo);

public:
    GestorTransacciones();
    void registrarTransaccion(Transaccion* transaccion);
    Transaccion* buscarTransaccion(int id);
    void detectarTransaccionesSospechosas(double montoLimite);
    void generarReporte();
};

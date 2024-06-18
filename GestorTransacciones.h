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
    std::vector<int> transaccionesReportadas;
    bool fueReportada(int id);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void guardarEnArchivo(const std::string& nombreArchivo);
    void guardarEnArchivoInOrden(NodoAVL *nodo, std::ofstream &archivo);
    NodoAVL *buscarNodoAVL(NodoAVL *nodo, int id);
    void detectarSospechosas(NodoAVL* nodo, double montoLimite);
    void generarReporteInOrden(NodoABB* nodo, std::ofstream& reporte);

public:
    GestorTransacciones();
    void registrarTransaccion(Transaccion* transaccion);
    Transaccion* buscarTransaccion(int id);
    void detectarTransaccionesSospechosasPorMonto(double montoLimite);
    void generarReporte();
};

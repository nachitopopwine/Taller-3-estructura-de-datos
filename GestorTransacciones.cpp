#include "GestorTransacciones.h"
#include <fstream>
#include <sstream>

GestorTransacciones::GestorTransacciones() {
    cargarDesdeArchivo("transacciones.txt");
}

void GestorTransacciones::registrarTransaccion(Transaccion* transaccion) {
    historialTransacciones.insertar(transaccion);
    guardarEnArchivo("transacciones.txt");
}

Transaccion* GestorTransacciones::buscarTransaccion(int id) {
    // Implementación de la búsqueda de transacciones por ID.
    return nullptr; // Placeholder
}

void GestorTransacciones::detectarTransaccionesSospechosas(double montoLimite) {
    // Implementación de la detección de transacciones sospechosas.
}

void GestorTransacciones::generarReporte() {
    // Implementación de la generación de reportes.
}

void GestorTransacciones::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            std::istringstream iss(linea);
            int id;
            std::string origen, destino, ubicacion, fechaHora;
            double monto;
            iss >> id >> origen >> destino >> monto >> ubicacion >> fechaHora;
            Transaccion* transaccion = new Transaccion(id, origen, destino, monto, ubicacion, fechaHora);
            historialTransacciones.insertar(transaccion);
        }
        archivo.close();
    }
}

void GestorTransacciones::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        // Implementación de guardar todas las transacciones en el archivo.
        archivo.close();
    }
}

#include "GestorTransacciones.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

GestorTransacciones::GestorTransacciones() {
    cargarDesdeArchivo("transacciones.txt");
}

void GestorTransacciones::registrarTransaccion(Transaccion* transaccion) {
    historialTransacciones.insertar(transaccion);
    guardarEnArchivo("transacciones.txt");
}

Transaccion* GestorTransacciones::buscarTransaccion(int id) {
    NodoAVL* nodo = buscarNodoAVL(historialTransacciones.obtenerRaiz(), id);
    if (nodo) {
    return nodo->transaccion;
    } else {
    return nullptr;
    }
}

NodoAVL* GestorTransacciones::buscarNodoAVL(NodoAVL* nodo, int id) {
    if (nodo == nullptr || nodo->transaccion->getId() == id)
        return nodo;

    if (id < nodo->transaccion->getId())
        return buscarNodoAVL(nodo->izquierdo, id);
    else
        return buscarNodoAVL(nodo->derecho, id);
}

void GestorTransacciones::detectarTransaccionesSospechosasPorMonto(double montoLimite) {
    detectarSospechosas(historialTransacciones.obtenerRaiz(), montoLimite);
}

void GestorTransacciones::detectarSospechosas(NodoAVL* nodo, double montoLimite) {
    if (nodo == nullptr) return;

    if (nodo->transaccion->getMonto() > montoLimite && fueReportada(nodo->transaccion->getId())){
        std::cout << "Transacción sospechosa detectada:" << std::endl;
        std::cout << "ID: " << nodo->transaccion->getId() << ", Origen: " << nodo->transaccion->getCuentaOrigen()
                  << ", Destino: " << nodo->transaccion->getCuentaDestino() << ", Monto: " << nodo->transaccion->getMonto()
                  << ", Ubicación: " << nodo->transaccion->getUbicacion() << ", Fecha y Hora: " << nodo->transaccion->getFechaHora() << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }

    if (nodo->transaccion->getMonto() > montoLimite && !fueReportada(nodo->transaccion->getId())){
        transaccionesSospechosas.insertar(nodo->transaccion);
        transaccionesReportadas.push_back(nodo->transaccion->getId());
        std::cout << "Transacción sospechosa detectada:" << std::endl;
        std::cout << "ID: " << nodo->transaccion->getId() << ", Origen: " << nodo->transaccion->getCuentaOrigen()
                  << ", Destino: " << nodo->transaccion->getCuentaDestino() << ", Monto: " << nodo->transaccion->getMonto()
                  << ", Ubicación: " << nodo->transaccion->getUbicacion() << ", Fecha y Hora: " << nodo->transaccion->getFechaHora() << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }
    detectarSospechosas(nodo->izquierdo, montoLimite);
    detectarSospechosas(nodo->derecho, montoLimite);
}

void GestorTransacciones::generarReporte() {
    std::ofstream reporte("reporte_sospechosas.txt");
    if (reporte.is_open()) {
        std::cout << "Generando reporte de transacciones sospechosas:" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        generarReporteInOrden(transaccionesSospechosas.obtenerRaiz(), reporte);
        reporte.close();
        std::cout << "Reporte generado exitosamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo de reporte." << std::endl;
    }
}

void GestorTransacciones::generarReporteInOrden(NodoABB* nodo, std::ofstream& reporte) {
    if (nodo != nullptr) {
        generarReporteInOrden(nodo->izquierdo, reporte);
        reporte << "ID: " << nodo->transaccion->getId() << ", Origen: " << nodo->transaccion->getCuentaOrigen()
                << ", Destino: " << nodo->transaccion->getCuentaDestino() << ", Monto: " << nodo->transaccion->getMonto()
                << ", Ubicación: " << nodo->transaccion->getUbicacion() << ", Fecha y Hora: " << nodo->transaccion->getFechaHora() << std::endl;


        std::cout << "ID: " << nodo->transaccion->getId() << ", Origen: " << nodo->transaccion->getCuentaOrigen()
                  << ", Destino: " << nodo->transaccion->getCuentaDestino() << ", Monto: " << nodo->transaccion->getMonto()
                  << ", Ubicación: " << nodo->transaccion->getUbicacion() << ", Fecha y Hora: " << nodo->transaccion->getFechaHora() << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        generarReporteInOrden(nodo->derecho, reporte);
    }
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
        guardarEnArchivoInOrden(historialTransacciones.obtenerRaiz(), archivo);
        archivo.close();
    }
}

void GestorTransacciones::guardarEnArchivoInOrden(NodoAVL* nodo, std::ofstream& archivo) {
    if (nodo != nullptr) {
        guardarEnArchivoInOrden(nodo->izquierdo, archivo);
        archivo << nodo->transaccion->getId() << " " << nodo->transaccion->getCuentaOrigen() << " "
                << nodo->transaccion->getCuentaDestino() << " " << nodo->transaccion->getMonto() << " "
                << nodo->transaccion->getUbicacion() << " " << nodo->transaccion->getFechaHora() << std::endl;
        guardarEnArchivoInOrden(nodo->derecho, archivo);
    }


}
bool GestorTransacciones::fueReportada(int id) {
    for (int idReportado : transaccionesReportadas) {
        if (idReportado == id) {
            return true;
        }
    }
    return false;
}

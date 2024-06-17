#include "InterfazUsuario.h"
#include <iostream>

void InterfazUsuario::mostrarMenu() {
    std::cout << "1. Registrar Transaccion\n";
    std::cout << "2. Buscar Transaccion\n";
    std::cout << "3. Detectar Transacciones Sospechosas\n";
    std::cout << "4. Generar Reporte\n";
    std::cout << "5. Salir\n";
}

void InterfazUsuario::opcionRegistrarTransaccion() {
    int id;
    std::string origen, destino, ubicacion, fechaHora;
    double monto;
    
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Cuenta Origen: ";
    std::cin >> origen;
    std::cout << "Cuenta Destino: ";
    std::cin >> destino;
    std::cout << "Monto: ";
    std::cin >> monto;
    std::cout << "Ubicación: ";
    std::cin >> ubicacion;
    std::cout << "Fecha y Hora: ";
    std::cin >> fechaHora;

    Transaccion* transaccion = new Transaccion(id, origen, destino, monto, ubicacion, fechaHora);
    gestor.registrarTransaccion(transaccion);
}

void InterfazUsuario::opcionBuscarTransaccion() {
    int id;
    std::cout << "ID de la transacción: ";
    std::cin >> id;
    Transaccion* transaccion = gestor.buscarTransaccion(id);
    if (transaccion) {
        transaccion->mostrarTransaccion();
    } else {
        std::cout << "Transacción no encontrada.\n";
    }
}

void InterfazUsuario::opcionDetectarTransaccionesSospechosas() {
    double montoLimite;
    std::cout << "Monto límite para detectar transacciones sospechosas: ";
    std::cin >> montoLimite;
    gestor.detectarTransaccionesSospechosas(montoLimite);
}

void InterfazUsuario::opcionGenerarReporte() {
    gestor.generarReporte();
}

void InterfazUsuario::iniciar() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                opcionRegistrarTransaccion();
                break;
            case 2:
                opcionBuscarTransaccion();
                break;
            case 3:
                opcionDetectarTransaccionesSospechosas();
                break;
            case 4:
                opcionGenerarReporte();
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
                break;
        }
    } while (opcion != 5);
}

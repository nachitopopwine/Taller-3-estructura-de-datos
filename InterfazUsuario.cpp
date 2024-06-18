#include "InterfazUsuario.h"
#include <iostream>

void InterfazUsuario::mostrarMenu() {
    std::cout << "1. Registrar Transaccion\n";
    std::cout << "2. Buscar Transaccion\n";
    std::cout << "3. Detectar Transacciones Sospechosas\n";
    std::cout << "4. Modificar formas de Detectar Transacciones Sospechosas\n"; // Nuevo
    std::cout << "5. Generar Reporte\n";
    std::cout << "6. Salir\n";
}

void InterfazUsuario::opcionRegistrarTransaccion() {
    int id;
    std::string origen, destino, ubicacion, fechaHora;
    double monto;
    
    std::cout << "ID: ";
    std::cin >> id;
    
    std::cin.ignore();  
    
    std::cout << "Cuenta Origen: ";
    std::getline(std::cin, origen);

    std::cout << "Cuenta Destino: ";
    std::getline(std::cin, destino);

    std::cout << "Monto: ";
    std::cin >> monto;
    
    std::cin.ignore();  

    std::cout << "Ubicación: ";
    std::getline(std::cin, ubicacion);

    std::cout << "Fecha y Hora, ejemplo(2024-17-06T20:14:00): ";
    std::getline(std::cin, fechaHora);

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
     std::cout << "Seleccione la forma de detectar transacciones sospechosas:" << std::endl;
    std::cout << "1. Transacciones que excedan un monto específico." << std::endl;
    std::cout << "2. Frecuencia inusualmente alta de transacciones en un corto periodo." << std::endl;
    std::cout << "3. Transacciones desde ubicaciones geográficas diferentes en un corto tiempo." << std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion) {
        case 1: {
            double montoLimite;
            std::cout << "Monto límite para detectar transacciones sospechosas: ";
            std::cin >> montoLimite;
            gestor.detectarTransaccionesSospechosasPorMonto(montoLimite);
            break;
        }
        case 2:
            //gestor.detectarTransaccionesFrecuentes();
            break;
        case 3:
            //gestor.detectarTransaccionesDesdeUbicacionesDiferentes();
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }
}

void InterfazUsuario::opcionGenerarReporte() {
    gestor.generarReporte();
}
void InterfazUsuario::opcionModificarFormasDetectarTransaccionesSospechosas() {
    std::cout << "Seleccione la forma de modificar la detección de transacciones sospechosas:" << std::endl;
    std::cout << "1. Modificar cantidad maxima de transacciones para frecuencia alta en un corto periodo(1 dia)." << std::endl;
    std::cout << "2. Modificar cantidad maxima de transacciones desde ubicaciones diferentes en un corto tiempo (1 dia)." << std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion) {
        case 1: {
            int cantidad;
            std::cout << "Ingrese la nueva cantidad de transacciones en un corto periodo: ";
            std::cin >> cantidad;
            //gestor.setCantidadTransaccionesFrecuentes(cantidad);
            break;
        }
        case 2: {
            int cantidad;
            std::cout << "Ingrese la nueva cantidad de transacciones desde ubicaciones diferentes: ";
            std::cin >> cantidad;
            //gestor.setCantidadTransaccionesDesdeUbicaciones(cantidad);
            break;
        }
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }
}
void InterfazUsuario::iniciar() {
    int opcion;
    do {
        mostrarMenu();
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;
        std::cin.ignore();

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
                opcionModificarFormasDetectarTransaccionesSospechosas();
                break;
            case 5:
                opcionGenerarReporte();
                break;
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
                break;
        }
    } while (opcion != 6);
}

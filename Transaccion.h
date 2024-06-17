#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaccion {
private:
    int id;
    string cuentaOrigen;
    string cuentaDestino;
    double monto;
    string ubicacion;
    string fechaHora;

public:
    Transaccion(int id, string origen, string destino, double monto, string ubicacion, string fechaHora);
    int getId() const;
    string getCuentaOrigen() const;
    string getCuentaDestino() const;
    double getMonto() const;
    string getUbicacion() const;
    string getFechaHora() const;
    
    void mostrarTransaccion() const;
};

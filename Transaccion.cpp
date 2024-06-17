#include "Transaccion.h"

Transaccion::Transaccion(int id, string origen, string destino, double monto, string ubicacion, string fechaHora)
    : id(id), cuentaOrigen(origen), cuentaDestino(destino), monto(monto), ubicacion(ubicacion), fechaHora(fechaHora) {}

int Transaccion::getId() const { return id; }
string Transaccion::getCuentaOrigen() const { return cuentaOrigen; }
string Transaccion::getCuentaDestino() const { return cuentaDestino; }
double Transaccion::getMonto() const { return monto; }
string Transaccion::getUbicacion() const { return ubicacion; }
string Transaccion::getFechaHora() const { return fechaHora; }

void Transaccion::mostrarTransaccion() const {
    cout << "ID: " << id << ", Origen: " << cuentaOrigen << ", Destino: " << cuentaDestino
         << ", Monto: " << monto << ", Ubicación: " << ubicacion << ", Fecha y Hora: " << fechaHora << endl;
}

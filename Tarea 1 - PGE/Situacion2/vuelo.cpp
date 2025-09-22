#include "vuelo.h"
#include <QDebug>

Vuelo::Vuelo(const QString& codigo, const QString& origen, const QString& destino)
    : codigo(codigo), origen(origen), destino(destino) {}

Vuelo::~Vuelo() {
    qDeleteAll(asientos);
    qDeleteAll(reservas);
}

void Vuelo::agregarAsiento(const QString& numero) {
    asientos.append(new Asiento(numero));
}

Asiento* Vuelo::buscarAsientoDisponible() {
    for (Asiento* asiento : asientos) {
        if (asiento->estaDisponible()) {
            return asiento;
        }
    }
    return nullptr;
}

void Vuelo::reservarAsiento(const Pasajero& pasajero) {
    Asiento* asientoDisponible = buscarAsientoDisponible();
    if (asientoDisponible) {
        Reserva* nuevaReserva = new Reserva(pasajero, asientoDisponible);
        nuevaReserva->confirmarReserva();
        reservas.append(nuevaReserva);
    } else {
        qDebug() << "No hay asientos disponibles.";
    }
}

void Vuelo::mostrarReservas() const {
    qDebug() << "Reservas para el vuelo" << codigo << ":";
    for (Reserva* r : reservas) {
        r->mostrarReserva();
    }
}

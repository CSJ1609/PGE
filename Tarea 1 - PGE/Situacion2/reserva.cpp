#include "reserva.h"
#include <QDebug>

Reserva::Reserva(const Pasajero& pasajero, Asiento* asiento)
    : pasajero(pasajero), asiento(asiento) {}

void Reserva::confirmarReserva() {
    if (asiento->estaDisponible()) {
        asiento->reservar();
        qDebug() << "Reserva confirmada para" << pasajero.getNombre()<<pasajero.getDni()
                 << "en el asiento" << asiento->getNumero();
    } else {
        qDebug() << "El asiento" << asiento->getNumero() << "ya está reservado.";
    }
}

void Reserva::mostrarReserva() const {
    qDebug() << "Pasajero:" << pasajero.getNombre()<<pasajero.getDni()
    << "| Asiento:" << asiento->getNumero();
}

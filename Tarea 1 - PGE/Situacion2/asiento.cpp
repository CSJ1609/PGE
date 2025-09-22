#include "asiento.h"

Asiento::Asiento(const QString& numero)
    : numero(numero), disponible(true) {}

QString Asiento::getNumero() const {
    return numero;
}

bool Asiento::estaDisponible() const {
    return disponible;
}

void Asiento::reservar() {
    disponible = false;
}

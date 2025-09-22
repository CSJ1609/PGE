#include "pasajero.h"

Pasajero::Pasajero(const QString& nombre, const QString& dni)
    : nombre(nombre), dni(dni) {}

QString Pasajero::getNombre() const {
    return nombre;
}

QString Pasajero::getDni() const {
    return dni;
}

#include "persona.h"

Persona::Persona(const QString& nombre, const QString& dni)
    : nombre(nombre), dni(dni) {}

QString Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const QString& nombre) {
    this->nombre = nombre;
}

QString Persona::getDni() const {
    return dni;
}

void Persona::setDni(const QString& dni) {
    this->dni = dni;
}

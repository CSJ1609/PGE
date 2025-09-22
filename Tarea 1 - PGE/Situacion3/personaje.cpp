#include "personaje.h"
#include <QDebug>

Personaje::Personaje(const QString& nombre, int x, int y, int salud)
    : Entidad(x, y, salud), nombre(nombre) {}

void Personaje::mover(int dx, int dy) {
    x += dx;
    y += dy;
    qDebug() << nombre << "se mueve a (" << x << "," << y << ")";
}

#include "entidad.h"

Entidad::Entidad(int x, int y, int salud)
    : x(x), y(y), salud(salud) {}

void Entidad::recibirDano(int cantidad) {
    salud -= cantidad;
    if (salud < 0) salud = 0;
}

int Entidad::getX() const { return x; }
int Entidad::getY() const { return y; }
int Entidad::getSalud() const { return salud; }

#include "item.h"

Item::Item(const QString& nombre, int x, int y)
    : nombre(nombre), x(x), y(y) {}

QString Item::getNombre() const { return nombre; }
int Item::getX() const { return x; }
int Item::getY() const { return y; }

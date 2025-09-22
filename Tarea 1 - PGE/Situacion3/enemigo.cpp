#include "enemigo.h"
#include <QDebug>

Enemigo::Enemigo(const QString& nombre, int x, int y)
    : Personaje(nombre, x, y, 50) {}

void Enemigo::atacar(Entidad* objetivo) {
    qDebug() << nombre << "ataca al jugador!";
    objetivo->recibirDano(10);
}

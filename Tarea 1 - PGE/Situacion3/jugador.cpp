#include "jugador.h"
#include <QDebug>

Jugador::Jugador(const QString& nombre, int x, int y)
    : Personaje(nombre, x, y, 100) {}

void Jugador::atacar(Entidad* objetivo) {
    qDebug() << nombre << "ataca al enemigo";
    objetivo->recibirDano(20);
}

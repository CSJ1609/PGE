#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

class Jugador : public Personaje {
public:
    Jugador(const QString& nombre, int x, int y);

    void atacar(Entidad* objetivo) override;
};

#endif // JUGADOR_H


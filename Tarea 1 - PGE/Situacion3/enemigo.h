#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

class Enemigo : public Personaje {
public:
    Enemigo(const QString& nombre, int x, int y);

    void atacar(Entidad* objetivo) override;
};

#endif // ENEMIGO_H



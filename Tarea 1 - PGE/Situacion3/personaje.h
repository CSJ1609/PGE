#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include <QString>

class Personaje : public Entidad {
protected:
    QString nombre;

public:
    Personaje(const QString& nombre, int x, int y, int salud);
    virtual void mover(int dx, int dy) override;
};

#endif // PERSONAJE_H


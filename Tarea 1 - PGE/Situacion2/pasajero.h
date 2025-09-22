#ifndef PASAJERO_H
#define PASAJERO_H

#include <QString>

class Pasajero {
private:
    QString nombre;
    QString dni;

public:
    Pasajero(const QString& nombre, const QString& dni);

    QString getNombre() const;
    QString getDni() const;
};

#endif // PASAJERO_H


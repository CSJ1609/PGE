#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

class Persona {
private:
    QString nombre;
    QString dni;

public:
    Persona(const QString& nombre, const QString& dni);

    QString getNombre() const;
    void setNombre(const QString& nombre);

    QString getDni() const;
    void setDni(const QString& dni);
};

#endif // PERSONA_H


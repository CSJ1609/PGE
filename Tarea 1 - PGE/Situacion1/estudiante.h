#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include <QMap>

class Estudiante : public Persona {
private:
    QMap<QString, float> materias; // clave: nombre materia, valor: calificación

public:
    Estudiante(const QString& nombre, const QString& dni);

    void registrarMateria(const QString& materia, float nota);
    float obtenerNota(const QString& materia) const;
    void mostrarMaterias() const;
};

#endif // ESTUDIANTE_H


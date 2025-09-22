#include "estudiante.h"
#include <QDebug>

Estudiante::Estudiante(const QString& nombre, const QString& dni)
    : Persona(nombre, dni) {}

void Estudiante::registrarMateria(const QString& materia, float nota) {
    materias[materia] = nota;
}

float Estudiante::obtenerNota(const QString& materia) const {
    return materias.value(materia, -1); // devuelve -1 si no existe
}

void Estudiante::mostrarMaterias() const {
    qDebug() << "Materias de" << getNombre() << getDni() <<":";
    for (auto it = materias.begin(); it != materias.end(); ++it) {
        qDebug() << "Materia:" << it.key() << "- Nota:" << it.value();
    }
}

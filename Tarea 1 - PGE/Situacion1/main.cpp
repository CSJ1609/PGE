#include <QCoreApplication>
#include "estudiante.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Estudiante est("Sofia Julieta Conejo", "44980655");

    est.registrarMateria("Matemática", 9.5);
    est.registrarMateria("Historia", 8.0);
    est.mostrarMaterias();

    float nota = est.obtenerNota("Matemática");
    qDebug() << "Nota de Matemática:" << nota;

    return a.exec();
}

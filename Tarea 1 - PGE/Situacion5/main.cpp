#include <QCoreApplication>
#include "Gerente.h"
#include "Desarrollador.h"
#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<Empleado*> empleados;

    empleados.push_back(new Gerente("Carlos Perez", 5000, 1200));
    empleados.push_back(new Desarrollador("Ana Lopez", 4000, 10, 50));

    for (Empleado* emp : empleados) {
        emp->mostrarInformacion();
    }

    // Liberar memoria
    for (Empleado* emp : empleados) {
        delete emp;
    }

    return a.exec();
}


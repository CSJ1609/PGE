#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QString>
#include <iostream>

// Clase abstracta
class Empleado {
protected:
    QString nombre;
    double salarioBase;

public:
    Empleado(const QString &nombre, double salarioBase)
        : nombre(nombre), salarioBase(salarioBase) {}

    virtual ~Empleado() {}

    virtual void mostrarInformacion() const = 0; // Método virtual puro
    virtual double calcularSalario() const = 0;  // Método virtual puro
};

#endif // EMPLEADO_H


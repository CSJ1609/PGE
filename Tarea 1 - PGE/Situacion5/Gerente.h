#ifndef GERENTE_H
#define GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado {
private:
    double bono;

public:
    Gerente(const QString &nombre, double salarioBase, double bono)
        : Empleado(nombre, salarioBase), bono(bono) {}

    void mostrarInformacion() const override {
        std::cout << "Gerente: " << nombre.toStdString()
        << " | Salario base: " << salarioBase
        << " | Bono: " << bono
        << " | Salario total: " << calcularSalario()
        << std::endl;
    }

    double calcularSalario() const override {
        return salarioBase + bono;
    }
};

#endif // GERENTE_H


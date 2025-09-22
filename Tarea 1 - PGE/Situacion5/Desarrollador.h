#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include "Empleado.h"

class Desarrollador : public Empleado {
private:
    int horasExtras;
    double pagoPorHoraExtra;

public:
    Desarrollador(const QString &nombre, double salarioBase, int horasExtras, double pagoHora)
        : Empleado(nombre, salarioBase),
        horasExtras(horasExtras),
        pagoPorHoraExtra(pagoHora) {}

    void mostrarInformacion() const override {
        std::cout << "Desarrollador: " << nombre.toStdString()
        << " | Salario base: " << salarioBase
        << " | Horas extras: " << horasExtras
        << " | Salario total: " << calcularSalario()
        << std::endl;
    }

    double calcularSalario() const override {
        return salarioBase + (horasExtras * pagoPorHoraExtra);
    }
};

#endif // DESARROLLADOR_H


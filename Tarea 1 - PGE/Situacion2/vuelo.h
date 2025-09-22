#ifndef VUELO_H
#define VUELO_H

#include "asiento.h"
#include "reserva.h"
#include <QList>
#include <QString>

class Vuelo {
private:
    QString codigo;
    QString origen;
    QString destino;
    QList<Asiento*> asientos;
    QList<Reserva*> reservas;

public:
    Vuelo(const QString& codigo, const QString& origen, const QString& destino);
    ~Vuelo();

    void agregarAsiento(const QString& numero);
    Asiento* buscarAsientoDisponible();
    void reservarAsiento(const Pasajero& pasajero);
    void mostrarReservas() const;
};

#endif // VUELO_H


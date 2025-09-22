#ifndef RESERVA_H
#define RESERVA_H

#include "pasajero.h"
#include "asiento.h"

class Reserva {
private:
    Pasajero pasajero;
    Asiento* asiento;

public:
    Reserva(const Pasajero& pasajero, Asiento* asiento);

    void confirmarReserva();
    void mostrarReserva() const;
};

#endif // RESERVA_H


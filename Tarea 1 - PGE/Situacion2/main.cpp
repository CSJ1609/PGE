#include <QCoreApplication>
#include "vuelo.h"
#include "pasajero.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vuelo vuelo("AR123", "Cordoba", "Buenos Aires");

    vuelo.agregarAsiento("1A");
    vuelo.agregarAsiento("1B");

    Pasajero p1("Julieta Conejo", "12345678");
    Pasajero p2("Mateo Diaz", "87654321");

    vuelo.reservarAsiento(p1);
    vuelo.reservarAsiento(p2);

    vuelo.mostrarReservas();

    return a.exec();
}

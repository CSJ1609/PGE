#ifndef ASIENTO_H
#define ASIENTO_H

#include <QString>

class Asiento {
private:
    QString numero;
    bool disponible;

public:
    Asiento(const QString& numero);

    QString getNumero() const;
    bool estaDisponible() const;
    void reservar();
};

#endif // ASIENTO_H


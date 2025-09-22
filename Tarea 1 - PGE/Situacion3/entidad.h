#ifndef ENTIDAD_H
#define ENTIDAD_H

class Entidad {
protected:
    int x, y;
    int salud;

public:
    Entidad(int x, int y, int salud);

    virtual void mover(int dx, int dy) = 0;
    virtual void atacar(Entidad* objetivo) = 0;
    virtual void recibirDano(int cantidad);
    virtual ~Entidad() {}

    int getX() const;
    int getY() const;
    int getSalud() const;
};

#endif // ENTIDAD_H


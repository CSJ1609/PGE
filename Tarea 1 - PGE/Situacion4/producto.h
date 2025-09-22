#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto {
private:
    QString nombre;
    int cantidad;
    double precio;

public:
    Producto(const QString& nombre, int cantidad, double precio);

    QString getNombre() const;
    int getCantidad() const;
    double getPrecio() const;

    void setNombre(const QString& nombre);
    void setCantidad(int cantidad);
    void setPrecio(double precio);

    void agregarCantidad(int cantidad);
    void actualizarCantidad(int cantidad);
    void eliminarCantidad(int cantidad);
};

#endif // PRODUCTO_H


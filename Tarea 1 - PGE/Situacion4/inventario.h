#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"
#include <QList>

class Inventario {
private:
    QList<Producto> productos;

public:
    void agregarProducto(const Producto& producto);
    bool actualizarProducto(const QString& nombre, int nuevaCantidad);
    bool eliminarProducto(const QString& nombre);
    QList<Producto> getProductos() const;
};

#endif // INVENTARIO_H


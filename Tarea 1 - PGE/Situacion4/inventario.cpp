#include "inventario.h"

void Inventario::agregarProducto(const Producto& producto) {
    productos.append(producto);
}

bool Inventario::actualizarProducto(const QString& nombre, int nuevaCantidad) {
    for (Producto &p : productos) {
        if (p.getNombre() == nombre) {
            p.setCantidad(nuevaCantidad);
            return true;
        }
    }
    return false;
}

bool Inventario::eliminarProducto(const QString& nombre) {
    for (int i = 0; i < productos.size(); ++i) {
        if (productos[i].getNombre() == nombre) {
            productos.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Producto> Inventario::getProductos() const {
    return productos;
}

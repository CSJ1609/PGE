#include "producto.h"

Producto::Producto(const QString& nombre, int cantidad, double precio)
    : nombre(nombre), cantidad(cantidad), precio(precio) {}

QString Producto::getNombre() const { return nombre; }
int Producto::getCantidad() const { return cantidad; }
double Producto::getPrecio() const { return precio; }

void Producto::setNombre(const QString& nombre) { this->nombre = nombre; }
void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }
void Producto::setPrecio(double precio) { this->precio = precio; }

void Producto::agregarCantidad(int cant) { cantidad += cant; }
void Producto::actualizarCantidad(int cant) { cantidad = cant; }
void Producto::eliminarCantidad(int cant) {
    cantidad -= cant;
    if (cantidad < 0) cantidad = 0;
}

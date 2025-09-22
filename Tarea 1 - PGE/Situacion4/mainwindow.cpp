#include "mainwindow.h"
#include <QMessageBox>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), productoSeleccionado(-1) {
    central = new QWidget(this);
    setCentralWidget(central);

    // Componentes
    lineEditNombre = new QLineEdit();
    spinBoxCantidad = new QSpinBox();
    spinBoxCantidad->setRange(0, 10000);
    doubleSpinBoxPrecio = new QDoubleSpinBox();
    doubleSpinBoxPrecio->setRange(0, 100000);
    doubleSpinBoxPrecio->setDecimals(2);

    btnAgregar = new QPushButton("Agregar");
    btnActualizar = new QPushButton("Actualizar");
    btnEliminar = new QPushButton("Eliminar");

    tableView = new QTableView();
    modelo = new QStandardItemModel(0, 3, this);
    modelo->setHeaderData(0, Qt::Horizontal, "Nombre");
    modelo->setHeaderData(1, Qt::Horizontal, "Cantidad");
    modelo->setHeaderData(2, Qt::Horizontal, "Precio");
    tableView->setModel(modelo);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Layouts
    QVBoxLayout *layoutPrincipal = new QVBoxLayout();
    QHBoxLayout *layoutFormulario = new QHBoxLayout();
    layoutFormulario->addWidget(lineEditNombre);
    layoutFormulario->addWidget(spinBoxCantidad);
    layoutFormulario->addWidget(doubleSpinBoxPrecio);

    QHBoxLayout *layoutBotones = new QHBoxLayout();
    layoutBotones->addWidget(btnAgregar);
    layoutBotones->addWidget(btnActualizar);
    layoutBotones->addWidget(btnEliminar);

    layoutPrincipal->addLayout(layoutFormulario);
    layoutPrincipal->addLayout(layoutBotones);
    layoutPrincipal->addWidget(tableView);

    central->setLayout(layoutPrincipal);

    // Conexiones
    connect(btnAgregar, &QPushButton::clicked, this, &MainWindow::agregarProducto);
    connect(btnActualizar, &QPushButton::clicked, this, &MainWindow::actualizarProducto);
    connect(btnEliminar, &QPushButton::clicked, this, &MainWindow::eliminarProducto);
    connect(tableView, &QTableView::clicked, this, &MainWindow::seleccionarProducto);
}

MainWindow::~MainWindow() {}

void MainWindow::actualizarTabla() {
    modelo->removeRows(0, modelo->rowCount());
    QList<Producto> productos = inventario.getProductos();

    for (int i = 0; i < productos.size(); ++i) {
        const Producto &p = productos[i];
        modelo->insertRow(i);
        modelo->setData(modelo->index(i, 0), p.getNombre());
        modelo->setData(modelo->index(i, 1), p.getCantidad());
        modelo->setData(modelo->index(i, 2), p.getPrecio());
    }
}

void MainWindow::limpiarCampos() {
    lineEditNombre->clear();
    spinBoxCantidad->setValue(0);
    doubleSpinBoxPrecio->setValue(0.0);
    productoSeleccionado = -1;
}

void MainWindow::agregarProducto() {
    QString nombre = lineEditNombre->text();
    int cantidad = spinBoxCantidad->value();
    double precio = doubleSpinBoxPrecio->value();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese un nombre válido");
        return;
    }

    Producto p(nombre, cantidad, precio);
    inventario.agregarProducto(p);

    actualizarTabla();
    limpiarCampos();
}

void MainWindow::actualizarProducto() {
    if (productoSeleccionado < 0) {
        QMessageBox::warning(this, "Error", "Seleccione un producto para actualizar");
        return;
    }

    QString nombre = lineEditNombre->text();
    int cantidad = spinBoxCantidad->value();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese un nombre válido");
        return;
    }

    inventario.actualizarProducto(nombre, cantidad);
    actualizarTabla();
    limpiarCampos();
}

void MainWindow::eliminarProducto() {
    if (productoSeleccionado < 0) {
        QMessageBox::warning(this, "Error", "Seleccione un producto para eliminar");
        return;
    }

    QString nombre = lineEditNombre->text();
    if (inventario.eliminarProducto(nombre)) {
        actualizarTabla();
        limpiarCampos();
    } else {
        QMessageBox::warning(this, "Error", "Producto no encontrado");
    }
}

void MainWindow::seleccionarProducto(const QModelIndex &index) {
    productoSeleccionado = index.row();

    Producto p = inventario.getProductos().at(productoSeleccionado);
    lineEditNombre->setText(p.getNombre());
    spinBoxCantidad->setValue(p.getCantidad());
    doubleSpinBoxPrecio->setValue(p.getPrecio());
}

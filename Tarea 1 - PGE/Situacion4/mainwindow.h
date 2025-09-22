#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include "producto.h"
#include "inventario.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void agregarProducto();
    void actualizarProducto();
    void eliminarProducto();
    void seleccionarProducto(const QModelIndex &index);

private:
    QWidget *central;
    QLineEdit *lineEditNombre;
    QSpinBox *spinBoxCantidad;
    QDoubleSpinBox *doubleSpinBoxPrecio;
    QPushButton *btnAgregar;
    QPushButton *btnActualizar;
    QPushButton *btnEliminar;
    QTableView *tableView;
    QStandardItemModel *modelo;
    Inventario inventario;
    int productoSeleccionado;

    void actualizarTabla();
    void limpiarCampos();
};

#endif // MAINWINDOW_H


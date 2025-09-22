#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

class JuegoWidget : public QWidget {
    int jugadorX = 50;
    int jugadorY = 50;
    int enemigoX = 200;
    int enemigoY = 100;
    int itemX = 300;
    int itemY = 200;

public:
    JuegoWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(400, 300);
        setFocusPolicy(Qt::StrongFocus);

        // Timer para actualizar la ventana cada 50 ms
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&JuegoWidget::update));
        timer->start(50);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);

        // Fondo
        painter.fillRect(rect(), Qt::white);

        // Dibujo jugador - azul
        painter.setBrush(Qt::blue);
        painter.drawRect(jugadorX, jugadorY, 40, 40);

        // Dibujo enemigo - rojo
        painter.setBrush(Qt::red);
        painter.drawRect(enemigoX, enemigoY, 40, 40);

        // Dibujo ítem - verde
        painter.setBrush(Qt::green);
        painter.drawEllipse(itemX, itemY, 20, 20);
    }

    void keyPressEvent(QKeyEvent *event) override {
        int step = 10;
        switch (event->key()) {
        case Qt::Key_Left:
            jugadorX = qMax(0, jugadorX - step);
            break;
        case Qt::Key_Right:
            jugadorX = qMin(width() - 40, jugadorX + step);
            break;
        case Qt::Key_Up:
            jugadorY = qMax(0, jugadorY - step);
            break;
        case Qt::Key_Down:
            jugadorY = qMin(height() - 40, jugadorY + step);
            break;
        default:
            QWidget::keyPressEvent(event);
        }

        // Opcional: Detectar colisión con ítem
        QRect jugadorRect(jugadorX, jugadorY, 40, 40);
        QRect itemRect(itemX, itemY, 20, 20);
        if (jugadorRect.intersects(itemRect)) {
            itemX = -100; // sacar el ítem del área visible
            itemY = -100;
        }

        update(); // Redibujar la ventana
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    JuegoWidget ventana;
    ventana.show();

    return app.exec();
}


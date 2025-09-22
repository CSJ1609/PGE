#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
private:
    QString nombre;
    int x, y;

public:
    Item(const QString& nombre, int x, int y);
    QString getNombre() const;
    int getX() const;
    int getY() const;
};

#endif // ITEM_H


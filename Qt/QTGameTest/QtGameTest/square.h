#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItemGroup>
#include "grid.h"
#include <QTimer>
class SquarePiece : public QObject, public QGraphicsItemGroup {
    Q_OBJECT //needed to handle slots
public:
    Grid * m_grid;
    SquarePiece(Grid * grid, int xx, int yy);

    // move
    QTimer * m_timer;
    int limiter = 550;
    int movX=0,movY=0;
    bool falling = true; //spawns falling
    // ---



public slots:
    void move();

};

#endif // SQUARE_H

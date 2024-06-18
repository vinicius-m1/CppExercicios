#ifndef EXTRABLOCK_H
#define EXTRABLOCK_H
#include "grid.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>

class ExtraBlock : public QObject, public QGraphicsRectItem{
    Q_OBJECT //needed to handle slots
public:
    QTimer * m_timer;
    bool falling = true; //spawns falling

    int movX,movY;
    int limiter = 550;

    Grid * m_grid;
    ExtraBlock(Grid * grid);

public slots:
    void move();
    //void duplication();


};




#endif // EXTRABLOCK_H

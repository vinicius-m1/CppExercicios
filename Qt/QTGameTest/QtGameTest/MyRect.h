#ifndef MYRECT_H
#define MYRECT_H
#include "ExtraBlock.h"
#include"grid.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include"square.h"


#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{
public:

    int test=1;
    Grid grid;
    //std::vector<ExtraBlock*> blocks_in_scene;
    SquarePiece *current_piece = nullptr; // piece that the player has control at the time
    std::vector<QGraphicsItem*> blocks_in_scene;
    // polimorfismo é fo##

    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H

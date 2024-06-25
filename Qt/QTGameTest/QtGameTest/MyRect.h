#ifndef MYRECT_H
#define MYRECT_H
#include "ExtraBlock.h"
#include"grid.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>



#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{
public:


    int test=0;
    Grid grid;
    //std::vector<ExtraBlock*> blocks_in_scene;
    std::vector<QGraphicsItem*> blocks_in_scene;
    // polimorfismo é fo##

    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H

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



    Grid grid;
    std::vector<ExtraBlock*> blocks_in_scene;


    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H

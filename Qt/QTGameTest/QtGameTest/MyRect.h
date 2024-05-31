#ifndef MYRECT_H
#define MYRECT_H
#include"grid.h"
#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{
public:
    Grid grid;
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H

#ifndef EXTRABLOCK_H
#define EXTRABLOCK_H
#include <QGraphicsRectItem>
#include "grid.h"
#include <QObject>
#include <QTimer>
class ExtraBlock : public QObject, public QGraphicsRectItem{
    Q_OBJECT //needed to handle slots
public:
    QTimer * m_timer;
    int movX,movY;
    int limiter = 550;
    //bool duplication_able = false;
    Grid * m_grid;
    ExtraBlock(Grid * grid);

public slots:
    void move();
    //void duplication();


};




#endif // EXTRABLOCK_H

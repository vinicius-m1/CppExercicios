#ifndef EXTRABLOCK_H
#define EXTRABLOCK_H
#include <QGraphicsRectItem>
#include <QObject>

class ExtraBlock : public QObject, public QGraphicsRectItem{
    Q_OBJECT //needed to handle slots
public:

    int movX,movY; // define random number for each extra between -5 .. 5 in constructor
    int limiter = 200;
    bool duplication_able = false;
    ExtraBlock();

public slots:
    void move();
    void duplication();


};




#endif // EXTRABLOCK_H

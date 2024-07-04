#ifndef MYRECT_H
#define MYRECT_H
#include "ExtraBlock.h"
#include"grid.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include"PieceBase.h"
#include <QTimer>
#include <QFont>
#include <QGraphicsRectItem>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT //needed to handle slots
public:

    // positions stuff
    Grid grid;
    std::vector<ExtraBlock*> blocks_in_scene;

    //controls stuff
    PieceBase *current_piece = nullptr; // piece that the player has control at the time
    void keyPressEvent(QKeyEvent * event);

    //tick
    MyRect(){
        connect(timer,SIGNAL(timeout()), this, SLOT(Tick()) );
        timer->start(200);
    }
    QTimer * timer = new QTimer();

    //game ui
    QGraphicsTextItem * score;
    int points=0;
    QGraphicsRectItem * next_piece_pic;

    //spawns
    std::pair<int,int> rand_spawns;
    void SpawnExtraBlock();
    void SpawnSquare();
    void SpawnRandom();


public slots:
    void Tick();

};

#endif // MYRECT_H

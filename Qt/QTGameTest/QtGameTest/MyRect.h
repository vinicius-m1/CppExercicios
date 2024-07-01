#ifndef MYRECT_H
#define MYRECT_H
#include "ExtraBlock.h"
#include"grid.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include"PieceBase.h"


#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{
public:

    // positions stuff
    Grid grid;
    std::vector<ExtraBlock*> blocks_in_scene;

    //controls stuff
    PieceBase *current_piece = nullptr; // piece that the player has control at the time

    //tick
    void Tick(); // make timer for it later

    //spawns
    void SpawnExtraBlock();
    void SpawnSquare();
    void SpawnRandom();



    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H

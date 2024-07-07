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
    std::vector<PieceBase*> all_pieces;
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
    QGraphicsTextItem * stats;
    int points=0;
    QGraphicsRectItem * next_piece_pic;
    bool debug_mode = false; // turns off random spawn, turn on user spawn
    void GameOver();



    //spawns
    std::pair<int,int> rand_spawns;
    int num_cube=0,num_line=0,num_triangle=0,num_lpiece=0;
    void SpawnSquare();
    void SpawnCube();
    void SpawnRandom();
    void SpawnTriangle();
    void SpawnLPiece();

public slots:
    void Tick();

};

#endif // MYRECT_H

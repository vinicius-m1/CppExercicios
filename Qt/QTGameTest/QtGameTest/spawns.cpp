#include "MyRect.h"
#include "square.h"
#include "ExtraBlock.h"
#include <cstdlib>

//this file contain the spawn operations for the game


void MyRect::SpawnSquare(){
    SquarePiece * square = new SquarePiece(&grid);
    qDebug() << "Square created.";
    square->setPos(x(),y());

    scene()->addItem(square);
    square->SetBlocksInScene(&blocks_in_scene);
    //add the blocks inside piece to the blocks vector
    for (int i = 1; i<=square->number_of_blocks; i++){
        blocks_in_scene.push_back(square->GetBlock(i));
    }

    current_piece = square; // give control to player
};

void MyRect::SpawnExtraBlock(){

    // generate extra block instance (base block for all formats)
    ExtraBlock * extra = new ExtraBlock(&grid);
    QBrush brush(Qt::red);
    extra->setBrush(brush);

    QBrush line_piec(QImage(":/images/line_shaped.png"));
    next_piece_pic->setBrush(line_piec);

    extra->setPos(x(),y());
    scene()->addItem(extra);
    blocks_in_scene.push_back(extra); //accepts all formats of QGraphicsRectItem
};

void MyRect::SpawnRandom(){

    if(!(rand_spawns.second == 0))
        rand_spawns.first = ((std::rand()%6)+1);
        //second is the next piece to spawn
    rand_spawns.first = rand_spawns.second;
    rand_spawns.second = ((std::rand()%6)+1);
    QBrush line_piece(QImage(":/images/line_piece.png"));
    //qDebug()<< rand_spawns.first <<" " << rand_spawns.second;

    switch (rand_spawns.first){
    case(1):
        SpawnSquare();
        break;

    default: break;
    }

    switch(rand_spawns.second){
    case(1):
        next_piece_pic->setBrush(line_piece);



    default: break;
    }
};


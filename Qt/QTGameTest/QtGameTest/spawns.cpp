#include "MyRect.h"
#include "square.h"
#include "ExtraBlock.h"


//this file contain the spawn operations for the game


void MyRect::SpawnSquare(){
    SquarePiece * square = new SquarePiece(&grid);
    qDebug() << "Square created.";
    square->setPos(x(),y());

    scene()->addItem(square);

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

    extra->setPos(x(),y());
    scene()->addItem(extra);
    blocks_in_scene.push_back(extra); //accepts all formats of QGraphicsRectItem
};

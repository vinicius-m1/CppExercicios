#include "Tetris.h"
#include "line.h"
#include "cube.h"
#include "LPiece.h"
#include "ExtraBlock.h"
#include"triangle.h"
#include <cstdlib>

//this file contain the spawn operations for the game


void MyRect::SpawnLine(){
    num_line++;
    LinePiece * line = new LinePiece(&grid);
    //qDebug() << "Line created.";
    line->setPos(x(),y());

    scene()->addItem(line);
    all_pieces.push_back(line);
    line->SetBlocksInScene(&blocks_in_scene);
    //add the blocks inside piece to the blocks vector
    for (int i = 1; i<=line->number_of_blocks; i++){
        blocks_in_scene.push_back(line->GetBlock(i));
    }

    current_piece = line; // give control to player
};

void MyRect::SpawnCube(){
    num_cube++;
    CubePiece * cube = new CubePiece(&grid);
    //qDebug() << "Cube created.";
    cube->setPos(x(),y());
    all_pieces.push_back(cube);
    scene()->addItem(cube);
    cube->SetBlocksInScene(&blocks_in_scene);
    //add the blocks inside piece to the blocks vector
    for (int i = 1; i<=cube->number_of_blocks; i++){
        blocks_in_scene.push_back(cube->GetBlock(i));
    }
    current_piece = cube; // give control to player
};


void MyRect::SpawnLPiece(){
    num_lpiece++;
    LPiece * lpiece = new LPiece(&grid);
    //qDebug() << "L Piece created.";
    lpiece->setPos(x(),y()+60); //custom height
    all_pieces.push_back(lpiece);
    scene()->addItem(lpiece);
    lpiece->SetBlocksInScene(&blocks_in_scene);
    //add the blocks inside piece to the blocks vector
    for (int i = 1; i<=lpiece->number_of_blocks; i++){
        blocks_in_scene.push_back(lpiece->GetBlock(i));
    }
    current_piece = lpiece; // give control to player
};



void MyRect::SpawnTriangle(){
    num_triangle++;
    TrianglePiece * triangle = new TrianglePiece(&grid);
    //qDebug() << "Triangle created.";
    triangle->setPos(x(),y()+30); //custom height
    all_pieces.push_back(triangle);
    scene()->addItem(triangle);
    triangle->SetBlocksInScene(&blocks_in_scene);
    //add the blocks inside piece to the blocks vector
    for (int i = 1; i<=triangle->number_of_blocks; i++){
        blocks_in_scene.push_back(triangle->GetBlock(i));
    }
    current_piece = triangle; // give control to player
};

void MyRect::SpawnRandom(){

    rand_spawns.second = ((std::rand()%4)+1);


    switch (rand_spawns.first){
    case(1):
        SpawnLine();
        break;
    case(2):
        SpawnCube();
        break;
    case(3):
        SpawnTriangle();
        break;
    case(4):
        SpawnLPiece();
        break;
    default: break;
    }

    switch(rand_spawns.second){
    case(1):
        //QBrush line_piece(QImage(":/images/line_piece.png"));
        next_piece_pic->setBrush(QBrush(QImage(":/images/line_shaped.png")));
        break;
    case (2):
        next_piece_pic->setBrush(QBrush(QImage(":/images/square_shaped.png")));
        break;
    case(3):
        next_piece_pic->setBrush(QBrush(QImage(":/images/triangle_shaped.png")));
        break;
    case(4):
        next_piece_pic->setBrush(QBrush(QImage(":/images/l_piece.png")));

    default: break;
    }

    rand_spawns.first = rand_spawns.second;
};


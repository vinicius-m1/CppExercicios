#ifndef SQUARE_H
#define SQUARE_H

#include "PieceBase.h"
#include "grid.h"
#include "ExtraBlock.h"
#include <QTimer>
class SquarePiece : public QObject, public PieceBase {
    Q_OBJECT //needed to handle slots
public:
    Grid * m_grid;
    SquarePiece(Grid * grid);

    ~SquarePiece(){
        qDebug()<<"Square piece deleted.";
    };

    // members of this group
    ExtraBlock *block1;
    ExtraBlock *block2;
    ExtraBlock *block3;
    ExtraBlock *block4;
    ExtraBlock* GetBlock(int id);
    // -------------------

    // formation stuff
    //int number_of_formations = 2; now in contructor
    int number_of_blocks = 4;
    //int formation = 1;            now in contructor
    int x_correction=30, y_correction=0; //collision positions (values for default formation)

    void SetFormation(int t_formation); //change visually (in group)
    // ----------------------------


    // move stuff
    QTimer * m_timer;
    int limiter = 550;
    int movX=0,movY=0;
    bool falling = true; //spawns falling
    //bool controls = true; //user starts controlling -- now in contructor
    void moveRight();
    void moveLeft();
    // -----------------------------


public slots:
    void move();

};

#endif // SQUARE_H

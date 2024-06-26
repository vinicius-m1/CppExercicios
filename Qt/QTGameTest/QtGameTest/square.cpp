#include "square.h"


SquarePiece::SquarePiece(Grid * grid)
{

    m_grid = grid; // saves received grid to pass to blocks

    QBrush brush(Qt::cyan);  // Example: blue color

    QBrush test(Qt::green);  // debug color

    // Create individual block items and add them to the group
    block1 = new ExtraBlock(grid,true); // piece_mode = true
    block1->setBrush(test);
    block1->setPos(0, 0); // Adjust position as needed (position based on group)
    addToGroup(block1);


    block2 = new ExtraBlock(grid,true);
    block2->setBrush(brush);
    block2->setPos(30,0); // Adjust position as needed
    addToGroup(block2);

    block3 = new ExtraBlock(grid,true);
    block3->setBrush(brush);
    block3->setPos(60,0); // Adjust position as needed
    addToGroup(block3);

    block4 = new ExtraBlock(grid,true);
    block4->setBrush(brush);
    block4->setPos(90,0); // Adjust position as needed
    addToGroup(block4);


    //          MOVE RELATED STUFF

    //conect slot to timer, when timer runs out the slot is executed
    QTimer * timer = new QTimer();
    m_timer = timer;
    connect(timer,SIGNAL(timeout()), this, SLOT(move()) );

    timer->start(20);

    // -------------------------------------------------------------
}

void SquarePiece::SetFormation(int t_formation)
{
    // change piece formation visually in the group
    // 1 - default (horizontal line)
    // 2 - vertical line

    if (t_formation == 1){
        block1->setPos(0,0);
        block2->setPos(30,0);
        block3->setPos(60,0);
        block4->setPos(90,0);

        // change piece formation on collisions
        y_correction = 0;
        x_correction = 30;

    }
    else if(t_formation == 2){
        block1->setPos(0,0);
        block2->setPos(0,30);
        block3->setPos(0,60);
        block4->setPos(0,90);

        // change piece formation on collisions
        x_correction = 0;
        y_correction = 30;
    }

}


void SquarePiece::move()
{

    movY = -5;
    int destination = (y() - (movY-25)); //(25 is a constant offset)


    //hit occupied grid slot
    if (m_grid->IsOccupied(x(),destination) == true || m_grid->IsOccupied(x()+x_correction,destination+y_correction) == true || m_grid->IsOccupied(x()+x_correction+x_correction,destination+y_correction+y_correction) == true || m_grid->IsOccupied(x()+x_correction+x_correction+x_correction,destination+y_correction+y_correction+y_correction) == true){

        m_timer->stop(); // timer cant really stop because of rows possubly being deleted
        // decrease time to reduce performance hogging
        m_timer->start(100);

        falling = false;
        m_grid->SetOccupied(x(),y());  //block 1
        m_grid->SetOccupied(x()+x_correction,y()+y_correction);  //block 2
        m_grid->SetOccupied(x()+x_correction+x_correction,y()+y_correction+y_correction);  //block 3
        m_grid->SetOccupied(x()+x_correction+x_correction+x_correction,y()+y_correction+y_correction+y_correction);  //block 4

        qDebug() << "clock stopped bcs occupied. ";

        return;
    }


    // yeah, so many "+" but it was better for mental visualization


    // hit border
    // only checks first and last block when vertical formation
    if (destination >= (limiter) || destination+y_correction+y_correction+y_correction >= (limiter) ){

        m_grid->SetOccupied(x(),y());  //block 1
        m_grid->SetOccupied(x()+x_correction,y()+y_correction);  //block 2
        m_grid->SetOccupied(x()+x_correction+x_correction,y()+y_correction+y_correction);  //block 3
        m_grid->SetOccupied(x()+x_correction+x_correction+x_correction,y()+y_correction+y_correction+y_correction);  //block 4


        m_timer->stop(); // timer cant really stop because of rows possubly being deleted
        // decrease time to reduce performance hogging
        m_timer->start(100);


        falling = false;
        qDebug() << "clock stopped bcs border.";

        return;
    };

    //--------------------------------------------------------------------------------------
    // IF BELLOW IS FREE
    //--------------------------------------------------------------------------------------

    if (falling == false){ //if was stopped and now moving, remove old "seat"
        m_grid->RemoveOccupied(x(),y());
        m_grid->RemoveOccupied(x()+x_correction,y()+y_correction);
        m_grid->RemoveOccupied(x()+x_correction+x_correction,y()+y_correction+y_correction);
        m_grid->RemoveOccupied(x()+x_correction+x_correction+x_correction,y()+y_correction+y_correction+y_correction);
    }

    falling = true;

    setPos(x()+movX,y()-movY);

};


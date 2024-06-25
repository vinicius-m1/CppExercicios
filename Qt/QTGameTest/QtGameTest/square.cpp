#include "square.h"
#include "ExtraBlock.h"
                                //external x and y
SquarePiece::SquarePiece(Grid * grid, int xx, int yy)
{

    m_grid = grid; // saves received grid to pass to blocks

    QBrush brush(Qt::cyan);  // Example: blue color

    // Create individual block items and add them to the group
    ExtraBlock *block1 = new ExtraBlock(grid,true); // piece_mode = true
    block1->setBrush(brush);
    block1->setPos(x(), y()); // Adjust position as needed (position based on group)
    addToGroup(block1);


    ExtraBlock *block2 = new ExtraBlock(grid,true);
    block2->setBrush(brush);
    block2->setPos(x()+30,y()+0); // Adjust position as needed
    addToGroup(block2);

    ExtraBlock *block3 = new ExtraBlock(grid,true);
    block3->setBrush(brush);
    block3->setPos(x()+60,y()+0); // Adjust position as needed
    addToGroup(block3);

    ExtraBlock *block4 = new ExtraBlock(grid,true);
    block4->setBrush(brush);
    block4->setPos(x()+90,y()+0); // Adjust position as needed
    addToGroup(block4);


    //          MOVE RELATED STUFF

    //conect slot to timer, when timer runs out the slot is executed
    QTimer * timer = new QTimer();
    m_timer = timer;
    connect(timer,SIGNAL(timeout()), this, SLOT(move()) );

    timer->start(20);

    // -------------------------------------------------------------
}


void SquarePiece::move()
{

    movY = -5;
    int destination = (y() - (movY-25));


    //hit occupied grid slot
    if (m_grid->IsOccupied(x(),destination) == true || m_grid->IsOccupied(x()+30,destination) == true || m_grid->IsOccupied(x()+60,destination) == true || m_grid->IsOccupied(x()+90,destination) == true){

        m_timer->stop(); // timer cant really stop because of rows possubly being deleted
        // decrease time to reduce performance hogging
        m_timer->start(100);

        falling = false;
        m_grid->SetOccupied(x(),y());  //block 1
        m_grid->SetOccupied(x()+30,y());  //block 2
        m_grid->SetOccupied(x()+60,y());  //block 3
        m_grid->SetOccupied(x()+90,y());  //block 4

        qDebug() << "clock stopped bcs occupied. ";

        return;
    }


    // ALL OF THESE CHECKS SHOULD INCLUDE ALL BLOCKS LOCATIONS IN GROUP, EVEN IF ONLY BY MATH


    // hit border
    if (destination >= (limiter)){

        m_grid->SetOccupied(x(),y());  //block 1
        m_grid->SetOccupied(x()+30,y());  //block 2
        m_grid->SetOccupied(x()+60,y());  //block 3
        m_grid->SetOccupied(x()+90,y());  //block 4

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

    if (falling == false) //if was stopped and now moving, remove old "seat"
        m_grid->RemoveOccupied(x(),y());

    falling = true;

    setPos(x()+movX,y()-movY);

};


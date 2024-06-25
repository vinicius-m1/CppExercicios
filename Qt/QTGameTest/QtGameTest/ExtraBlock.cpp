#include "ExtraBlock.h"


ExtraBlock::ExtraBlock(Grid * grid){

    setRect(0,0,30,30);

    movY =0;
    movX=0;
    m_grid = grid;

    //conect slot to timer, when timer runs out the slot is executed
    QTimer * timer = new QTimer();
    m_timer = timer;
    connect(timer,SIGNAL(timeout()), this, SLOT(move()) );


    timer->start(20);
}


void ExtraBlock::move()
{

    movY = -5;
    int destination = (y() - (movY-25));


    //hit occupied grid slot
    if (m_grid->IsOccupied(x(),destination) == true){


        m_timer->stop(); // timer cant really stop because of rows possubly being deleted
        // decrease time to reduce performance hogging
        m_timer->start(100);

        falling = false;
        m_grid->SetOccupied(x(),y());

        qDebug() << "clock stopped bcs occupied. ";

        return;
    }


    // hit border
    if (destination >= (limiter)){
        m_grid->SetOccupied(x(),y());

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

#include "ExtraBlock.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include "grid.h"
ExtraBlock::ExtraBlock(Grid * grid){

    setRect(0,0,30,30);
    //movX = rand() % 8;
    //movY = rand() % 5;
    movY =0;
    movX=0;
    m_grid = grid;
    //int neg_chance = rand() % 10;
    //if(movY>5){movX=((movX+1)*-1);};
    //if(neg_chance<5){movY=(movY*-1);};
    //if (movY==0 && movX==0){movX+=1;};

    //conect slot to timer, when timer runs out the slot is executed
    QTimer * timer = new QTimer();
    m_timer = timer;
    connect(timer,SIGNAL(timeout()), this, SLOT(move()) );

    //QTimer * timerDup = new QTimer();
    //connect(timerDup,SIGNAL(timeout()), this, SLOT(duplication()) );

    //timerDup->start(5000);
    timer->start(20);
}

//void ExtraBlock::duplication(){

//   duplication_able = true;

//};


void ExtraBlock::move()
{

    movY = -5;
    int destination = (y() - (movY-25));


    //hit occupied grid slot
    if (m_grid->IsOccupied(x(),destination) == true){
        m_timer->stop();
        qDebug() << "clock stopped bcs occupied. ";
        m_grid->SetOccupied(x(),y());
        return;
    }


    // hit border
    if (destination >= (limiter)){
        m_grid->SetOccupied(x(),y());
        m_timer->stop();
        qDebug() << "clock stopped bcs border.";
        return;
    };

    setPos(x()+movX,y()-movY);

};

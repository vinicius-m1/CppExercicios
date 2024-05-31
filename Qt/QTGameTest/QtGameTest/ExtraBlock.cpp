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

    //extra block movement every 20 miliseconds (timer)

        //int mov = 5; in .h
        //int limiter = 200;

    //if (x() > 200 || y() < -200 ){ExtraBlock::~ExtraBlock() ;};



    //if (x()+movX > (limiter) || y() - movY < (limiter*-1) ){
            //movX = movX*(-1);
            //movY = movY*(-1);

            //if (duplication_able){
              //  ExtraBlock * extra = new ExtraBlock();
            //    extra->setPos(x(),y());
          //      scene()->addItem(extra);
        //    };

      //  };
    //if (x()+movX < (limiter*-1) || y() - movY > (limiter) ){
     //       movX = movX*(-1);
   //         movY = movY*(-1);

            //int temp = movX;
            //movX = movY;
            //movY = temp;

            //if (duplication_able){
                //ExtraBlock * extra = new ExtraBlock();
                //extra->setPos(x(),y());
                //scene()->addItem(extra);
     //   };
    //};
    //Grid grid; // tem que ser dinamico, obviamente, fui burro
    movY = -5;
    int destination = (y() - (movY-25));

    //border check
    //if (destination < (limiter))


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

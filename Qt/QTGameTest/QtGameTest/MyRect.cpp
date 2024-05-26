#include "MyRect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "ExtraBlock.h"
void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){

        //verify boundaries
        if (x()-10 < -60){return;};

        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){

        //verify boundaries

        if (x()+10 > 60){return;};

        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        //verify boundaries
        if (y()-10 < -60){return;};
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){

        //verify boundaries
        if (y()+10 > 60){return;};

        setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        // generate extra block
        ExtraBlock * extra = new ExtraBlock();
        extra->setPos(x(),y());
        scene()->addItem(extra);
    }

    qDebug() << "Position:" << x() << "  "<< y() ;
}

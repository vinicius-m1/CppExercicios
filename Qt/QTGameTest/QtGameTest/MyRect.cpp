#include "MyRect.h"
#include <QKeyEvent>
#include <QDebug>
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

    qDebug() << "Position:" << x() << "  "<< y() ;
}

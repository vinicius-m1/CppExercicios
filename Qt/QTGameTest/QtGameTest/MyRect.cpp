#include "MyRect.h"
#include "square.h" // be carefull, it didnt have the extrablock .h in here and it worked (?)

void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){

        //verify boundaries
        if (x()-10 < 250){return;};

        setPos(x()-30,y());
    }
    else if (event->key() == Qt::Key_Right){

        //verify boundaries

        if (x()+10 > 520){return;};

        setPos(x()+30,y());
    }
    else if (event->key() == Qt::Key_Up){
        //verify boundaries
        if (y()-10 < -600){return;};
        setPos(x(),y()-10);

    }

    else if (event->key() == Qt::Key_0){
        // temporary - spawn square

        SquarePiece * square = new SquarePiece(&grid);
        qDebug() << "Square created.";

        square->setPos(x(),y());



        scene()->addItem(square);
        blocks_in_scene.push_back(square);
        current_piece = square; // give control to player

    }

    else if (event->key() == Qt::Key_1){
        // temporary - change current piece

        test = test+1;
        if(test>2)
            test = 1;

        if (current_piece)
            current_piece->SetFormation(test);
            //current_piece->setRotation(test); // just for test

        qDebug()<< "tou tried to rotate the piece.";
    }



    else if (event->key() == Qt::Key_Space){


        // generate extra block instance (base block for all formats)
        ExtraBlock * extra = new ExtraBlock(&grid);
        QBrush brush(Qt::red);  // Example: blue color
        extra->setBrush(brush);
        // -------- i -------- extra should be renamed "format later"

        extra->setPos(x(),y());
        scene()->addItem(extra);
        // create vector to store all blocks
        blocks_in_scene.push_back(extra); //accepts all formats of QGraphicsRectItem

        //then check grid.row_to_destroy to see if something has to be destroyed and where
        if (grid.row_to_destroy.first == true){

            for (int i=0;i<blocks_in_scene.size();){
                if (blocks_in_scene.at(i)->y() == grid.row_to_destroy.second){
                    // deletes object
                    delete blocks_in_scene.at(i);
                    // delete from vector
                    std::swap(blocks_in_scene.at(i), blocks_in_scene.back()); //move it to the back
                    blocks_in_scene.pop_back(); // deletes the back
                } else {i++;}; // only increment if nothing deleted
            }
            // after all is deleted
            grid.DestroyRow(grid.row_to_destroy.second); // destroy blocks position data inside grid
            grid.row_to_destroy = {false,0};

            // ------ i ------- maybe later make exclusive routine just to check for full rows

        }
    }


    qDebug() << "Position:" << x() << "  "<< y() ;
}

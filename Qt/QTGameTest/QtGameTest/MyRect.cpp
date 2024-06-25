#include "MyRect.h"
#include "square.h" // be caraful, it didnt have the extrablock .h in here and it worked (?)


void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){

        //verify boundaries
        if (x()-10 < -600){return;};

        setPos(x()-30,y());
    }
    else if (event->key() == Qt::Key_Right){

        //verify boundaries

        if (x()+10 > 600){return;};

        setPos(x()+30,y());
    }
    else if (event->key() == Qt::Key_Up){
        //verify boundaries
        if (y()-10 < -600){return;};
        setPos(x(),y()-10);

    }

    else if (event->key() == Qt::Key_0){
        // temporary - spawn square

       // TetrisPiece * square = new TetrisPiece(&grid);
        //square->setPos(x()+100,y());
        //blocks_in_scene.push_back(square);
        //scene()->addItem(square);




    }

    else if (event->key() == Qt::Key_Space){


        // generate extra block instance (base block for all formats)
        ExtraBlock * extra = new ExtraBlock(&grid);
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

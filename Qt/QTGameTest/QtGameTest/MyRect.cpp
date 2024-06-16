#include "MyRect.h"



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


    else if (event->key() == Qt::Key_Space){
        // generate extra block
        ExtraBlock * extra = new ExtraBlock(&grid);

        extra->setPos(x(),y());
        scene()->addItem(extra);
        // create vector to store all blocks
        blocks_in_scene.push_back(extra);

        //then check grid.row_to_destroy to see if something has to be destroyed and where
        if (grid.row_to_destroy.first == true){

            for (int i=0;i<blocks_in_scene.size();){
                if (blocks_in_scene.at(i)->y() == grid.row_to_destroy.second){
                    // deletes from screen
                    //scene()->removeItem(blocks_in_scene.at(i)); // doesnt really need to happen deleting the object does it
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
        }

                    // THOSE WHO FALL BY EFFECT OF A ROW BELLOW IT BEING DELETED DOES NOT UPDATE THE OCCUPIED VECTOR

        //qDebug() << "tamanho blocks in scene" <<grid.blocks_in_scene.size();

    }

    qDebug() << "Position:" << x() << "  "<< y() ;
}

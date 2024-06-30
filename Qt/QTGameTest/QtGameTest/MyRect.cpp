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

        //add the blocks inside piece to the blocks vector
        //blocks_in_scene.push_back(square);
        for (int i = 1; i<=square->number_of_blocks; i++){
            blocks_in_scene.push_back(square->GetBlock(i));
        }

        current_piece = square; // give control to player

    }

    else if (event->key() == Qt::Key_1){
        // temporary - change current piece

        if (current_piece){ // if not nullptr
            if(current_piece->formation==current_piece->number_of_formations) //if max
                current_piece->SetFormation(1);
            else
                current_piece->SetFormation(current_piece->formation + 1);
        }
        qDebug()<< "tou tried to rotate the piece.";
    }



    else if (event->key() == Qt::Key_Space){


        // generate extra block instance (base block for all formats)
        ExtraBlock * extra = new ExtraBlock(&grid);
        QBrush brush(Qt::red);
        extra->setBrush(brush);
        // -------- i -------- extra should be renamed "format later"

        extra->setPos(x(),y());
        scene()->addItem(extra);
        // create vector to store all blocks
        blocks_in_scene.push_back(extra); //accepts all formats of QGraphicsRectItem
        qDebug() << " will try to check from full row ";
        //then check grid.row_to_destroy to see if something has to be destroyed and where
        if (grid.row_to_destroy.first == true){
            for (int i=0;i<blocks_in_scene.size();){
                if (blocks_in_scene.at(i)->virtual_position.second == grid.row_to_destroy.second){ // first part of OR is legacy blocks_in_scene.at(i)->y() == grid.row_to_destroy.second ||
                    // deletes object

                    if (blocks_in_scene.at(i)->piece_mode == false)
                        delete blocks_in_scene.at(i);
                    else{
                        blocks_in_scene.at(i)->setBrush(brush);
                        blocks_in_scene.at(i)->exist = false;
                        // not as i intended to do but, couldnt set block as nullptr from here, so square does it.
                    }

                    //if(blocks_in_scene.at(i)){

                    //    delete blocks_in_scene.at(i); //crashing aroud here, things are not beeing remove from occupied too
                    //    blocks_in_scene.at(i) = nullptr;
                    //    qDebug() << "deleted and set null";
                    //}

                    // delete from vector
                    std::swap(blocks_in_scene.at(i), blocks_in_scene.back()); //move it to the back
                    blocks_in_scene.pop_back(); // deletes the back
                } else {i++;}; // only increment if nothing deleted
            }
            qDebug() << "deleted ALL FROM SCREEN";

            // after all is deleted
            grid.DestroyRow(grid.row_to_destroy.second); // destroy blocks position data inside grid
            grid.row_to_destroy = {false,0};

            // ------ i ------- maybe later make exclusive routine just to check for full rows

        } else {qDebug() << "no row to remove";}
    }


    qDebug() << "Position:" << x() << "  "<< y() ;
}

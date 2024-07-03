#include "MyRect.h"
#include "square.h"



void MyRect::Tick(){

    qDebug()<<"tic-tac";
    setFocus();


    if(grid.row_to_destroy.empty())
        return;

    //check grid.row_to_destroy to see if something has to be destroyed and where
    QBrush brush(Qt::white);
    for(int r=0; r<grid.row_to_destroy.size(); r++){
        for (int i=0;i<blocks_in_scene.size();){
            if (blocks_in_scene.at(i)->virtual_position.second == grid.row_to_destroy.at(r)){

                // deletes object - checking if independent block - soon legacy
                if (blocks_in_scene.at(i)->piece_mode == false)
                    delete blocks_in_scene.at(i);
                else{
                    blocks_in_scene.at(i)->setBrush(brush);
                    blocks_in_scene.at(i)->exist = false; //flags to be deleted from inside square
                }

                // delete from vector
                std::swap(blocks_in_scene.at(i), blocks_in_scene.back());
                blocks_in_scene.pop_back();

            } else {i++;}; // only increment if nothing deleted
        }

        qDebug() << "deleted ALL FROM row "<< r;
        grid.DestroyRow(grid.row_to_destroy.at(r)); // destroy blocks position data inside grid
    }
    // after all is deleted
    grid.row_to_destroy.clear(); //wipes flagging vector

};




















//==============================================================================================
//                            VVV  CONTROLS SECTION  VVV


void MyRect::keyPressEvent(QKeyEvent *event){

    // -----------------------------
    //      LEFT KEY PRESSED
    // -----------------------------
    if (event->key() == Qt::Key_Left){

        if(current_piece){ // if something exists

            if (!current_piece->controls) //if player can control
                return;
            //if all good
            current_piece->moveLeft();
        }
    }


    // -----------------------------
    //      RIGHT KEY PRESSED
    // -----------------------------
    else if (event->key() == Qt::Key_Right){

        if(current_piece){ // if something exists

            if (!current_piece->controls) //if player can control
                return;
            //if all good
            current_piece->moveRight();
        }

    }




    //      0 KEY PRESSED
    else if (event->key() == Qt::Key_0){
        SpawnSquare();
    }

    //      SPACEBAR KEY PRESSED
    else if (event->key() == Qt::Key_1){
        SpawnExtraBlock();
    }



    // -----------------------------
    //      1 KEY PRESSED
    // -----------------------------

    else if (event->key() == Qt::Key_Space){
        // temporary - change current piece

        if (current_piece){ // if not nullptr

            //this will change later REMOVE
            if (!current_piece->controls) //check if player can control
                return;


            if(current_piece->formation==current_piece->number_of_formations) //if max
                current_piece->SetFormation(1);
            else
                current_piece->SetFormation(current_piece->formation + 1);
        }
        qDebug()<< "you tried to rotate the piece.";
    }
    // --------------------------------------------------------


    qDebug() << "Position:" << x() << "  "<< y() ;
}

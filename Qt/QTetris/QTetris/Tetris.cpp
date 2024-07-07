#include "Tetris.h"
#include "line.h"
#include <QMessageBox>


void MyRect::Tick(){

    //routine stuff
    //qDebug()<<"tic-tac";
    setFocus();

    if(grid.game_over){
        grid.game_over=false;
        GameOver();
    }

    //update score
    score->setPlainText(QString::number(points));
    //update statistics
    stats->setPlainText(QString::number(num_line) + "x\n\n\n" + QString::number(num_triangle) + "x\n\n\n"+ QString::number(num_cube) + "x\n\n\n\n"+ QString::number(num_lpiece) + "x\n\n\n"+ QString::number(0) + "x");

    //spawn next pieces
    if((current_piece && !(current_piece->falling) || current_piece == nullptr) && (!debug_mode))
        SpawnRandom();


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
                //qDebug()<< "size was: "<<blocks_in_scene.size();
                blocks_in_scene.pop_back();
                //qDebug()<< "size is: "<<blocks_in_scene.size();
            } else {i++;}; // only increment if nothing deleted
        }

        //qDebug() << "deleted ALL FROM row "<< r;
        grid.DestroyRow(grid.row_to_destroy.at(r)); // destroy blocks position data inside grid
        points = points + (1*grid.row_to_destroy.size());
    }
    // after all is deleted
    grid.row_to_destroy.clear(); //wipes flagging vector

};

void MyRect::GameOver(){

    timer->stop();
    grid.game_over == false;
    // clear screen
    points = 0;
    num_cube=0,num_line=0,num_triangle=0,num_lpiece=0;


    for(int i = 0; i < blocks_in_scene.size();i++){
        blocks_in_scene.at(i)->exist=false;
        blocks_in_scene.at(i) = nullptr;
    }

    for(int i = 0; i < all_pieces.size();i++){
        delete all_pieces.at(i);
        all_pieces.at(i) = nullptr;
    }

    all_pieces.clear();
    grid.occupied.clear();
    blocks_in_scene.clear();

    // game over prompt, restart or quit
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(nullptr, "):", "Game Over! Restart?");
    if(btn == QMessageBox::Yes){
        timer->start(200);
    } else
        qApp->quit();
};








//==============================================================================================
//                            VVV  CONTROLS SECTION  VVV


void MyRect::keyPressEvent(QKeyEvent *event){

    // -----------------------------
    //      LEFT KEY PRESSED (OR A)
    // -----------------------------
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){

        if(current_piece){ // if something exists

            if (!current_piece->controls) //if player can control
                return;
            //if all good
            current_piece->moveLeft();
        }
    }


    // -----------------------------
    //      RIGHT KEY PRESSED (OR D)
    // -----------------------------
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){

        if(current_piece){ // if something exists

            if (!current_piece->controls) //if player can control
                return;
            //if all good
            current_piece->moveRight();
        }

    }

    //      0 KEY PRESSED
    else if (event->key() == Qt::Key_0 && debug_mode){
        SpawnLine();
    }

    //      7 KEY PRESSED
    else if (event->key() == Qt::Key_7 && debug_mode){
        SpawnLPiece();
    }


    //      9 KEY PRESSED
    else if (event->key() == Qt::Key_9 && debug_mode){
        SpawnCube();
    }


    //      8 KEY PRESSED
    else if (event->key() == Qt::Key_8 && debug_mode){
        SpawnTriangle();
    }

    else if (event->key() == Qt::Key_Space){
        // change current piece

        if (current_piece){ // if not nullptr

            //this will change later REMOVE
            if (!current_piece->controls) //check if player can control
                return;

            if(current_piece->formation==current_piece->number_of_formations) //if max
                current_piece->SetFormation(1);
            else
                current_piece->SetFormation(current_piece->formation + 1);
        }
        //qDebug()<< "you tried to rotate the piece.";
    }
    // --------------------------------------------------------


    //qDebug() << "Position:" << x() << "  "<< y() ;
}

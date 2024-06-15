#include "grid.h"
#include "QDebug"
#include"algorithm"


void Grid::SetOccupied(int x, int y)
{
    std::pair<int,int> temp(x,y);
    occupied.push_back(temp);
    qDebug() << "occupied at:" << temp.first << "  "<< temp.second <<x << " " <<y << "size: "<<occupied.size();


    // see how many itens are in a row (basing on occupied)
    int y_amount = 0;
    for (int i =0; i < occupied.size() ; i++){
        if (occupied.at(i).second == y){
            y_amount++;
            qDebug() << "there are "<<y_amount<< " blocks in the "<< y << "row.";
        }
    };

    // if reached the limit of the row size, the row is deleted
    int row_horizontal_size = 16; // change later
    if (y_amount >= row_horizontal_size){
        qDebug() << "row shall be destroyed!";
        DestroyRow(y);
    }

}

void Grid::DestroyRow(int y)
{
    // remove from occupied
    // Using std::remove_if with a lambda function
    occupied.erase(std::remove_if(occupied.begin(), occupied.end(),
                                  [&y](const std::pair<int, int>& element) {
                                      return element.second == y;
                                  }),
                   occupied.end()); //removes all occurences


    // remove from scene... somehow



}

bool Grid::IsOccupied(int x, int y)
{
    std::pair<int,int> search(x,y);


    //auto it = std::find(occupied.begin(),occupied.end(), search);
    //if (it != occupied.end()){
    //        qDebug() << "already occupied" <<x << " " <<y;
    //        return (true);
    //}

    for (int i=0; i<occupied.size();i++){
        if (occupied.at(i) == search){
            qDebug() << "already occupied" <<x << " " <<y << "size: "<<occupied.size();
            return (true);
        }
    }

    qDebug() << "nothing found at "<<x << " " <<y << "size: "<<occupied.size();
    return (false);
}

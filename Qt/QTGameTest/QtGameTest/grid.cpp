#include "grid.h"
//#include "QDebug"
//#include"algorithm"

#include "ExtraBlock.h" //idk what i did but test with this
#include "connector.h" // wont work bcs not same instance

void Grid::SetOccupied(int x, int y)
{

    if (Grid::IsOccupied(x,y))
        return;

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
    int row_horizontal_size = 5; // change later
    if (y_amount >= row_horizontal_size){
        qDebug() << "row shall be destroyed!";

        // MyRect will check this and call DestroyRow (crazy, but due to syncronization issues)
        row_to_destroy = {true,y};

        //DestroyRow(y);
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


}

bool Grid::IsOccupied(int x, int y)
{
    std::pair<int,int> search(x,y);

    for (int i=0; i<occupied.size();i++){
        if (occupied.at(i) == search){
            qDebug() << "already occupied" <<x << " " <<y << "size: "<<occupied.size();
            return (true);
        }
    }

    qDebug() << "nothing found at "<<x << " " <<y << "size: "<<occupied.size();
    return (false);
}

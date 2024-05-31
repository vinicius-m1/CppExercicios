#include "grid.h"
#include "QDebug"
#include"algorithm"
void Grid::SetOccupied(int x, int y)
{
    std::pair<int,int> temp(x,y);
    occupied.push_back(temp);
    qDebug() << "occupied at:" << temp.first << "  "<< temp.second <<x << " " <<y << "size: "<<occupied.size();
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

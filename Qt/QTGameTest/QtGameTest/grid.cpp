#include "grid.h"
//#include "QDebug"
//#include"algorithm"

#include "ExtraBlock.h" //idk what i did but test with this


void Grid::SetOccupied(int x, int y)
{

    if (Grid::IsOccupied(x,y))
        return;

    std::pair<int,int> temp(x,y);
    occupied.push_back(temp);
    //qDebug() << "occupied at:" << temp.first << "  "<< temp.second <<x << " " <<y << "size: "<<occupied.size();


    //std::vector<int> repeatedNumbers;

    std::unordered_map<int, int> countMap;

    // count occurrences of each number in occupied vector
    for (const auto& pair : occupied) {
        countMap[pair.second]++;
    }

    // check if any number appears 10 or more times
    for (const auto& pair : countMap) {
        if (pair.second >= 10) {
            row_to_destroy.push_back(pair.first);
        }
    }

}

void Grid::DestroyRow(int y)
{

    qDebug() << "remove row "<< y;
    // remove from occupied
    // Using std::remove_if with a lambda function
    occupied.erase(std::remove_if(occupied.begin(), occupied.end(),
                                  [&y](const std::pair<int, int>& element) {
                                      return element.second == y;
                                  }),
                   occupied.end()); //removes all occurences
qDebug() << "removed all from occupied";
}

void Grid::RemoveOccupied(int x, int y)
{

    //remove from occupied
    // only one item
    qDebug() << "remove one item";
    occupied.erase(std::remove_if(occupied.begin(), occupied.end(),
                                  [&x, &y](const std::pair<int, int>& element) {
                                      return element.first == x && element.second == y;
                                  }),
                   occupied.end());


}

bool Grid::IsOccupied(int x, int y)
{
    std::pair<int,int> search(x,y);

    for (int i=0; i<occupied.size();i++){
        if (occupied.at(i) == search){
            //qDebug() << "already occupied" <<x << " " <<y << "size: "<<occupied.size();
            return (true);
        }
    }

    //qDebug() << "nothing found at "<<x << " " <<y << "size: "<<occupied.size();
    return (false);
}

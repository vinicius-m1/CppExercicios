#ifndef GRID_H
#define GRID_H
#include<vector>

class Grid{

protected:
    std::vector<std::pair<int,int>> occupied;
public:
    bool IsOccupied(int x,int y);

    void SetOccupied(int x,int y);

};



#endif // GRID_H

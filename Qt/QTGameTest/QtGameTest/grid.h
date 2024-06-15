#ifndef GRID_H
#define GRID_H
#include<vector>

class Grid{

protected:
    std::vector<std::pair<int,int>> occupied;
    //std::vector<ExtraBlock*> blocks_in_scene;
public:

    bool IsOccupied(int x,int y);

    void SetOccupied(int x,int y);

    void DestroyRow(int y);

};



#endif // GRID_H

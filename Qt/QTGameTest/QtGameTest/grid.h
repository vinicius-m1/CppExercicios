#ifndef GRID_H
#define GRID_H
//#include <sys/types.h>
#include <QObject>
#include <vector>

//#include "ExtraBlock.h"
//#include "MyRect.h"
#include "QDebug"

#include"algorithm"

class Grid : public QObject{

protected:

    std::vector<std::pair<int,int>> occupied;

public:

    std::vector<int> row_to_destroy; // from grid DestroyRow to MyRect.cpp direct access
    int row_horizontal_size = 10; // max quant of block in each row

    //std::vector<ExtraBlock::ExtraBlock*> blocks_in_scene; //public so MyRect.cpp can access

    bool IsOccupied(int x,int y);

    void SetOccupied(int x,int y);

    void DestroyRow(int y);

    void RemoveOccupied(int x,int y);

};



#endif // GRID_H

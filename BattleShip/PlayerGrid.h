#pragma once
#include "GridAbstract.h"

class PlayerGrid : public GridAbstract
{
public:
    PlayerGrid(int gridDimension);
    virtual ~PlayerGrid();

    std::string gridRowString(int row);

    // generate the ships on the grid
    void placeShips(int numShips);

//    virtual std::string gridString();

private:
    int m_dimension;
};
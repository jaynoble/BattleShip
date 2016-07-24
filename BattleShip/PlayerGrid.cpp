#include "PlayerGrid.h"

PlayerGrid::PlayerGrid(int gridDimension) :
    GridAbstract(gridDimension),
    m_dimension(gridDimension)
{
}


PlayerGrid::~PlayerGrid()
{
}

std::string PlayerGrid::gridRowString(int row)
{
    std::string rowString;
    for (int index = 0; index < m_dimension; ++index)
        rowString += " " + gridStatusString(row, index) + " ";  // TODO gridStatusString may be what's responsible for showing ships (Player) or not (CPU)
    return rowString;
}

void PlayerGrid::placeShips(int numShips)
{
    // for each specified ship in Navy
    // pick a random spot on the grid and mark
    // look shipSize/2 spaces in each direction to see if it can fit
    // place the ship if it can fit
    // mark it as too big for that ship if it can't

    // for testing, create a static placement of ships
}

/*std::string PlayerGrid::gridString()
{
    
}*/

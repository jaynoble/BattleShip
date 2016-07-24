#include "CPUGrid.h"


CPUGrid::CPUGrid(int gridDimension) :
    GridAbstract(gridDimension),
    m_dimension(gridDimension)
{
}


CPUGrid::~CPUGrid()
{
}

// get the status of the grid row in string form
std::string CPUGrid::gridRowString(int row)
{
    std::string rowString;
    for (int index = 0; index < m_dimension; ++index)
        rowString += " " + gridStatusString(row, index) + " ";  // TODO gridStatusString may be what's responsible for showing ships (Player) or not (CPU)
    return rowString;
}



#include "GridAbstract.h"
#include "Ship.h"
#include "ShipPlacer.h"


GridAbstract::GridAbstract(int dimension) :
    m_dimension(dimension)
{
    // initialize the grid to no ships, no hits, no misses, just water
    m_gridStatus = std::vector< std::vector<GridStatus> >(m_dimension, std::vector<GridStatus>(m_dimension, GridStatus::WATER));
    // create and place ships
    placeShips();
}


GridAbstract::~GridAbstract()
{
}

/*
    1  2  3  4  5  \n   // indent 4, SIZE(# + 2spaces)
   --------------- \n   // indent 3, 3*SIZE(dashes) + space
A | o  o  o  o  o |\n   // indent 0, LETTER space | <content> |
B | o  o  o  o  o |\n
C | o  o  o  o  o |\n
D | o  o  o  o  o |\n
E | o  o  o  o  o |\n
   --------------- \n
*/
/*std::string GridAbstract::display()
{
    return "";
}*/

std::string GridAbstract::columnHeaderString()
{
    std::string header = "    ";
    for (int number = 1; number <= m_dimension; ++number)
        header += std::to_string(number) + "  ";
    header += "\n";

    return header;
}

std::string GridAbstract::rowHeaderString(int rowIndex)
{
    _ASSERT(0 <= rowIndex && rowIndex < m_dimension);

    char letter = ACHAR + rowIndex;
    std::string header(1,letter);
    header += " |";

    return header;
}

std::string GridAbstract::rowLineString()
{
    std::string line = "   ";
    for (int dash = 0; dash < m_dimension; ++dash)
        line += "---";
    line += " \n";
    
    return line;
}

int GridAbstract::dimension()
{
    return m_dimension;
}

// Generic format of grid border with content passed in
std::string GridAbstract::gridString()
{
    std::string gridDisplayString = columnHeaderString() + rowLineString();
    for (int rowIndex = 0; rowIndex < m_dimension; ++rowIndex)
    {
        gridDisplayString += rowHeaderString(rowIndex);
        // gridRow content provided by the current grid object
        gridDisplayString += this->gridRowString(rowIndex);
        gridDisplayString += "|\n";
    }
    gridDisplayString += rowLineString();

    return gridDisplayString;
}

std::string GridAbstract::gridStatusString(int row, int column)
{
    std::string statusString;
    switch (m_gridStatus[row][column])
    {
    case GridStatus::WATER:
        statusString = "-";
        break;
    case GridStatus::SHIP:
        statusString = "S";
        break;
    case GridStatus::HIT:
        statusString = "X";
        break;
    case GridStatus::MISS:
        statusString = "o";
        break;
    default:
        _ASSERT(false);
        break;
    }
    return statusString;
}

GridAbstract::GridStatus GridAbstract::status(int row, int column)
{
    return m_gridStatus[row][column];
}

std::vector<Ship>& GridAbstract::ships()
{
    return m_ships;
}



void GridAbstract::placeShips()
{
    Ship carrier = Carrier();
    ShipPlacer(*this, carrier);
    m_ships.emplace_back(carrier);
    // for each specified ship in Navy
    // pick a random spot on the grid and mark
    // look shipSize/2 spaces in each direction to see if it can fit
    // place the ship if it can fit
    // mark it as too big for that ship if it can't
}
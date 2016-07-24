#pragma once
#include "GridInterface.h"
#include <vector>

class Ship;

// TODO: add override and const where appropriate
class GridAbstract : public GridInterface
{
public:
    GridAbstract(int dimension);
    virtual ~GridAbstract();

    // declare strongly typed eunum for status
    enum class GridStatus {WATER, SHIP, HIT, MISS}; // TODO: can this be moved to interface?

    int dimension();

    std::string gridString();

    virtual std::string gridRowString(int row) = 0;

    std::string gridStatusString(int row, int column);  // TODO: return char?

    GridStatus status(int row, int column); // constexpr

    std::vector<Ship>& ships();

    void placeShips();

private:
    std::string columnHeaderString(); 

    std::string rowHeaderString(int row); 

    std::string rowLineString();

    int m_dimension;
    std::vector< std::vector<GridStatus> > m_gridStatus;
    std::vector<Ship> m_ships;

    static int const ACHAR = 65;
};


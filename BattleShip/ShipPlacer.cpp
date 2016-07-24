#include "ShipPlacer.h"
#include "GridAbstract.h"
#include "Ship.h"

#include <random>


ShipPlacer::ShipPlacer(GridAbstract& grid, Ship& ship) :
    m_grid(grid),
    m_ship(ship)
{
    placeShip();
}

Coord ShipPlacer::emptySpot()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, m_grid.dimension());
    int randRow = distribution(generator);
    int randCol = distribution(generator);
    Coord spot = std::make_pair(randRow, randCol);
    GridAbstract::GridStatus status = m_grid.status(spot.first, spot.second);
    if (status == GridAbstract::GridStatus::WATER)
        return spot;
    else
        return emptySpot();
}

bool ShipPlacer::placeShipAtSpot(Coord const& spot)
{
    bool shipPlaced = false;

    return shipPlaced;
}

bool ShipPlacer::placeShip()
{
    bool shipPlaced = false;

    // find an empty spot on the grid
    Coord spot = emptySpot();
    // find space for the ship
    shipPlaced = placeShipAtSpot(spot);
    return shipPlaced;
}


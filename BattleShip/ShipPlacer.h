#pragma once

#include "Ship.h"

class GridAbstract;

class ShipPlacer
{
public:
    ShipPlacer(GridAbstract& grid, Ship& ship);

private:
    Coord emptySpot();

    bool placeShipAtSpot(Coord const& spot);

    bool placeShip();

    GridAbstract& m_grid;
    Ship& m_ship;
};

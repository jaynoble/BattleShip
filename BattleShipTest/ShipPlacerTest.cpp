#include <gtest\gtest.h>
#include "ShipPlacer.h"
#include "GridAbstract.h"
#include "Ship.h"


bool shipLocationIsValid(std::vector<Coord> location)
{
    bool locationIsValid = false;

    // location coords are in the grid
    // location coords are in a line

    return locationIsValid;
}

TEST(TestShipPlacer, shouldPlaceAShip)
{
    int const GRID_DIMENSION = 5;
    int const SHIP_SIZE = 3;

    GridAbstract grid(GRID_DIMENSION);
    Ship ship(SHIP_SIZE);

    ShipPlacer(grid, ship);

    ship.location();
}

TEST(TestShipPlacer, shouldThrowWhenNoShipPlaced)
{
    // make the ship too big or fill the grid
}
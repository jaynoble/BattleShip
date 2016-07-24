#pragma once

#include <vector>
// use alias so don't have to type so much  TODO: move this somewhere more global
#include <utility>
using Coord = std::pair<int, int>;


class Ship
{
public:
    Ship(int size);
    Ship(Coord coord1, Coord coord2);

    int size();

    std::vector<Coord> location();

    enum class SHIPTYPE { CARRIER, BATTLESHIP, SUBMARINE };
private:
    Coord m_coord1;
    Coord m_coord2;
    int m_size;
    std::vector<Coord> m_location;
};

class Carrier : public Ship
{
public:
    Carrier();
    Carrier(Coord coord1, Coord coord2);

    int size();

private:
    static int const SHIP_SIZE = 5;
    int m_health;
};

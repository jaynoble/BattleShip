#include "Ship.h"

Ship::Ship(int size) :
    m_size(size)
{
    Coord badCoord = std::make_pair(-1, -1);
    for (int i = 0; i < m_size; ++i)
        m_location.push_back(badCoord);
}

Ship::Ship(Coord coord1, Coord coord2) :
    m_coord1(coord1),
    m_coord2(coord2)
{

}

int Ship::size()
{
    return m_size;
}

std::vector<Coord> Ship::location()
{
    return m_location;
}
    

Carrier::Carrier() :
    Ship(SHIP_SIZE)
{
    m_health = SHIP_SIZE;
}

Carrier::Carrier(Coord coord1, Coord coord2) :
    Ship(coord1, coord2)
{
    m_health = SHIP_SIZE;
}

int Carrier::size()
{
    return SHIP_SIZE;
}


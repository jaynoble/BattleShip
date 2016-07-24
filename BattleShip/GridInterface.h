#pragma once
#include <string>

class GridInterface
{
public:
    
    // virtual std::string gridString() = 0;
    virtual std::string gridRowString(int row) = 0;
};
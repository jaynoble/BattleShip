#pragma once
#include "GridAbstract.h"
#include<vector>

class CPUGrid : public GridAbstract
{
public:
    CPUGrid(int gridDimension);
    virtual ~CPUGrid();

    std::string gridRowString(int row); // override

private:
    int m_dimension;
};


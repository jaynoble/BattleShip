#include <gtest\gtest.h>
#include "CPUGrid.h"
#include "Ship.h"


TEST (TestCPUGrid, shouldDisplayInitialEmptyFormattedGrid)
{
    int const cpuGridDimension = 5;
    static std::string const cpuGridDisplayExpected =
        "    1  2  3  4  5  \n"
        "   --------------- \n"
        "A | -  -  -  -  - |\n"
        "B | -  -  -  -  - |\n"
        "C | -  -  -  -  - |\n"
        "D | -  -  -  -  - |\n"
        "E | -  -  -  -  - |\n"
        "   --------------- \n";
    // create CPUGrid
    CPUGrid cpuGrid(cpuGridDimension);
    // compare to cpuGridDisplayExpected
    ASSERT_EQ(cpuGridDisplayExpected, cpuGrid.gridString());
}

TEST(TestCPUGrid, shouldFitAllShips)
{
    int const cpuGridDimension = 5;

    // create CPUGrid
    CPUGrid cpuGrid(cpuGridDimension);
    // place ships
    int totalShipSpacesExpected = 0;
    for (Ship ship : cpuGrid.ships())
        totalShipSpacesExpected += ship.size();
    int totalShipSpacesFound = 0;
    for (int row = 0; row < cpuGridDimension; ++row)
    {
        for (int col = 0; col < cpuGridDimension; ++col)
        {
            GridAbstract::GridStatus status = cpuGrid.status(row, col);
            if (status == GridAbstract::GridStatus::SHIP)
                ++totalShipSpacesFound;
        }
    }
    // for each location
    //  add ship space
    ASSERT_EQ(totalShipSpacesExpected, totalShipSpacesFound);
}

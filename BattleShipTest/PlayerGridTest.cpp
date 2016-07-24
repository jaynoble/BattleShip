#include <gtest\gtest.h>
#include "PlayerGrid.h"


TEST(TestPlayerGrid, shouldDisplayInitialFormattedGridWithShips)
{
    int const playerGridDimension = 5;

    // just test that all ships have been placed by checking 5 ships have SHIP on grid
    static std::string const playerGridDisplayExpected =
        "    1  2  3  4  5  \n"
        "   --------------- \n"
        "A |/-\\ -  -  -  - |\n"
        "B ||-| -  -  -  - |\n"
        "C ||-| -  -  -  - |\n"
        "D |\\-/<-  -  -> - |\n"
        "E | -  -  - <-  -> |\n"
        "   --------------- \n";

/*        "    1 2 3 4 5 \n"
        "   --------------- \n"
        "A |/-\ -  -  -  - |\n"
        "B ||-| -  -  -  - |\n"
        "C ||-| -  -  -  - |\n"
        "D |\-/<-  -  -  ->|\n"
        "E | -  -  - <-  ->|\n"
        "   --------------- \n";
*/
    // create PlayerGrid
    PlayerGrid playerGrid(playerGridDimension);
    //playerGrid.placeShips(numPlayerShips);
    // compare to playerGridDisplayExpected
    /*
    for each ship
        expectedShipSpaces += ship.size();
    for each space in playerGrid
    {
        if (foundShipSpace)
            shipSpacesInGrid++;
    }
    ASSERT_EQ(expectedShipSpaces, shipSpacesInGrid);
    */
    //size_t numShips = playerGrid.ships().size();
    ASSERT_EQ(playerGridDisplayExpected, playerGrid.gridString());
}


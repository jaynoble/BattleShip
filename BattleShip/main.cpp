#include <stdlib.h>
#include <iostream>
#include <string>

#include "CPUGrid.h"
#include "PlayerGrid.h"

void displayHelp()
{
    std::string helpMessage = "";
    static std::string const rules = "Battleship Rules:\n"
        "Each side has its ships randomly placed on their grid.  Player fires a shot, giving coordinates\n"
        "in the form: LETTER NUMBER.  LETTER corresponds to a row on the opponents grid; NUMBER is the column.\n"
        "After the player's turn, the computer returns fire.  The last side with ships still afloat is the winner.\n"
        "Good luck!\n";
    std::cout << helpMessage + rules;
}

enum class USERCHOICE {FIRE, HELP, EXIT, BAD};

bool validChoice(USERCHOICE choice)
{
    return choice != USERCHOICE::BAD;
}

USERCHOICE displayChoice()
{
    std::cout << "1. Fire\n"
        "2. Help\n"
        "3. Exit\n"
        "Enter Choice: ";
    USERCHOICE choice = USERCHOICE::BAD;
    int choiceNum;
    std::cin >> choiceNum;
    choice = static_cast<USERCHOICE>(choiceNum);    // TODO: re-evaluate this approach since enum class doesn't necessarily resolve to ints
    while (!validChoice(choice))
    {
        std::cout << "Not a valid choice.\n\n";
        displayChoice();
    }

    _ASSERT(USERCHOICE::FIRE <= choice && choice <= USERCHOICE::EXIT);
    return choice;
}

// initialize game with cpu and player grids
bool initialize(int const& gridDimension, int const& numShips, CPUGrid* cpuGrid, PlayerGrid* playerGrid)
{
    bool result = true;
    try
    {
        cpuGrid = new CPUGrid(gridDimension);
    }
    catch (std::bad_alloc)
    {
        result = false;
    }

    return result;
}

int main()
{
    bool result = true;

    displayHelp();

    int const gridDimension = 5;
    int const numShips = 3;
    CPUGrid* cpuGrid = nullptr;
    PlayerGrid* playerGrid = nullptr;

    result = initialize(gridDimension, numShips, cpuGrid, playerGrid);

    USERCHOICE choice = USERCHOICE::BAD;
    while (choice != USERCHOICE::EXIT)
    {
        choice = displayChoice();
    }

    return result ? 0 : 1;
}


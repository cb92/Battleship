#include "Game.hpp"
#include "Player.hpp"
#include "utils.hpp"
#include <iostream>

int main()
{
	unsigned seed=time(0);
	srand(seed);

	bool continueGame=true;

	while (continueGame)
	{
		continueGame = printMenu();
	}
	return 0;

}
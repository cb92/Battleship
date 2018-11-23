#include "Game.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


// function to play game
bool Game::playGame()
{
	int firstPlayer, currentPlayer, toPlay;
	Board * bptr;
	Player * pptr;

	startGame();

	std::cout<<"Which player will make the first move (enter 1 or 2)?\n";
	firstPlayer=getInt(1,2);


	// hold pointers for current player/board objects
	if (firstPlayer==1)
	{
		pptr = &p1; 
		bptr = &p2Board;
	}
	else {
		pptr = &p2;
		bptr = &p1Board;
	}

	while(gameCondition()==UNFINISHED)
	{
		if ((*pptr).isPlayerAutomatic())
		{
			getNextMoveAuto(*(bptr));
		}
		else
		{
			printGameState(*(pptr));
			getNextMove(*(bptr));
			printGameState(*(pptr));
		}

		// switch pointers at the end of each turn
		if ((*pptr).getPlayerNum()==1)
		{
			if (!p1.isPlayerAutomatic() && !p2.isPlayerAutomatic()) 
			{
				switchPlayers(p1.getName(), p2.getName());
			}
			pptr = &p2; 
			bptr = &p1Board;
		}
		else {
			if (!p1.isPlayerAutomatic() && !p2.isPlayerAutomatic())
			{
				switchPlayers(p2.getName(), p1.getName());
			}
			pptr = &p1;
			bptr = &p2Board;
		}
	}

	if (gameCondition()==P1_WIN)
		std::cout<<p1.getName()<<" wins!!!"<<std::endl;
	else 
		std::cout<<p2.getName()<<" wins!!!"<<std::endl;

	std::cout<<"I hope you enjoyed the Battleship game. Bye!\n\n";
	return true;

}

// function to perform necessary setup before game is played
void Game::startGame()
{
	std::string nameTemp;
	int autoTemp;

	//set player numbers
	p1.setPlayerNum(1);
	p2.setPlayerNum(2);

	//get player names
	std::cout<<"What is player 1's name (<=32 chars)?\n";
	p1.setName(getString(32));
	std::cout<<"Welcome, "<<p1.getName()<<"!"<<std::endl;

	std::cout<<"What is player 2's name (<=32 chars)?\n";
	p2.setName(getString(32));
	std::cout<<"Welcome, "<<p2.getName()<<"!"<<std::endl;

	//get automatic statuses
	std::cout<<"What type of player is "<<p1.getName()
					<<"? (enter 0 for non-auto, 1 for auto)\n";
	p1.setAuto(getInt(0,1));

	std::cout<<"What type of player is "<<p2.getName()
					<<"? (enter 0 for non-auto, 1 for auto)\n";
	p2.setAuto(getInt(0,1));


	//initialize both boards, according to whether the players are automatic
	if (p1.isPlayerAutomatic())
		initializeBoardAuto(p1Board, false);
	else
	{
		std::cout<<p1.getName()<<", how would you like your board to be set?"
						<<" (enter 0 for non-auto, 1 for auto)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			initializeBoardAuto(p1Board, true);
		else initializeBoard(p1Board);

	}

	// if both players are non-auto, clear screen appropriately between fills
	if (!p2.isPlayerAutomatic() && !p1.isPlayerAutomatic())
	{
		switchPlayers(p1.getName(), p2.getName());
	}

	if (p2.isPlayerAutomatic())
		initializeBoardAuto(p2Board, false);
	else
	{
		
		std::cout<<p2.getName()<<", how would you like your board to be set?"
						<<" (enter 0 for non-auto, 1 for auto)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			initializeBoardAuto(p2Board, true);
		else initializeBoard(p2Board);

	}
	if (!p2.isPlayerAutomatic() && !p1.isPlayerAutomatic())
	{
		std::cout<<std::string(100,'\n');
	}

	return;
}

// prints game state, with player's own board exposed and opponent's board
// mostly obscured, save for moves player has made
void Game::printGameState(Player p)
{
	std::cout<<p.getName()<<"'s GAME STATE:\n\n";
	if (p.getPlayerNum()==1)
	{
		std::cout<<"YOUR BOARD: \n";
		p1Board.printPublicBoard();
		std::cout<<"YOUR OPPONENT'S BOARD: \n";
		p2Board.printPrivateBoard();
		std::cout<<std::endl<<std::endl;
	}
	else
	{
		std::cout<<"YOUR BOARD: \n";
		p2Board.printPublicBoard();
		std::cout<<"YOUR OPPONENT'S BOARD: \n";
		p1Board.printPrivateBoard();
		std::cout<<std::endl<<std::endl;
	}


	return;
}

// initializes board based on user input 
void Game::initializeBoard(Board &b)
{
	int xEntry, yEntry, horizEntry, attemptCount;
	std::string entryTemp;
	for (int i=0; i<NUM_SHIPS; i++)
	{
		attemptCount=0;
		do // check for valid placement of each ship
		{
			b.printPublicBoard();
			if (attemptCount>0) 
				std::cout<<"INVALID ENTRY for that ship! Please try again. \n";

			std::cout<<"Please enter location [Letter][Number] for the "<<
						"top/left of your "<<SHIP_NAMES[i]<<" which is length "
						<<SHIP_LENGTHS[i]<<": \n";
			entryTemp=getSquare();		
			xEntry=static_cast<int>(entryTemp[0]);
			yEntry=static_cast<int>(entryTemp[1]);

			std::cout<<"Please enter 0 if the ship is oriented vertically, "
						<<"1 if it is oriented horizontally:\n";
			horizEntry=getInt(0,1);

			attemptCount++;
		} while (!b.placeShip(i, xEntry-LETTER_CHAR_OFFSET, 
						yEntry-NUMBER_CHAR_OFFSET, horizEntry));

	}

	std::cout<<"Your starting board: \n";
	b.printPublicBoard();

	return;
}


// initializes a board with random placement of ships on a board 
void Game::initializeBoardAuto(Board &b, bool print)
{
	int xEntry, yEntry, horizEntry;

	for (int i=0; i<NUM_SHIPS; i++)
	{
		do // randomize position placements and place ships if possible
		{
			xEntry=rand()%10;
			yEntry=rand()%10;
			horizEntry=rand()%2;
		} while (!b.placeShip(i, xEntry, yEntry, horizEntry));

	}

	if (print)
	{
		std::cout<<"Your starting board: \n";
		b.printPublicBoard();
	}


	return;
}

// returns enum determining state of game
state Game::gameCondition()
{
	if (p1Board.getNumHits()==TOTAL_SHIP_SPACES)
		return P2_WIN;

	else if (p2Board.getNumHits()==TOTAL_SHIP_SPACES)
		return P1_WIN;

	else
		return UNFINISHED;
}


// function to prompt a player to actively choose which move to make 
void Game::getNextMove(Board &b)
{
	int attemptCount=0;
	int xEntry, yEntry;
	bool goodMove=false;
	std::string entryTemp;

	while (!goodMove)
	{
		if (attemptCount>0) 
			std::cout<<"That move has already been attempted. Try again. \n";

		std::cout<<"Please enter location [Letter][Number] of desired move:\n";
		entryTemp=getSquare();		
		xEntry=static_cast<int>(entryTemp[0]);
		yEntry=static_cast<int>(entryTemp[1]);

		if (b.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, 
						yEntry-NUMBER_CHAR_OFFSET)!=isHIT
			&& b.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, 
							yEntry-NUMBER_CHAR_OFFSET)!=isMISS)
		{
			b.recordHit(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET);
			goodMove=true;
		}
		attemptCount++;
	} 

	return;
}


// function to make a random move
void Game::getNextMoveAuto(Board &b)
{
	bool goodMove=false;
	int xEntry, yEntry;

	while (!goodMove)
	{
		// randomly choose next move
		xEntry=rand()%10;
		yEntry=rand()%10;

		if (b.getSpaceValue(xEntry, yEntry)!=isHIT
			&& b.getSpaceValue(xEntry, yEntry)!=isMISS)
		{
			b.recordHit(xEntry, yEntry);
			goodMove=true;
		}
	} 
	return;
}

// input validation for square
std::string Game::getSquare()
{
	std::string retString;
	std::getline(std::cin, retString);
	bool isGoodInput=false;

	while (!isGoodInput)
	{
		// check for two character entries of letter/number
		if (retString.length()==2 && (retString[0]>=65 && retString[0]<=74) 
						&& (retString[1]>=48 && retString[1]<=57))
			isGoodInput=true;
		else
		{
			std::cout<<"Bad input! Please enter location [Letter][Number] of "
						<<"your desired move, with capital letters only:\n";
			std::getline(std::cin, retString);
		}
	}

	return retString;
}


// switchPlayers is a function that controls the screen between turns, 
// ensuring that the player whose turn it is can control what is visible
// on the screen in case someone else is peeking
void Game::switchPlayers(std::string playerFrom, std::string playerTo)
{
	std::cout<<playerFrom<<", press ENTER to finish your turn!";
	std::cin.get();
	std::cout<<std::flush;
	std::cout<<std::string(100,'\n');
	std::cout<<playerTo<<", press ENTER to start your turn!";
	std::cin.get();
	std::cout<<std::flush;
	std::cout<<std::string(100,'\n');	

}
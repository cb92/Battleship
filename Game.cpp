#include "Game.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>



bool Game::playGame()
{
	int firstPlayer, currentPlayer, toPlay;
	Board * bptr;
	Player * pptr;

	startGame();

	std::cout<<"Which player will make the first move (enter 1 or 2)?\n";
	firstPlayer=getInt(1,2);

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

		if ((*pptr).getPlayerNum()==1)
		{
			pptr = &p2; 
			bptr = &p1Board;
		}
		else {
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


void Game::startGame()
{
	std::string nameTemp;
	int autoTemp;

	//set player numbers
	p1.setPlayerNum(1);
	p2.setPlayerNum(2);

	//get player names
	std::cout<<"What is player 1's name (please enter a string of <=32 chars)?\n";
	p1.setName(getString(32));
	std::cout<<"Welcome, "<<p1.getName()<<"!"<<std::endl;

	std::cout<<"What is player 2's name (please enter a string of <=32 chars)?\n";
	p2.setName(getString(32));
	std::cout<<"Welcome, "<<p2.getName()<<"!"<<std::endl;

	//get automatic statuses
	std::cout<<"What type of player is "<<p1.getName()<<"? (enter 0 for non-auto, 1 for auto)\n";
	p1.setAuto(getInt(0,1));

	std::cout<<"What type of player is "<<p2.getName()<<"? (enter 0 for non-auto, 1 for auto)\n";
	p2.setAuto(getInt(0,1));


	//initialize both boards, according to whether the players are automatic
	if (p1.isPlayerAutomatic())
		initializeBoardAuto(p1Board);
	else
	{
		std::cout<<p1.getName()<<", how would you like your board to be set? (enter 0 for non-auto, 1 for auto)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			initializeBoardAuto(p1Board);
		else initializeBoard(p1Board);

	}

	if (p2.isPlayerAutomatic())
		initializeBoardAuto(p2Board, 1);
	else
	{
		std::cout<<p2.getName()<<", how would you like your board to be set? (enter 0 for non-auto, 1 for auto)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			initializeBoardAuto(p2Board);
		else initializeBoard(p2Board);

	}

	return;
}

void Game::printGameState(Player p)
{
	std::cout<<"PLAYER "<<p.getPlayerNum()<<" GAME STATE:\n\n";
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

void Game::initializeBoard(Board &b)
{
	int xEntry, yEntry, horizEntry, attemptCount;
	std::string entryTemp;
	for (int i=0; i<NUM_SHIPS; i++)
	{
		attemptCount=0;
		do
		{
			b.printPublicBoard();
			if (attemptCount>0) 
				std::cout<<"INVALID ENTRY for that ship! Please try again. \n";

			std::cout<<"Please enter location [Letter][Number] for the top/left of your "
						<<SHIP_NAMES[i]<<" which is length "
						<<SHIP_LENGTHS[i]<<": \n";
			entryTemp=getSquare();		
			xEntry=static_cast<int>(entryTemp[0]);
			yEntry=static_cast<int>(entryTemp[1]);

			std::cout<<"Please enter 0 if the ship is oriented vertically, 1 if it is oriented horizontally:\n";
			horizEntry=getInt(0,1);

			attemptCount++;
		} while (!b.placeShip(i, xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET, horizEntry));

	}

	std::cout<<"Your starting board: \n";
	b.printPublicBoard();

	return;
}



void Game::initializeBoardAuto(Board &b, int seedOffset)
{
	int xEntry, yEntry, horizEntry;
	unsigned seed=time(0)+seedOffset;
	srand(seed);

	for (int i=0; i<NUM_SHIPS; i++)
	{
		do
		{
			xEntry=rand()%10;
			yEntry=rand()%10;
			horizEntry=rand()%2;
		} while (!b.placeShip(i, xEntry, yEntry, horizEntry));

	}

	std::cout<<"Your starting board: \n";
	b.printPublicBoard();


	return;
}


state Game::gameCondition()
{
	if (p1Board.getNumHits()==TOTAL_SHIP_SPACES)
		return P2_WIN;

	else if (p2Board.getNumHits()==TOTAL_SHIP_SPACES)
		return P1_WIN;

	else
		return UNFINISHED;



}


void Game::getNextMove(Board &b)
{
	int attemptCount=0;
	int xEntry, yEntry;
	bool goodMove=false;
	std::string entryTemp;

	while (!goodMove)
	{
		if (attemptCount>0) 
			std::cout<<"That move has already been attempted. Please try again. \n";

		std::cout<<"Please enter location [Letter][Number] of your desired move:\n";
		entryTemp=getSquare();		
		xEntry=static_cast<int>(entryTemp[0]);
		yEntry=static_cast<int>(entryTemp[1]);

		if (b.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isHIT
			&& b.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isMISS)
		{
			b.recordHit(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET);
			goodMove=true;
		}
		attemptCount++;
	} 

	return;
}


void Game::getNextMoveAuto(Board &b)
{
	bool goodMove=false;
	int xEntry, yEntry;

	while (!goodMove)
	{
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

std::string Game::getSquare()
{
	std::string retString;
	std::getline(std::cin, retString);
	bool isGoodInput=false;

	while (!isGoodInput)
	{
		if (retString.length()==2 && (retString[0]>=65 && retString[0]<=74) && (retString[1]>=48 && retString[1]<=57))
			isGoodInput=true;
		else
		{
			std::cout<<"Bad input! Please enter location [Letter][Number] of your desired move, with capital letters only:\n";
			std::getline(std::cin, retString);
		}
	}

	return retString;
}
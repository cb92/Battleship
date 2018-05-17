#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool playGame(int firstPlayer)
{
	startGame();

	return true;

}


void Game::startGame()
{
	//get information about players
	p1.setPlayerNum(1);
	p2.setPlayerNum(2);

	//initialize both boards, according to whether the players are automatic
	initializeBoardAuto(p1Board);
	initializeBoardAuto(p2Board);
	
	getNextMove(p1Board);
	p1Board.printPublicBoard();

	getNextMove(p2Board);
	p2Board.printPublicBoard();

	getNextMove(p1Board);
	p1Board.printPublicBoard();

	getNextMoveAuto(p2Board);
	p2Board.printPublicBoard();

	return;
}

void Game::initializeBoard(Board &b)
{
	int xEntry, yEntry, horizEntry, attemptCount;
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
			xEntry=std::cin.get();
			yEntry=std::cin.get();	
			std::cin.ignore();

			std::cout<<"Please enter 0 if the ship is oriented vertically, 1 if it is oriented horizontally:\n";
			horizEntry=std::cin.get()-NUMBER_CHAR_OFFSET;
			std::cin.ignore();

			attemptCount++;
		} while (!b.placeShip(i, xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET, horizEntry));

	}

	std::cout<<"Your starting board: \n";
	b.printPublicBoard();

	return;
}



void Game::initializeBoardAuto(Board &b)
{
	int xEntry, yEntry, horizEntry;
	unsigned seed=time(0);
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

	while (!goodMove)
	{
		if (attemptCount>0) 
			std::cout<<"That move has already been attempted. Please try again. \n";

		std::cout<<"Please enter location [Letter][Number] of your desired move:\n";
		xEntry=std::cin.get();
		yEntry=std::cin.get();	
		std::cin.ignore();

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

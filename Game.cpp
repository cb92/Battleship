#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool playGame(int firstPlayer)
{
	//

}


void Game::startGame()
{
	//get information about players
	


	//initialize both boards, according to whether the players are automatic
	if (p1.isPlayerAutomatic()) 
		initializeBoardAuto(p1Board);
	else 
		initializeBoard(p1Board);

	if (p2.isPlayerAutomatic()) 
		initializeBoardAuto(p2Board);
	else 
		initializeBoard(p2Board);

	return;
}

void Game::initializeBoard(Board b)
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



void Game::initializeBoardAuto(Board b)
{
	int xEntry, yEntry, horizEntry;
	unsigned seed=time(0);
	srand(seed);

	for (int i=0; i<NUM_SHIPS; i++)
	{
		do
		{
			xEntry=rand()%10;
			std::cout<<xEntry<<std::endl;
			yEntry=rand()%10;
			std::cout<<yEntry<<std::endl;
			horizEntry=rand()%2;
			std::cout<<horizEntry<<std::endl<<"------\n";
		} while (!b.placeShip(i, xEntry, yEntry, horizEntry));

		b.printPublicBoard();

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


bool makeNextMove(Board b, int x, int y)
{
	if (b.getSpaceValue(x, y)!=isHIT && b.getSpaceValue(x, y)!=isMISS)
	{
		b.recordHit(x, y);
		return true;
	}
	else 
		return false;
}


/*
bool playGame()
{
	
	int attemptCount=0;
	bool goodMove=false;

	while (!goodMove)
	{
		if (attemptCount>0) 
			std::cout<<"That move has already been attempted. Please try again. \n";

		std::cout<<"Please enter location [Letter][Number] of your desired move:\n";
		xEntry=std::cin.get();
		yEntry=std::cin.get();	
		std::cin.ignore();

		if (p.getNumber()==1 
			&& p2board.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isHIT
			&& p2board.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isMISS)
		{
			p2Board.recordHit(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET);
			goodMove=true;
		}

		if (p.getNumber()==2
			&& p1board.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isHIT
			&& p1board.getSpaceValue(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET)!=isMISS)
		{
			p1Board.recordHit(xEntry-LETTER_CHAR_OFFSET, yEntry-NUMBER_CHAR_OFFSET);
			goodMove=true;
		}

		attemptCount++;
	} 




}

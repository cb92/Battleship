#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>



bool Game::playGame()
{
	int firstPlayer, currentPlayer;
	startGame();

	std::cout<<"Which player will make the first move (enter 1 or 2)?\n";
	std::cin>>firstPlayer;
	std::cin.ignore();
	currentPlayer=firstPlayer;

	while(gameCondition()==UNFINISHED)
	{

		if (currentPlayer==1)
		{
			if (p1.isPlayerAutomatic())
				getNextMoveAuto(p2Board);
			else
			{
				printGameState(p1);
				getNextMove(p2Board);
				printGameState(p1);
			}
		}
		else
		{
			if (p2.isPlayerAutomatic())
				getNextMoveAuto(p1Board);
			else
			{
				printGameState(p2);
				getNextMove(p1Board);
				printGameState(p2);
			}

		}
		//switch current player
		if (currentPlayer==1)
			currentPlayer=2;
		else currentPlayer=1;
	}

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
	std::cout<<"What is player 1's name?\n";
	std::cin>>nameTemp;
	std::cin.ignore();
	p1.setName(nameTemp);
	std::cout<<"Welcome, "<<p1.getName()<<"!"<<std::endl;

	std::cout<<"What is player 2's name?\n";
	std::cin>>nameTemp;
	std::cin.ignore();
	p2.setName(nameTemp);
	std::cout<<"Welcome, "<<p2.getName()<<"!"<<std::endl;

	//get automatic statuses
	std::cout<<"What type of player is player 1? (enter 0 for non-auto, 1 for auto)\n";
	std::cin>>autoTemp;
	std::cin.ignore();
	p1.setAuto(autoTemp);

	std::cout<<"What type of player is player 2? (enter 0 for non-auto, 1 for auto)\n";
	std::cin>>autoTemp;
	std::cin.ignore();
	p2.setAuto(autoTemp);


	//initialize both boards, according to whether the players are automatic
	if (p1.isPlayerAutomatic())
		initializeBoardAuto(p1Board);
	else initializeBoard(p1Board);

	if (p2.isPlayerAutomatic())
		initializeBoardAuto(p2Board, 1);
	else initializeBoard(p2Board);

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

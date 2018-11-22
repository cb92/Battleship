#include "Board.hpp"
#include <iostream>

// default board constructor builds a 2D array filled with water, 
// and fills a vector with the standard ship objects
Board::Board()
{
	for (int i=0; i<BOARD_DIM; i++)
		for (int j=0; j<BOARD_DIM; j++)
			gameBoard[i][j]=isWATER;

	for (int i=0; i<NUM_SHIPS; i++)
		shipVec.push_back(Ship(SHIP_LENGTHS[i], SHIP_NAMES[i]));
}

// copy constructor - copies old board square by square
Board::Board(const Board &oldBoard)
{
	for (int i=0; i<BOARD_DIM; i++)
		for (int j=0; j<BOARD_DIM; j++)
			gameBoard[i][j]=oldBoard.gameBoard[i][j];
	shipVec = oldBoard.shipVec;
}

// copy assignment operator - copies old board square by square
Board& Board::operator=(const Board &right)
{
	if (this!=&right)
	{
		for (int i=0; i<BOARD_DIM; i++)
			for (int j=0; j<BOARD_DIM; j++)
				gameBoard[i][j]=right.gameBoard[i][j];
		shipVec = right.shipVec;
	}

	return *this;

}

// return the number of hits on the board at the moment
int Board::getNumHits()
{
	int count=0;

	for (int i=0; i<BOARD_DIM; i++)
		for (int j=0; j<BOARD_DIM; j++)
			if (gameBoard[i][j]==isHIT)
				count++;

	return count;
}

// method to print the private version of the board 
// (player can only see hits/misses) 
void Board::printPrivateBoard()
{
	std::cout<<"  A B C D E F G H I J\n";
	for (int i=0; i<BOARD_DIM; i++)
	{
		std::cout<<i<<" ";
		for (int j=0; j<BOARD_DIM; j++)
		{
			if (gameBoard[i][j]==isHIT || gameBoard[i][j]==isMISS)
				std::cout<<gameBoard[i][j]<<" ";
			else // obfuscate non-hit/miss entries
				std::cout<<isUNKNOWN<<" ";
		}	
		std::cout<<std::endl;
	}
}

// method to print the board that the player can see completely 
// (usually, the player's own board)
void Board::printPublicBoard()
{
	std::cout<<"  A B C D E F G H I J\n";
	for (int i=0; i<BOARD_DIM; i++)
	{
		std::cout<<i<<" ";
		for (int j=0; j<BOARD_DIM; j++)
		{
			std::cout<<gameBoard[i][j]<<" ";
		}	
		std::cout<<std::endl;
	}

}

//return the value of a space
char Board::getSpaceValue(int x, int y)
{
	return gameBoard[y][x];
}

// record a hit on the board by attempting to record a hit on every ship
// if a ship is hit, change board position to hit and return true
// if no ship is hit, change board position to miss and return false
bool Board::recordHit(int x, int y)
{
	for (int i=0; i<NUM_SHIPS; i++)
	{
		if (shipVec[i].recordHit(x, y))
		{
			gameBoard[y][x]=isHIT; //record the hit on the board
			//tell the user that they sunk a ship
			if (shipVec[i].isShipSunk()) 
				std::cout<<"You sunk the "<<shipVec[i].getName()<<"!\n";
			return true;
		}
	}
	gameBoard[y][x]=isMISS;
	return false;
}

// function to place ship on board
bool Board::placeShip(int shipNum, int x, int y, bool isHorizontal)
{
	//if x or y is out of bounds, return false
	if (x>=BOARD_DIM || y>=BOARD_DIM)
		return false;

	//if ship has already been placed, return false
	if (shipVec[shipNum].getX()>=0 && shipVec[shipNum].getY()>=0)
		return false;

	//loop through the positions required for the ship
	for (int i=0; i<shipVec[shipNum].getSize(); i++)
	{
		//if any of the desired spaces are filled, return false
		if ((isHorizontal && gameBoard[y][x+i]!=isWATER) || 
							(!isHorizontal && gameBoard[y+i][x]!=isWATER))
			return false;
		//if any of the desired spaces are out of bounds, return false
		if ((isHorizontal && (x+i)>=BOARD_DIM) || 
							(!isHorizontal && (y+i)>=BOARD_DIM))
			return false;
	}

	//if the for loop finishes, and all the positions are empty, 
	//1. place the Ship in the desired position on the board
	for (int i=0; i<shipVec[shipNum].getSize(); i++)
	{
		if (isHorizontal)
			gameBoard[y][x+i]=isSAFESHIP;
		else 
			gameBoard[y+i][x]=isSAFESHIP;
	}

	//2. set the x/y parameters for the Ship object 
	shipVec[shipNum].setPosition(x, y, isHorizontal);

	//... and return true
	return true;
}

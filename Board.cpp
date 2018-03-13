



#include "Board.hpp"
#include <iostream>

Board::Board()
{
	for (int i=0; i<BOARD_DIM; i++)
		for (int j=0; j<BOARD_DIM; j++)
			gameBoard[i][j]=isWATER;

	for (int i=0; i<NUM_SHIPS, i++)
		shipVec[i]=Ship(SHIP_LENGTHS[i], false, SHIP_NAMES[i])
}

int Board::getNumHits()
{
	int count=0;

	for (int i=0; i<BOARD_DIM; i++)
		for (int j=0; j<BOARD_DIM; j++)
			if (gameBoard[i][j]==isHIT)
				count++;

	return count;
}

//method to print the board that the player cannot see all of 
void Board::printPrivateBoard()
{
	for (int i=0; i<BOARD_DIM; i++)
	{
		for (int j=0; j<BOARD_DIM; j++)
		{
			if (gameBoard[i][j]==isHIT || gameBoard[i][j]==isMISS)
				std::cout<<gameBoard[i][j]<<" ";
			else 
				std::cout<<isUNKNOWN<<" ";
		}	
		std::cout<<std::endl;
	}
}

//method to print the board that the player can see all of
void Board::printPublicBoard()
{
	for (int i=0; i<BOARD_DIM; i++)
	{
		for (int j=0; j<BOARD_DIM; j++)
		{
			std::cout<<gameBoard[i][j]<<" ";
		}	
		std::cout<<std::endl;
	}

}
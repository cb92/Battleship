/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: header file for the Board class
******************************************************************************/


#include "Ship.hpp"
#include "Constants.hpp"
#include <vector>

#ifndef BOARD_H
#define BOARD_H

class Board
{
	private:
		char gameBoard[BOARD_DIM][BOARD_DIM];
		std::vector<Ship> shipVec;

	public:
		Board();
		int getNumHits();
		void printPrivateBoard();
		void printPublicBoard();
		bool recordHit(int x, int y);
		bool placeShip(Ship* s, int x, int y);

};

#endif





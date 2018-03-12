/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: header file for the Ship class
******************************************************************************/


#ifndef SHIP_H
#define SHIP_H

class Ship
{
	private: 
		char* shipSquares;
		int shipSize;
		bool isSunk;

	public:	
		Ship(int size);//constructor
		Ship(const Ship &oldShip); //copy constructor
		~Ship(); //destructor
		int getSize();
		bool isShipSunk();
		void printShip();
		void recordHit(int hitLoc);

};

#endif;
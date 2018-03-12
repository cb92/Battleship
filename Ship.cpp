/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: definition of Ship functions
******************************************************************************/

#include "Ship.hpp"
#include <iostream>

using std::cout;

Ship::Ship(int size)
{
	shipSize=size;
	shipSquares=new char[shipSize];
	for (int i=0; i<(*shipSquares).length(); i++)
		shipSquares[i]='_'; //initialize all ship squares to '_', indicating no hit
	isSunk=false;
}

Ship::Ship(cont Ship &oldShip)
{
	shipSize=oldShip.getSize();
	shipSquares=new char[shipSize]
	for (int i=0; i<(*shipSquares).length(); i++)
		shipSquares[i]=oldShip.shipSquares[i]; //initialize all ship squares to '_', indicating no hit
	isSunk=false;
}

Ship::~Ship
{

	if (shipSize > 0)
		delete [] shipSquares;
}


int Ship::getSize()
{
	return shipSize;
}

bool Ship::isShipSunk()
{
	return isSunk;
}

void printShip()
{
	for (int i=0; i<(*shipSquares).length(); i++)
		cout<<shipSquares[i]<<" ";
	return;
}
void recordHit(int hitLoc)
{
	if (hitLoc>=(*shipSquares).length() || hitLoc<0)
		return;
	else shipSquares[hitLoc]='X';

	//determine whether the ship has been sunk
	isSunk=true;
	for (int i=0; i<(*shipSquares).length(); i++)
		if (shipSquares[i]=='_')
			isSunk=false;

	return;


}

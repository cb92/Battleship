/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: definition of Ship functions
******************************************************************************/

#include "Ship.hpp"
#include "Constants.hpp"
#include <iostream>

using std::cout;

// one constructor initializes a ship if only size and name are spcified
Ship::Ship(int size, std::string n)
{
	shipSize=size;
	name = n;
	shipSquares=new char[shipSize];
	for (int i=0; i<shipSize; i++)
		shipSquares[i]=isSAFESHIP; //initialize all ship squares to '_', indicating no hit
	xpos=-1; //indicates that the ship has not been placed yet
	ypos=-1; //indicates that the ship has not been placed yet
	isSunk=false; //since ship is new, it is not yet sunk
	isHorizontal=true;
}

// ship can also be placed when it is initialized
Ship::Ship(int size, std::string n, int x, int y, bool s, bool h)
{
	shipSize=size;
	name = n;
	shipSquares=new char[shipSize];
	for (int i=0; i<shipSize; i++)
		shipSquares[i]=isSAFESHIP; //initialize all ship squares to '_', indicating no hit
	xpos=x; 
	ypos=y;
	isSunk=s; 
	isHorizontal=h;
}


// copy constructor
Ship::Ship(const Ship &oldShip)
{
	shipSize=oldShip.getSize();
	name = oldShip.getName();
	shipSquares=new char[shipSize];
	for (int i=0; i<shipSize; i++)
		shipSquares[i]=oldShip.shipSquares[i]; //initialize all ship squares to '_', indicating no hit
	xpos=oldShip.getX();
	ypos=oldShip.getY();
	isSunk=oldShip.isShipSunk();
	isHorizontal=oldShip.isShipHorizontal();
}

// copy assignment operator
Ship& Ship::operator=(const Ship &right)
{
	if (this!=&right)
	{
		shipSize=right.getSize();
		name = right.getName();
		xpos=right.getX();
		ypos=right.getY();
		isSunk=right.isShipSunk();
		isHorizontal=right.isShipHorizontal();

		if (shipSize>0) // delete old memory before allocating memory in correct size
			delete [] shipSquares;
		shipSquares = new char[shipSize];
		for (int i=0; i<shipSize; i++)
			shipSquares[i]=right.shipSquares[i]; //initialize all ship squares to '_', indicating no hit


	}
	return *this;

}

// destructor deletes dynamically allocated memory
Ship::~Ship()
{
	if (shipSize > 0)
		delete [] shipSquares;
}

// getter methods
int Ship::getSize() const
{
	return shipSize;
}

int Ship::getX() const
{
	return xpos;
}

int Ship::getY() const
{
	return ypos;
}

bool Ship::isShipSunk() const
{
	return isSunk;
}

bool Ship::isShipHorizontal() const
{
	return isHorizontal;
}

std::string Ship::getName() const
{
	return name;
}

// set position
void Ship::setPosition(int x, int y, bool h)
{
	xpos=x;
	ypos=y;
	isHorizontal=h;
	return;
}

// print ship to console for visualization (only used for debugging)
void Ship::printShip() 
{
	for (int i=0; i<shipSize; i++)
		cout<<shipSquares[i]<<" ";
	cout<<"\n";
	return;
}


// function to record hit on ship, return false if there is no hit, true if there is a hit
// Note: hitLocX = location on lettered axis, hitLocY = location on numbered axis
bool Ship::recordHit(int hitLocX, int hitLocY)
{
	//check to make sure that the hit is located on the ship, return if it is not
	if ((isHorizontal & (hitLocX<xpos || hitLocX>=xpos+shipSize || hitLocY!=ypos))
		|| (!isHorizontal & (hitLocY<ypos || hitLocY>=ypos+shipSize || hitLocX!=xpos)))
		return false; //return false because it was not a hit, true will be returned otherwise
	else // if there is a hit, record it on the ship
	{
		if (isHorizontal) 
			shipSquares[hitLocX-xpos]=isHIT;
		else 
			shipSquares[hitLocY-ypos]=isHIT;
	}

	//determine whether the ship has been sunk
	isSunk=true;
	for (int i=0; i<shipSize; i++)//check for any un-hit locations, if one exists, ship is not sunk
		if (shipSquares[i]==isSAFESHIP)
			isSunk=false;

	return true;
}
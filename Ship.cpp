/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: definition of Ship functions
******************************************************************************/

#include "Ship.hpp"
#include <iostream>

using std::cout;

Ship::Ship(int size, std::string n, int x=-1, int y=-1, bool h = true)
{
	shipSize=size;
	shipSquares=new char[shipSize];
	for (int i=0; i<shipSize; i++)
		shipSquares[i]=isSAFESHIP; //initialize all ship squares to '_', indicating no hit
	xpos=x;
	ypos=y;
	isSunk=false;
	isHorizontal=h;
	name = n;
}

Ship::Ship(const Ship &oldShip)
{
	shipSize=oldShip.getSize();
	shipSquares=new char[shipSize];
	for (int i=0; i<shipSize; i++)
		shipSquares[i]=oldShip.shipSquares[i]; //initialize all ship squares to '_', indicating no hit
	xpos=oldShip.getX();
	ypos=oldShip.getY();
	isSunk=oldShip.isShipSunk();
	isHorizontal=oldShip.isShipHorizontal;
	name = oldShip.getName();
}

Ship::~Ship()
{
	if (shipSize > 0)
		delete [] shipSquares;
}


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

void Ship::setPosition(int x, int y, bool h)
{
	xpos=x;
	ypos=y;
	isHorizontal=h;
	return;
}

void Ship::printShip() 
{
	for (int i=0; i<shipSize; i++)
		cout<<shipSquares[i]<<" ";
	cout<<"\n";
	return;
}

bool Ship::recordHit(int hitLocX, int hitLocY)
{
	//check to make sure that the hit is located on the ship, return if it is not
	if ((!isHorizontal & (hitLocX<xpos || hitLocX>=xpos+shipSize || hitLocY!=ypos))
		|| (isHorizontal & (hitLocY<ypos || hitLocY>=ypos+shipSize || hitLocX!=xpos)))
		return false; //return false because it was not a hit
	else
	{
		if (!isHorizontal) 
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
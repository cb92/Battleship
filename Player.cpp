/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: definition of member functions for the player class
******************************************************************************/

#include "Player.hpp"

//constructor, takes strings for name, whether the player is automatic, and number
Player::Player(std::string n, bool a, int num)
{
	name=n;
	isAutomaticPlayer = a;
	playerNumber = num;
}

std::string Player::getName()
{
	return name;
}

bool Player::isPlayerAutomatic()
{
	return isAutomaticPlayer;
}

int Player::getPlayerNum()
{
	return playerNumber;
}
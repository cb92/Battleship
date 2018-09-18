/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: definition of member functions for the player class
******************************************************************************/

#include "Player.hpp"

//default constructor assigns values when no inputs supplied
Player::Player()
{
	name="";
	isAutomaticPlayer = false;
	playerNumber = 1;
}

//constructor, takes strings for name, whether the player is automatic, and number
Player::Player(std::string n, bool a, int num)
{
	name=n;
	isAutomaticPlayer = a;
	playerNumber = num;
}

// copy constructor
Player::Player(const Player &oldPlayer)
{
	name=oldPlayer.name;
	isAutomaticPlayer=oldPlayer.isAutomaticPlayer;
	playerNumber=oldPlayer.playerNumber;

}

//copy assignment operator 
Player& Player::operator=(const Player &obj)
{
	if (this != &obj)
	{
		name = obj.name;
		isAutomaticPlayer = obj.isAutomaticPlayer;
		playerNumber = obj.playerNumber;
	}

	return *this;
}

//getter functions (name, auto, number)
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

//setter functions (name, auto, number)
void Player::setName(std::string n)
{
	name=n;
	return;
}

void Player::setAuto(bool a)
{
	isAutomaticPlayer=a;
	return;
}

void Player::setPlayerNum(int n)
{
	playerNumber=n;
	return;
}
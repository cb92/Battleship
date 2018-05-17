/******************************************************************************
** Author: Christina Brasco
** Date created: 3/11/2018
** Last modified date: 3/11/2018
** Description: header file for the Player class
******************************************************************************/


#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		std::string name;
		bool isAutomaticPlayer;
		int playerNumber;
	public:
		Player();
		Player(std::string n, bool a, int num);
		std::string getName();
		bool isPlayerAutomatic();
		int getPlayerNum();
		void setName(std::string n);
		void setAuto(bool a);
		void setPlayerNum(int n);
};

#endif
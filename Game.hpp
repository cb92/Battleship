#include "Board.hpp"
#include "Player.hpp"

#ifndef GAME_H
#define GAME_H

enum state {P1_WIN, P2_WIN, UNFINISHED};

class Game
{
	private: 
		Player p1;
		Board p1Board;
		Player p2;
		Board p2Board;
	public:		
		bool playGame();
		void startGame();
		void initializeBoard(Board &b);
		void initializeBoardAuto(Board &b, int seedOffset=0);
		state gameCondition();
		void printGameState(Player p);
		void getNextMove(Board &b);
		void getNextMoveAuto(Board &b);
		std::string getString(int maxLen);
		int getInt(int min, int max);
		std::string getSquare();
		int printMenu();
};

#endif 
#include <string>

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int NUM_SHIPS = 5;
const int BOARD_DIM = 10;
const int BOARD_SPACES = 100;
const int SHIP_LENGTHS[NUM_SHIPS] = {5, 4, 3, 3, 2};
const int TOTAL_SHIP_SPACES = 17;
const std::string SHIP_NAMES[NUM_SHIPS] = {"Carrier","Battleship","Cruiser","Submarine","Destroyer"};

const char isHIT = 'X';
const char isMISS = 'O';
const char isWATER = 'w';
const char isSAFESHIP = '_';
const char isUNKNOWN = '?';

const int LETTER_CHAR_OFFSET=65;
const int NUMBER_CHAR_OFFSET=48;


#endif

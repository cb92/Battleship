#include "utils.hpp"
#include "Game.hpp"
#include <iostream>

bool printMenu()
{
	Game g; 
	int cont;

	std::cout<<"Welcome to Battleship! Enter 1 or 2 to: \n1. Start a new game.\n2. Quit.\n\n";
	cont = getInt(1,2);

	if (cont==1)
	{
		g.playGame();
		return true;
	}
	else 
		return false;

}

std::string getString(int maxLen)
{
	std::string retString;
	std::getline(std::cin, retString);
	while (retString.length()>maxLen)
	{
		std::cout<<"String too long! Please enter a string with <="<<maxLen<<" characters:"<<std::endl;
		std::getline(std::cin, retString);
	}

	return retString;

}



int getInt(int min, int max)
{
	std::string retString;
	std::getline(std::cin, retString);
	bool isGoodInput=false;
	int nIter=0;
	char tempChar;
	bool isNeg=false;
	int retInt=0;

	while (!isGoodInput)
	{
		isGoodInput = true;
		// get input again if required
		if (nIter>0)
		{
			std::cout<<"Bad input! Please enter an integer between "<<min<<" and "<<max<<"."<<std::endl;
			std::getline(std::cin, retString);
		}

		// process the string, char by char, to see if it's a numeric
		for (int i=0; i<retString.length(); i++)
		{
			tempChar = static_cast<char>(retString[i]);
			if (i==0 & tempChar=='-')
			{
				isNeg=true;
				continue;
			}
			else 
			{
				if (tempChar>=48 && tempChar<=57)
				{
					retInt = retInt*10+(static_cast<int>(tempChar)-48);
				}
				else 
				{
					isGoodInput = false;
					break;
				}
			}
		}
		if (isGoodInput && isNeg)
			retInt = (-1)*retInt;
		if (isGoodInput && (retInt<min || retInt>max))
			isGoodInput = false;

		if (!isGoodInput) 
		{
			retInt=0;
			isNeg=false;
		}
			
		nIter++;
	}

	return retInt;
}

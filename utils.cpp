#include "utils.hpp"
#include "Game.hpp"
#include <iostream>

bool printMenu()
{
	Game g; 
	int cont;

	std::cout<<"Welcome to Battleship! Enter 1 or 2 to: \n1. Start a new game."
				<<"\n2. Quit.\n\n";
	cont = getInt(1,2);

	if (cont==1)
	{
		g.playGame();
		return true;
	}
	else 
		return false;

}

// input validation requires two ints, to indicate the allowed range for input
// the function will prompt a user to enter an int until 
// an appropriate one is entered
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
		// prompt fot input again if input was bad
		if (nIter>0)
		{
			std::cout<<"Bad input! Please enter an integer between "<<min;
			std::cout<<" and "<<max<<"."<<std::endl;
			std::getline(std::cin, retString);
		}
		if (retString.length()>0) 
		{
			// process the string, char by char, to see if it's a numeric
			for (int i=0; i<retString.length(); i++)
			{
				tempChar = static_cast<char>(retString[i]);
				// if the first character is a negatve, note it, and continue
				if (i==0 & tempChar=='-')
				{
					isNeg=true;
				}
				// if char is numeric, update the integer to be returned
				else 
				{
					if (tempChar>=ASCII_INT_MIN && tempChar<=ASCII_INT_MAX)
					{
						retInt = retInt*10+(static_cast<int>(tempChar)-
																ASCII_INT_MIN);
					}
					else // if any non-ints encountered, break loop
					{
						isGoodInput = false;
						break;
					}
				}
			}
		}
		// zero length inputs are bad inputs
		else
		{
			isGoodInput=false;
		}

		// if negative, mutiply by -1
		if (isGoodInput && isNeg)
		{
			retInt = (-1)*retInt;
		}
		// check that int is between limits
		if (isGoodInput && (retInt<min || retInt>max))
		{
			isGoodInput = false;
		}

		// if input was bad, reset trackers and start over again
		if (!isGoodInput) 
		{
			retInt=0;
			isNeg=false;
		}
			
		nIter++;
	}

	return retInt;
}


std::string getString(int maxLen)
{
	std::string retString;
	std::getline(std::cin, retString);
	while (retString.length()>maxLen)
	{
		std::cout<<"String too long! Please enter a string with <=";
		std::cout<<maxLen<<" characters:"<<std::endl;
		std::getline(std::cin, retString);
	}

	return retString;
}
#Ship.cpp: depends on Ship.hpp, Constants.hpp
#Player.cpp: depends on Player.hpp
#Game.cpp: depends on Game.hpp
#Board.cpp: depend on Board.hpp

#Makefile to compile and link Battleship game

# *****************************************************
# Variables to control Makefile operation

CXX = g++
VARNAME = value 

# ****************************************************

shipTest: testMain.o Game.o Board.o Ship.o Player.o
	$(CXX) -o shipTest testMain.o Game.o Board.o Ship.o Player.o

testMain.o: testMain.cpp Game.hpp Player.hpp Ship.hpp Board.hpp Constants.hpp
	$(CXX) -c testMain.cpp

Game.o: Game.cpp Game.hpp Player.hpp Ship.hpp Board.hpp Constants.hpp
	$(CXX) -c Game.cpp

Board.o: Board.cpp Board.hpp Ship.hpp Constants.hpp
	$(CXX) -c Board.cpp

Ship.o: Ship.cpp Ship.hpp Constants.hpp
	$(CXX) -c Ship.cpp

Player.o:  Player.cpp Player.hpp
	$(CXX) -c Player.cpp
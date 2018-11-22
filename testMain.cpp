#include "Game.hpp"
#include "Player.hpp"
#include "utils.hpp"
#include <iostream>


using std::cout;
using std::endl;

int main()
{
	unsigned seed=time(0);
	srand(seed);

	//TEST ALL METHODS FOR SHIP CLASS 
	/*Ship myShip(5, "Carrier");
	cout<<myShip.getName()<<endl;
	cout<<myShip.getSize()<<endl;
	cout<<myShip.getX()<<endl;
	cout<<myShip.getY()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip.isShipHorizontal()<<endl;
	myShip.setPosition(1, 1, false);
	cout<<myShip.getName()<<endl;
	cout<<myShip.getSize()<<endl;
	cout<<myShip.getX()<<endl;
	cout<<myShip.getY()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip.isShipHorizontal()<<endl;
	myShip.printShip();

	Ship myShip2=myShip; // test copy constructor
	myShip2.printShip();
	myShip2.recordHit(0,0);
	myShip2.printShip();
	myShip2.recordHit(1, 2);
	myShip2.printShip();
	myShip2.recordHit(1, 3);
	myShip2.printShip();
	myShip2.recordHit(1, 4);
	myShip2.printShip();
	myShip2.recordHit(1, 5);
	myShip2.printShip();
	myShip2.recordHit(1, 1);
	myShip2.printShip();
	myShip2.recordHit(6, 1);
	myShip2.printShip();
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip2.isShipSunk()<<endl;
	myShip = myShip2; // test copy assignment operator
	cout<<myShip.isShipSunk()<<endl;
	myShip.printShip();

	//TEST ALL METHODS FOR PLAYER CLASS
	Player p1("Christina",false, 1);
	cout<<p1.getName()<<endl;
	cout<<p1.isPlayerAutomatic()<<endl;
	cout<<p1.getPlayerNum()<<endl;

	Player p2 = p1; // copy ctor test
	cout<<p2.getName()<<endl;
	cout<<p2.isPlayerAutomatic()<<endl;
	cout<<p2.getPlayerNum()<<endl;
	p2.setName("Bob");
	p2.setAuto(false);
	p2.setPlayerNum(3);
	cout<<p2.getName()<<endl;
	cout<<p2.isPlayerAutomatic()<<endl;
	cout<<p2.getPlayerNum()<<endl;

	//TEST ALL METHODS FOR BOARD CLASS 
	Board b1;
	bool test;
	test=b1.placeShip(0, 1, 1, true);
	cout<<"Ok placement: "<<test<<"\n";
	test=b1.placeShip(1, 8, 1, false);
	cout<<"Ok placement: "<<test<<"\n";
	test=b1.placeShip(1, 1, 2, true);
	cout<<"Ok placement: "<<test<<"\n";

	test=b1.recordHit(1, 1);
	test=b1.recordHit(2, 1);
	test=b1.recordHit(3, 1);
	test=b1.recordHit(4, 1);
	test=b1.recordHit(5, 1);
	test=b1.recordHit(6, 1);
	b1.printPublicBoard();
	b1.printPrivateBoard();
	Board b2 = b1; // copy constructor test 
	test=b2.recordHit(7, 1);
	b2.printPublicBoard();
	b1.printPublicBoard();
	b1 = b2; // copy assignment operator test
	b1.printPublicBoard();

	test=b1.recordHit(2, 2);
	b1.printPublicBoard();
	b1.printPrivateBoard();

	cout<<b1.getSpaceValue(1, 1)<<"\n";*/

	bool continueGame=true;

	while (continueGame)
	{
		continueGame = printMenu();
	}
	return 0;

}
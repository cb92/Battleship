#include "Game.hpp"
#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
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

	Ship myShip2=myShip;
	myShip2.printShip();
	myShip2.recordHit(0,0);
	myShip2.printShip();
	myShip2.recordHit(1, 2);
	myShip2.printShip();
	myShip2.recordHit(1, 3);
	myShip2.printShip();
	myShip2.recordHit(1, 4);
	myShip2.printShip();
	myShip2.recordHit(6, 1);
	myShip2.printShip();
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip2.isShipSunk()<<endl;


	Player p1("Christina",false, 1);
	cout<<p1.getName()<<endl;
	cout<<p1.isPlayerAutomatic()<<endl;
	cout<<p1.getPlayerNum()<<endl;

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

	test=b1.recordHit(2, 2);
	b1.printPublicBoard();
	b1.printPrivateBoard();

	cout<<b1.getSpaceValue(1, 1)<<"\n";
*/

	Game g1;
	g1.startGame();
	return 0;

}
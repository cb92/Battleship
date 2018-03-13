#include "Board.hpp"
#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Ship myShip(5, "Carrier");
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

	Board b1;
	b1.printPrivateBoard();
	b1.printPublicBoard();	

	Player p1("Christina",false, 1);
	cout<<p1.getName()<<endl;
	cout<<p1.isPlayerAutomatic()<<endl;
	cout<<p1.getPlayerNum()<<endl;

	return 0;

}
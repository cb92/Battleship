#include "Ship.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Ship myShip(5, 1, 1, true);
	cout<<myShip.getSize()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	myShip.printShip();

	Ship myShip2=myShip;
	myShip2.printShip();
	myShip2.recordHit(0,0);
	myShip2.printShip();
	myShip2.recordHit(1, 1);
	myShip2.printShip();
	myShip2.recordHit(1, 2);
	myShip2.printShip();
	myShip2.recordHit(1, 3);
	myShip2.printShip();
	myShip2.recordHit(6, 1);
	myShip2.printShip();
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip2.isShipSunk()<<endl;

	void recordHit(int hitLocX, int hitLocY);
	

	return 0;

}
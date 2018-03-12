#include "Ship.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Ship myShip(5);
	cout<<myShip.getSize()<<endl;
	cout<<myShip.isShipSunk()<<endl;
	myShip.printShip();

	Ship myShip2=myShip;
	myShip2.printShip();
	myShip2.recordHit(0);
	myShip2.recordHit(1);
	myShip2.recordHit(2);
	myShip2.recordHit(3);
	myShip2.recordHit(4);
	myShip.printShip();
	myShip2.printShip();
	cout<<myShip.isShipSunk()<<endl;
	cout<<myShip2.isShipSunk()<<endl;


	

	return 0;

}
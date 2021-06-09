#include <iostream>
#include "BasicBusiness.h"
using namespace std;

int main()
{
	// 1 Initialize
	Users users;
	Airports airports;
	Routes routes;
	Planes planes;
	Flights flights;
	Tickets tickets;
	DataOp dataOp(users, airports, routes, planes, flights, tickets);
	FileOp fileOp(dataOp);
	BasicBusiness basicBusiness(dataOp, fileOp);

	cout << "Hello, world!";
}
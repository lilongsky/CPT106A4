#include <iostream>
#include "Business.h"
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
	fileOp.readUsersFromFile();
	fileOp.readAirportsFromFile();
	fileOp.readRoutesFromFile();
	fileOp.readPlanesFromFIle();
	fileOp.readFlightsFromFIle();
	fileOp.readTicketsFromFile();
	Business basicBusiness(dataOp, fileOp);

	cout << "Hello, world!";
}
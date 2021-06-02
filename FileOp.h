#pragma once
#include<iostream>
#include<fstream>
#include"Airports.h"
#include"Planes.h"
#include"Flights.h"
#include"Routes.h"
#include"Tickets.h"
#include"Users.h"
class FileOp{
private:
	std::string fileName;
	std::fstream file;
public:
	FileOp(std::string name);
	void updateFile(Airports p_Airports);
	void updateFile(Planes p_Planes);
	void updateFile(Flights p_Flights);
	void updateFile(Routes p_Routes);
	void updateFile(Tickets p_Tickets);
	void updateFile(Users p_Users);
	Airports readAirportsFromFile();
	Planes readPlanesFromFIle();
	Flights readFlightsFromFIle();
	Routes readRoutesFromFile();
	Tickets readTicketsFromFile();
	Users readUsersFromFile();
};


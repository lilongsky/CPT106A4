#pragma once
#ifndef FILE_OP_H
#define FILE_OP_H


#include<fstream>
#include"../CPT106A4/VectorClass/Airports.h"
#include"VectorClass/Flights.h"
#include"VectorClass/Planes.h"
#include"VectorClass/Routes.h"
#include"VectorClass/Tickets.h"
#include"VectorClass/Users.h"
class FileOp{
private:
	std::string fileName;
	std::fstream file;
public:
	FileOp(std::string p_fileName);
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
#endif // !FILE_OP_H



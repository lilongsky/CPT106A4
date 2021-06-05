#pragma once
#ifndef FILE_OP_H
#define FILE_OP_H
#include <fstream>
//#include "VectorClass/Airports.h"
//#include "VectorClass/Flights.h"
//#include "VectorClass/Planes.h"
//#include "VectorClass/Routes.h"
//#include "VectorClass/Tickets.h"
//#include "VectorClass/Users.h"
#include"DataOp.h"

class FileOp
{
private:
	std::fstream file;
	DataOp* dataOpPtr;

public:
	FileOp();

	void updateAirportsFile(std::vector<Airport> p_Airports);
	void updatePlanesFile(std::vector<Plane> p_Planes);
	void updateFlightsFile(std::vector<Flight> p_Flights);
	void updateRoutesFile(std::vector<Route>  p_Routes);
	void updateTicketsFile(std::vector<Ticket>  p_Tickets);
	void updateUsersFile(std::vector<User> p_Users);

	void readAirportsFromFile();
	void readPlanesFromFIle();
	void readFlightsFromFIle();
	void readRoutesFromFile();
	void readTicketsFromFile();
	void readUsersFromFile();
};
FileOp::FileOp(){}
// All File should be "data1 data2 data3 .....datafinal\n"
// For pointer in file it shows the real data of the pointer 
void FileOp::updateAirportsFile(std::vector<Airport> p_Airports){
	file.open("Airport.txt", std::ios::out | std::ios::trunc);
	for (int i = 0 ; i < p_Airports.size(); i++){
		file << p_Airports.at(i).getAirportName() << std::endl;
	}
}

// Infile 'AirportName \n'
void FileOp::readAirportsFromFile(){
	file.open("Airports.txt", std::ios::in);
	std::string temp_APName;
	while (!file.eof()){
		file >> temp_APName;
		dataOpPtr->addAirport(temp_APName);
	}
	file.close();
}
// Infile 'PlaneId PlaneType \n'
void FileOp::readPlanesFromFIle(){
	file.open("Planes.txt", std::ios::in);

}

void FileOp::readFlightsFromFIle(){
	file.open("Flights.txt", std::ios::in);



}

void FileOp::readRoutesFromFile(){
	file.open("Routes.txt", std::ios::in);

}
void FileOp::readTicketsFromFile(){
	file.open("Tickets.txt", std::ios::in);
}

void FileOp::readUsersFromFile(){
	file.open("Users.txt", std::ios::in);
}
#endif // !FILE_OP_H

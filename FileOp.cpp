#include "FileOp.h"
using namespace std;
FileOp::FileOp(std::string){
	this->fileName = fileName;
}
// All File should be "data1 data2 data3 .....datafinal\n"
// For pointer in file it shows as the index in the 
void FileOp::updateFile(Airports p_Airports){
	file.open("Airports.txt", ios::out);
}

void FileOp::updateFile(Planes p_Planes){
}

void FileOp::updateFile(Flights p_Flights){
}

void FileOp::updateFile(Routes p_Routes){
}

void FileOp::updateFile(Tickets p_Tickets){
}

void FileOp::updateFile(Users p_Users){
}


Airports FileOp::readAirportsFromFile(){
	file.open("Airports.txt", ios::in);
	string tempAirportName;
	Airport tempAirport(tempAirportName);
	Airports tempAirports;
	while (!file.eof())	{
		file >> tempAirportName;
		tempAirport.setAirport(tempAirportName);
		tempAirports.add(tempAirport);
	}
	return tempAirports;
}

Planes FileOp::readPlanesFromFIle(){
	file.open("Airports.txt", ios::in);
	string tempPlaneType,tempPlaneId;
	Planes tempPlanes;
	while (!file.eof()){
		file >> tempPlaneType>>tempPlaneId;
		Plane tempPlane(tempPlaneId,tempPlaneType);
		tempPlanes.add(tempPlane);
	}
	return tempPlanes;
}

Flights FileOp::readFlightsFromFIle(){


	return Flights();
}

Routes FileOp::readRoutesFromFile(){
	return Routes();
}

Tickets FileOp::readTicketsFromFile(){
	return Tickets();
}

Users FileOp::readUsersFromFile(){
	return Users();
}

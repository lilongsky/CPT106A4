#pragma once
#ifndef FILE_OP_CPP
#define FILE_OP_CPP


#include "FileOp.h"
FileOp::FileOp(std::string p_fileName){
	this->fileName = p_fileName;
}
// All File should be "data1 data2 data3 .....datafinal\n"
// For pointer in file it shows the real data of the pointer
void FileOp::updateFile(Airports p_Airports){
	file.open("Airports.txt", std::ios::out | std::ios::trunc);
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

// Infile 'AirportName \n'
Airports FileOp::readAirportsFromFile(){
	file.open("Airports.txt", std::ios::in);
	std::string tempAirportName;
	Airport tempAirport(tempAirportName);
	Airports tempAirports;
	while (!file.eof())	{
		file >> tempAirportName;
		tempAirport.setAirport(tempAirportName);
		tempAirports.add(tempAirport);
	}
	return tempAirports;
}
// Infile 'PlaneId PlaneType \n'
Planes FileOp::readPlanesFromFIle(){
	file.open("Airports.txt", std::ios::in);
	std::string tempPlaneType,tempPlaneId;
	Planes tempPlanes;
	while (!file.eof()){
		file >> tempPlaneId >> tempPlaneType;
		Plane tempPlane(tempPlaneId,tempPlaneType);
		tempPlanes.add(tempPlane);
	}
	return tempPlanes;
}

Flights FileOp::readFlightsFromFIle(){
	file.open("Flights.txt");


	return Flights();
}

Routes FileOp::readRoutesFromFile(){
	file.open("Routes.txt", std::ios::in);
	std::string tempSrc, tempDest;
	int tempDuri;
	file >> tempSrc >> tempDest >> tempDuri;
	return Routes();
}

Tickets FileOp::readTicketsFromFile(){
	return Tickets();
}

Users FileOp::readUsersFromFile(){
	return Users();
}
#endif // !FILE_OP_CPP
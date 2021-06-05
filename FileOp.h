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
FileOp::FileOp(std::string p_fileName){
	this->fileName = p_fileName;
}
// All File should be "data1 data2 data3 .....datafinal\n"
// For pointer in file it shows the real data of the pointer 
void FileOp::updateFile(Airports p_Airports){
	file.open("Airports.txt", std::ios::out, std::ios::trunc);
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
	while (!file.eof()){
		file >> tempAirportName;
		tempAirport.setAirport(tempAirportName);
		tempAirports.add(tempAirport);
	}
	return tempAirports;
}
// Infile 'PlaneId PlaneType \n'
Planes FileOp::readPlanesFromFIle(){
	file.open("Airports.txt", std::ios::in);
	std::string tempPlaneType, tempPlaneId;
	Planes tempPlanes;
	while (!file.eof()){
		file >> tempPlaneId >> tempPlaneType;
		Plane tempPlane(tempPlaneId, tempPlaneType);
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
#endif // !FILE_OP_H



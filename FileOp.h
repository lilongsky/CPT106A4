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

	void updateAirportsFile();
	void updatePlanesFile();
	void updateFlightsFile();
	void updateRoutesFile();
	void updateTicketsFile();
	void updateUsersFile();

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
void FileOp::updateAirportsFile(){
	file.open("Airport.txt", std::ios::out | std::ios::trunc);
	for (int i = 0 ; i < dataOpPtr->getAPVectorCopy().size(); i++){
		file << dataOpPtr->getAPVectorCopy().at(i).getAirportName() << std::endl;
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

void FileOp::updatePlanesFile() {
	file.open("Planes.txt", std::ios::out | std::ios::trunc);
	/*for (int i = 0; i < dataOpPtr->getPVectorCopy().size(); i++) {
		file << dataOpPtr->getPVectorCopy().at(i).getPlaneID() << " "<<dataOpPtr->getPVectorCopy().at(i).getPlaneType() <<std::endl;
	}*/
	file.close();
}

// Infile 'PlaneId PlaneType \n'
void FileOp::readPlanesFromFIle(){
	file.open("Planes.txt", std::ios::in);
	std::string temp_PID,temp_PType;
	while (!file.eof()) {
		file >> temp_PID >> temp_PType;
		/*dataOpPtr->addPlaneID(temp_PID);
		daraOpPtr->addPlaneType(temp_PType)*/
	}
	file.close();
}

void FileOp::updateFlightsFile() {
	file.open("Flights.txt", std::ios::out | std::ios::trunc);
	/*for (int i = 0; i < dataOpPtr->getFVectorCopy().size(); i++) {
		file << dataOpPtr->getFVectorCopy().at(i).getPlaneID() << " "<<dataOpPtr->getPVectorCopy().at(i).getPlaneType() <<std::endl;
	}*/
	file.close();
}

void FileOp::readFlightsFromFIle(){
	file.open("Flights.txt", std::ios::in);
	file.close();

}

void FileOp::updateRoutesFile() {
	file.open("Routes.txt", std::ios::out | std::ios::trunc);
	//for (int i = 0; i < dataOpPtr->getRVectorCopy().size(); i++) {
	//	
	//}
	file.close();
}

void FileOp::readRoutesFromFile(){
	file.open("Routes.txt", std::ios::in);
	file.close();

}

void FileOp::updateTicketsFile() {
	file.open("Tickets.txt", std::ios::out | std::ios::trunc);
	file.close();
}

void FileOp::readTicketsFromFile(){
	file.open("Tickets.txt", std::ios::in);
	file.close();
}

void FileOp::updateUsersFile() {
	file.open("Users.txt", std::ios::out | std::ios::trunc);
	/*for (int i = 0; i < dataOpPtr->getFVectorCopy().size(); i++) {
		file << dataOpPtr->getUVectorCopy().at(i).getUserId() << " "<<dataOpPtr->getUVectorCopy().at(i).getUserName() 
			<<" "<< dataOpPtr->getAPVectorCopy().at(i).getUserRole <<std::endl;
	}*/
	file.close();
}


void FileOp::readUsersFromFile(){
	file.open("Users.txt", std::ios::in);
	std::string temp_UID, temp_UName, temp_URole;
	//while (!file.eof()) {
	//	file >> temp_UID >> temp_UName >> temp_URole;
	//	dataOpPtr->addUserID(temp_UID);
	//	dataOpPtr->addUserName(temp_UName);
	//	dataOpPtr->addUserRole(temp_URole);
	//}
	file.close();
}
#endif // !FILE_OP_H

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

/* external functiohn */

/* FileOp class */

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
	for (int i = 0; i < dataOpPtr->getPlaneVectorCopy().size(); i++) {
		file << dataOpPtr->getPlaneVectorCopy().at(i).getPlaneID() << " "
			<<dataOpPtr->getPlaneVectorCopy().at(i).getPlaneType() <<std::endl;
	}
	file.close();
}

// Infile 'PlaneId PlaneType \n'
void FileOp::readPlanesFromFIle(){
	file.open("Planes.txt", std::ios::in);
	std::string temp_PID,temp_PType;
	while (!file.eof()) {
		file >> temp_PID >> temp_PType;
		dataOpPtr->addPlane(temp_PID,temp_PType);
	}
	file.close();
}

void FileOp::updateFlightsFile() {
	file.open("Flights.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getFlightVectorCopy().size(); i++) {
		file << dataOpPtr->getFlightVectorCopy().at(i).getFlightID() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getPlane().getPlaneID() <<" "
			<< dataOpPtr->getFlightVectorCopy().at(i).getRoute().getTKOF_AP().getAirportName() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getRoute().getDEST_AP().getAirportName() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getTKOFTime() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getLandTime() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getPrice() <<std::endl;
	}
	file.close();
}

void FileOp::readFlightsFromFIle(){
	file.open("Flights.txt", std::ios::in);
	std::string temp_FID, temp_PID, temp_TKOF_AP, temp_DEST_AP;
	time_t temp_TKOF_Time, temp_LAND_Time;
	int temp_Price;
	
	while (!file.eof()) {
		file >> temp_FID >> temp_PID >> temp_TKOF_AP >> temp_DEST_AP >> temp_TKOF_Time >> temp_LAND_Time;
		dataOpPtr->addFlight(temp_FID, temp_PID, temp_TKOF_AP, temp_DEST_AP, temp_TKOF_Time, temp_LAND_Time, temp_Price);
	}
	file.close();

}

void FileOp::updateRoutesFile() {
	file.open("Routes.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getRouteVectorCopy().size(); i++) {
		file<< dataOpPtr->getRouteVectorCopy().at(i).getTKOF_AP().getAirportName() << " "
			<< dataOpPtr->getRouteVectorCopy().at(i).getDEST_AP().getAirportName() << " "
			<< dataOpPtr->getRouteVectorCopy().at(i).getDuration() << std::endl;
	}
	file.close();
}

void FileOp::readRoutesFromFile(){
	file.open("Routes.txt", std::ios::in);
	std::string temp_TKOF_AP, temp_DEST_AP;
	double temp_duration;
	while (!file.eof()) {
		file >> temp_TKOF_AP >> temp_DEST_AP >> temp_duration;
		dataOpPtr->addRoute(temp_TKOF_AP, temp_DEST_AP, temp_duration);
	}
	file.close();
}

void FileOp::updateTicketsFile() {
	file.open("Tickets.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getTicketVectorCopy().size(); i++) {
		file << dataOpPtr->getTicketVectorCopy().at(i).getTickerId() << " " << dataOpPtr->getTicketVectorCopy().at(i).getCustomerId().getUserID() << " " << dataOpPtr->getTicketVectorCopy().at(i).getFlight().getFlightID() << " " << dataOpPtr->getTicketVectorCopy().at(i).getBookTime() << " " << dataOpPtr->getTicketVectorCopy().at(i).getPayTime() << " " << dataOpPtr->getTicketVectorCopy().at(i).getExpireTime() << " " << dataOpPtr->getTicketVectorCopy().at(i).getPrice() << " " << dataOpPtr->getTicketVectorCopy().at(i).getTAId().getUserID() << std::endl;
	}
	file.close();
}

void FileOp::readTicketsFromFile(){
	file.open("Tickets.txt", std::ios::in);
	std::string temp_ticketID, temp_customerID, temp_flightID; 
	time_t temp_bookTime, temp_payTime, temp_dateOfExp;
	int temp_ticketPrice;
	std::string temp_ticketAgentPtr;
	while (!file.eof()) {
		file >> temp_ticketID >> temp_customerID >> temp_flightID >> temp_bookTime >> temp_payTime >> temp_dateOfExp 
			>> temp_ticketPrice >> temp_ticketAgentPtr;
		dataOpPtr->addTicket(temp_ticketID, temp_customerID, temp_flightID, temp_bookTime, temp_payTime
			, temp_dateOfExp, temp_ticketPrice, temp_ticketAgentPtr);
	}
	file.close();
}

void FileOp::updateUsersFile() {
	file.open("Users.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getUserVectorCopy().size(); i++) {
		file << dataOpPtr->getUserVectorCopy().at(i).getUserID() << " "
			<<dataOpPtr->getUserVectorCopy().at(i).getUserName() << " "
			<< dataOpPtr->getUserVectorCopy().at(i).getUserRole() <<std::endl;
	}
	file.close();
}


void FileOp::readUsersFromFile(){
	file.open("Users.txt", std::ios::in);
	std::string temp_UID, temp_UName, temp_URole;
	while (!file.eof()) {
		file >> temp_UID >> temp_UName >> temp_URole;
		dataOpPtr->addUser(temp_UID, temp_UName, temp_URole);
	}
	file.close();
}
#endif // !FILE_OP_H

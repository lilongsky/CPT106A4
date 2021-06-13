#pragma once

#include <fstream>
#include "DataOp.h"

class FileOp
{
private:
	DataOp* dataOpPtr;
	std::fstream file;

public:
	FileOp(DataOp &dataOp);

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

/* external function */

FileOp::FileOp(DataOp &dataOp) {
	dataOpPtr = &dataOp;
}

// All File should be "data1 data2 data3 .....datafinal\n"
// For pointer in file it shows the real data of the pointer

// Write 'AirportName \n'
void FileOp::updateAirportsFile(){
	file.open("Airports.txt", std::ios::out | std::ios::trunc);
	for (int i = 0 ; i < dataOpPtr->getAPVectorCopy().size(); i++){
		if (i > 0)
			file << std::endl;
		file << dataOpPtr->getAPVectorCopy().at(i).getAirportName();
	}
	file.close();
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

// Write 'PlaneId PlaneType \n'
void FileOp::updatePlanesFile() {
	file.open("Planes.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getPlaneVectorCopy().size(); i++) {
		if (i > 0)
			file << std::endl;
		file << dataOpPtr->getPlaneVectorCopy().at(i).getPlaneID() << " "
			<<dataOpPtr->getPlaneVectorCopy().at(i).getPlaneType();
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

// Write 'FlightID PlaneID TakeOffAirport DestinationAirport TakeOffTime LandTime TicketPrice\n'
void FileOp::updateFlightsFile() {
	file.open("Flights.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getFlightVectorCopy().size(); i++) {
		if (i > 0)
			file << std::endl;
		file << dataOpPtr->getFlightVectorCopy().at(i).getFlightID() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getPlane().getPlaneID() <<" "
			<< dataOpPtr->getFlightVectorCopy().at(i).getRoute().getTKOF_AP().getAirportName() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getRoute().getDEST_AP().getAirportName() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getTKOFTime() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getLandTime() << " "
			<< dataOpPtr->getFlightVectorCopy().at(i).getPrice();
	}
	file.close();
}

// Infile 'FlightID PlaneID TakeOffAirport DestinationAirport TakeOffTime LandTime TicketPrice\n'
void FileOp::readFlightsFromFIle(){
	file.open("Flights.txt", std::ios::in);
	std::string temp_FID, temp_PID, temp_TKOF_AP, temp_DEST_AP;
	time_t temp_TKOF_Time, temp_LAND_Time;
	int temp_Price = 0;

	while (!file.eof()) {
		file >> temp_FID >> temp_PID >> temp_TKOF_AP >> temp_DEST_AP >> temp_TKOF_Time >> temp_LAND_Time;
		dataOpPtr->addFlight(temp_FID, temp_PID, temp_TKOF_AP, temp_DEST_AP, temp_TKOF_Time, temp_LAND_Time, temp_Price);
	}
	file.close();

}

// Write ' TakeOffAirport DestinationAirport Duration \n'
void FileOp::updateRoutesFile() {
	file.open("Routes.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getRouteVectorCopy().size(); i++) {
		if (i > 0)
			file << std::endl;
		file<< dataOpPtr->getRouteVectorCopy().at(i).getTKOF_AP().getAirportName() << " "
			<< dataOpPtr->getRouteVectorCopy().at(i).getDEST_AP().getAirportName() << " "
			<< dataOpPtr->getRouteVectorCopy().at(i).getDuration();
	}
	file.close();
}

// Infile ' TakeOffAirport DestinationAirport Duration \n'
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

// Write 'TicketID CustomerID FlightID bookTime PayTime DataOfExp TicketPrice TicketAgent SeatRow SeatCol \n'
void FileOp::updateTicketsFile() {
	file.open("Tickets.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getTicketVectorCopy().size(); i++) {
		if (i > 0)
			file << std::endl;
		file << dataOpPtr->getTicketVectorCopy().at(i).getTicketID() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getCustomer().getUserID() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getFlight().getFlightID() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getBookTime() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getPayTime() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getExpireTime() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getPrice() << " " 
			<< dataOpPtr->getTicketVectorCopy().at(i).getTA().getUserID() << " "
			<<dataOpPtr->getTicketVectorCopy().at(i).getSeatCol()<<" "
			<<dataOpPtr->getTicketVectorCopy().at(i).getSeatRow();
	}
	file.close();
}

// Infile 'TicketID CustomerID FlightID bookTime PayTime DataOfExp TicketPrice TicketAgent SeatRow SeatCol \n'
void FileOp::readTicketsFromFile(){
	file.open("Tickets.txt", std::ios::in);
	std::string temp_ticketID, temp_customerID, temp_flightID;
	time_t temp_bookTime, temp_payTime, temp_dateOfExp;
	int temp_ticketPrice = 0;
	std::string temp_ticketAgentName;
	int temp_row = 0, temp_col = 0;
	while (!file.eof()) {
		file >> temp_ticketID >> temp_customerID >> temp_flightID >> temp_bookTime >> temp_payTime >> temp_dateOfExp
			>> temp_ticketPrice >> temp_ticketAgentName >> temp_row >> temp_col;
		dataOpPtr->addTicket(temp_ticketID, temp_customerID, temp_flightID, temp_bookTime, temp_payTime
			, temp_dateOfExp, temp_ticketPrice, temp_ticketAgentName, temp_row, temp_col);
	}
	file.close();
}

// Write ' UserID UserName UserRole /n'
void FileOp::updateUsersFile() {
	file.open("Users.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < dataOpPtr->getUserVectorCopy().size(); i++) {
		if (i > 0)
			file << std::endl;
		file << dataOpPtr->getUserVectorCopy().at(i).getUserID() << " "
			<<dataOpPtr->getUserVectorCopy().at(i).getUserName() << " "
			<< dataOpPtr->getUserVectorCopy().at(i).getUserRole();
	}
	file.close();
}

// Infile ' UserID UserName UserRole /n'
void FileOp::readUsersFromFile(){
	file.open("Users.txt", std::ios::in);
	std::string temp_UID, temp_UName, temp_URole;
	while (!file.eof()) {
		file >> temp_UID >> temp_UName >> temp_URole;
		dataOpPtr->addUser(temp_UID, temp_UName, temp_URole);
	}
	file.close();
}

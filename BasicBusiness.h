#pragma once
#include"FileOp.h"
#include"DataOp.h"
const double exiprationDuration = 30;
class BasicBusiness{
private:
	DataOp* dataOpPtr;
	FileOp* fileOpPtr;
public:
	BasicBusiness();
	void addNewUser(std::string p_userId, std::string p_realname, std::string p_role);
	void addNewAirport(std::string p_name);
	void addNewRoute(std::string p_src, std::string p_dest, double p_durition);
	void addNewPlane(std::string p_plane, std::string p_type);
	void creatNewFlight(std::string p_PlaneId, time_t p_TakeOffTIme, time_t p_LandingTime, int price);
	
	void bookTicket(std::string p_UserIdC, std::string p_flightId, std::string p_seat, time_t p_booktime, std::string p_UserIdTA);
	
	void payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat, time_t p_PayTime);
	void payForTicket(std::string p_TicketId);
	
	void deleteAirport(std::string p_name);
	void deleteRoute(std::string p_src, std::string p_dest, double p_durition);
	void deletePlane(std::string p_planeId);
	void deleteFlight(std::string p_PlaneId);
	void deleteTicket(std::string p_ticketId);

	int getPassagerOnFlight(std::string p_FlightId);
	int getRevenue(time_t p_StartTime, time_t p_EndTime);
	int getSellTicketNumbers(std::string p_UserId);
	std::vector<Flight> getFlightsInfo(time_t p_date, std::string p_src, std::string p_dest);
	std::string getFlightSeatInfo(std::string p_FlightId);
	int getPlaneNumber(std::string p_FlightType);
	std::vector<Flight> getPlaneInfo(std::string p_planeId);
	bool isPlaneInAirport(std::string p_planeId, std::string p_Airport);

	void modifyAirport(std::string p_name);
	void modifyRoute(std::string p_src, std::string p_dest, double p_durition);
	void modifyPlane(std::string p_planeId);
	void modifyFlight(std::string p_PlaneId);
	void modifyTicket(std::string p_ticketId);
};
BasicBusiness::BasicBusiness(){}
void BasicBusiness::addNewUser(std::string p_userId, std::string p_realname, std::string p_role){
	if (dataOpPtr->searchUser(p_userId,p_realname,p_role).size() == 0){
		dataOpPtr->addUser(p_userId, p_realname, p_role);
		fileOpPtr->updateUsersFile();
	}

}
void BasicBusiness::addNewAirport(std::string p_name){
	if (dataOpPtr->searchAirport(p_name).size()==0){
		dataOpPtr->addAirport(p_name);
		fileOpPtr->updateAirportsFile();
	}
	//else{
	//	throw();
	//}
}
void BasicBusiness::addNewRoute(std::string p_src, std::string p_dest, double p_durition){
	if (dataOpPtr->searchRoute(p_src,p_dest,p_durition).size() == 0){
		dataOpPtr->addRoute(p_src, p_dest, p_durition);
		fileOpPtr->updateRoutesFile();
	}
	//else{
	//	throw()
	//}
}
void BasicBusiness::addNewPlane(std::string p_plane, std::string p_type){
	if (dataOpPtr->searchPlane(p_plane, p_type).size() == 0){
		dataOpPtr->addPlane(p_plane, p_type);
		fileOpPtr->updatePlanesFile();
	}
}

void BasicBusiness::creatNewFlight(std::string p_PlaneId, time_t p_TakeOffTIme, time_t p_LandingTime, int price){

}

void BasicBusiness::bookTicket(std::string p_UserIdC, std::string p_flightId, std::string p_seat,time_t p_booktime, std::string p_UserIdTA){
	//confir their is flightId
	std::vector<Flight> tempFlight;
	
	if (tempFlight.size() < 1){
		//throw
	}
	//confirm their is a seat for the flight

	//get time 

	//set book time
	time_t expTime = p_booktime + (exiprationDuration * 60);
	
	//get price
	int price = tempFlight.at(0).getPrice();
	//add ticket
	dataOpPtr->addTicket(p_UserIdC + p_flightId + p_seat, 
		p_UserIdC, 
		p_flightId, 
		p_booktime, 
		NULL, 
		expTime, 
		price, 
		p_UserIdTA
	);
}	
void BasicBusiness::payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat,time_t p_PayTime){
	std::vector<Ticket> tempTicket;
	tempTicket = dataOpPtr->searchTicket("NULL", p_UserId, p_FlightId, NULL, NULL, NULL, NULL, NULL);
	
	//isTickeExisient
	if (tempTicket.size() == 0){/*throw()*/}
	
	//isTicketExpiration
	tempTicket.at(0);
	//setPayTime
	
	//updateFile
	fileOpPtr->updateTicketsFile();

}

void BasicBusiness::payForTicket(std::string p_TicketId){
	std::vector<Ticket> tempTicket;
	//isTickeExisient
	tempTicket = dataOpPtr->searchTicket(p_TicketId, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	if (tempTicket.size() == 0){
		//throw()
	}
	//isTicketExpiration
	//if (tempTicket.at(0)){

	//}
	//setPayTime

	//updateFile
	fileOpPtr->updateTicketsFile();
}


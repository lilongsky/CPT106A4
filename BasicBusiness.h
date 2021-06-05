#pragma once
#include"FileOp.h"
#include"DataOp.h"
class BasicBusiness{
private:
	DataOp* dataOpPtr;
	FileOp* fileOpPtr;
public:
	BasicBusiness();
	void addNewUser(std::string p_userId, std::string p_realname, std::string role);
	void addNewAirport(std::string p_name);
	void addNewRoute(std::string p_src, std::string p_dest, double p_durition);
	void addNewPlane(std::string p_plane, std::string p_type);
	void creatNewFlight(std::string p_PlaneId, time_t p_TakeOffTIme, time_t p_LandingTime, int price);
	void bookTicket(std::string p_UserIdC, std::string p_flightId, std::string p_seat, std::string p_UserIdTA);
	void payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat);
	void payForTicket(std::string p_TicketId);
	void deleteAirport(std::string p_name);
	void deleteRoute(std::string p_src, std::string p_dest, double p_durition);
	void deletePlane(std::string p_plane);
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

};
BasicBusiness::BasicBusiness(){}
void BasicBusiness::addNewUser(std::string p_userId, std::string p_realname, std::string role){

}
void BasicBusiness::addNewAirport(std::string p_name){
	if (true/*No Same Airport */){
		dataOpPtr->addAirport(p_name);
		/*fileOpPtr->updateAirportsFile()*/;
	}
	//else{
	//	throw();
	//}
}
void BasicBusiness::addNewRoute(std::string p_src, std::string p_dest, double p_durition){
	if (true/*No same Route */){
		dataOpPtr->addRoute(p_src, p_dest, p_durition);
		/*fileOpPtr->updateRoutesFile()*/
	}
	//else{
	//	throw()
	//}
}
void BasicBusiness::addNewPlane(std::string p_plane, std::string p_type){
	if (true/* No Same Plane*/){
		
	}
}

void BasicBusiness::creatNewFlight(std::string p_PlaneId, time_t p_TakeOffTIme, time_t p_LandingTime, int price){

}

void BasicBusiness::bookTicket(std::string p_UserIdC, std::string p_flightId, std::string p_seat, std::string p_UserIdTA){
	//confir their is planeId
	
	//confirm their is a seat for the flight

	//get time 


}	
void BasicBusiness::payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat){
	//isTickeExisient

	//isTicketExpiration

	//setPayTime

	//updateFile
}

void BasicBusiness::payForTicket(std::string p_TicketId){

}


#pragma once
#include"FileOp.h"
#include"DataOp.h"
class BasicBusiness{
private:
	DataOp* dataOpPtr;
	FileOp* fileOpPtr;
public:
	void addNewAirport(std::string p_name);
	void addNewRote(std::string p_src, std::string p_dest, double p_durition);
	void addNewPlane(std::string p_plane, std::string p_type);
	void creatNewFlight(std::string p_PlaneId, time_t p_TakeOffTIme, time_t p_LandingTime, int price);
	void bookTicket(std::string p_UserIdC, std::string p_planeId, std::string p_seat, std::string p_UserIdTA);
	void payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat);
	void payForTicket(std::string p_TicketId);
	int getPassagerOnFlight(std::string p_FlightId);
	int getRevenue(time_t p_StartTime, time_t p_EndTime);
	int getSellTicketNumbers(std::string p_UserId);
};
void BasicBusiness::addNewAirport(std::string p_name){
	if (true/*No Same Airport */){
		dataOpPtr->addAirport(p_name);
		fileOpPtr->updateAirportsFile(dataOpPtr->getAPVectorCopy());
	}
	//else{
	//	throw();
	//}
}
void BasicBusiness::addNewRote(std::string p_src, std::string p_dest, double p_durition){
	if (true/*No same Route */){
		dataOpPtr->addRoute(p_src, p_dest, p_durition);
		/*fileOpPtr->updateRoutesFile(dataOpPtr->getRouteVectorCopy())*/
	}
	//else{
	//	throw()
	//}
}
void BasicBusiness::addNewPlane(std::string p_plane, std::string p_type){
	if (true/* No Same Plane*/){
		
	}
}

void BasicBusiness::bookTicket(std::string p_UserIdC, std::string p_planeId, std::string p_seat, std::string p_UserIdTA){
	//confirm their is a seat for the flight

	//get time 
}
void BasicBusiness::payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat){

}

void BasicBusiness::payForTicket(std::string p_TicketId){

}


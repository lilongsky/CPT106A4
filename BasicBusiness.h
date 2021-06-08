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
	void creatNewFlight(std::string p_PlaneId, 
		std::string p_PlaneType, 
		std::string src, 
		std::string dest, 
		time_t p_TakeOffTIme, 
		time_t p_LandingTime, 
		int price);
	
	void bookTicket(std::string p_UserIdC, 
		std::string p_flightId, 
		std::string p_seat, 
		time_t p_booktime, 
		std::string p_UserIdTA);
	
	void payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat, time_t p_PayTime);
	void payForTicket(std::string p_TicketId, time_t p_PayTime);
	
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
	std::vector<Flight> getPlaneFlights(std::string p_planeId);
	bool isPlaneInAirport(std::string p_planeId, std::string p_Airport,time_t p_time);//time_t is a time point

	void modifyUser(std::string p_userId, std::string p_realname, std::string p_role);
	void modifyAirport(std::string p_name);
	void modifyRoute(std::string p_src, std::string p_dest, double p_durition);
	void modifyPlane(std::string p_plane, std::string p_type);
	void modifyFlight(std::string flightID,
		std::string p_planeID,
		std::string p_TKOF_AP_Name, std::string p_DEST_AP_Name,
		time_t p_TKOFTime, time_t p_LandTime,
		int p_price);
	void modifyTicket(std::string p_ticketID,
		std::string p_customerID,
		std::string p_flightID,
		time_t p_bookTime, time_t p_payTime, time_t p_ExpireTime,
		int p_ticketPrice,
		std::string p_ticketAgentID);
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

void BasicBusiness::creatNewFlight(std::string p_PlaneId, 
	std::string p_PlaneType,
	std::string src, 
	std::string dest, 
	time_t p_TakeOffTIme, 
	time_t p_LandingTime, 
	int price){
	//PlaneID check
	if ((dataOpPtr->searchPlane(p_PlaneId).size()) == 0){
		/*throw()*/
	}//no planeid
	//TKOFT and LANDT Time Check
	if (p_TakeOffTIme > p_LandingTime){
		/*throw()*/
	}
	// FlyTimeCheck
	double tempDurition = dataOpPtr->searchRoute(src, dest).at(0).getDuration();
	if (difftime(p_LandingTime, p_TakeOffTIme) >= tempDurition){
		/*throw()*/
	}
	//plane Time Check
	std::vector<Flight> tempFlights;
	tempFlights = dataOpPtr->searchFlight("NULL", p_PlaneId, "NULL", "NULL", NULL, NULL, NULL);
	time_t MaxLandT, tempLandT;
	Airport tempPlaneLastDest;
	Airport tempSrc(src);
	MaxLandT = INT16_MIN;
	for (int i = 0; i < tempFlights.size(); i++){
		tempLandT = tempFlights.at(i).getLandTime();
		if (tempLandT > MaxLandT){
			MaxLandT = tempLandT;
			tempPlaneLastDest.hardcopy(tempFlights.at(i).getRoute().getDEST_AP());
		}
	}//Search for latest LandT
	if ((p_TakeOffTIme < MaxLandT)){
		/*throw()*/
	}//No plane use Time Problem
	if (tempPlaneLastDest.isSameAirport(tempSrc)){
		/*throw()*/
	}//no plane in airport 
	//change take off time to string
	char StringTkofT[13];
	struct tm* p_TakeOffTimeSt;
	p_TakeOffTimeSt = gmtime(&p_TakeOffTIme);
	strftime(StringTkofT, sizeof(StringTkofT), "%Y%m%d%H%M", p_TakeOffTimeSt);
	//generate Flight ID
	std::string FlightID;
	FlightID = p_PlaneId + StringTkofT;
	dataOpPtr->addFlight(FlightID,p_PlaneId,src,dest,p_TakeOffTIme,p_LandingTime,price);
	fileOpPtr->updateFlightsFile();
}

void BasicBusiness::bookTicket(std::string p_UserIdC, std::string p_flightId, std::string p_seat,time_t p_booktime, std::string p_UserIdTA){
	//confir their is flightId
	std::vector<Flight> tempFlight;
	
	if (tempFlight.size() < 1){
		//throw
	}
	//confirm their is a seat for the flight

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
	fileOpPtr->updateTicketsFile();
}	
void BasicBusiness::payForTicket(std::string p_FlightId, std::string p_UserId, std::string p_seat,time_t p_PayTime){
	std::vector<Ticket> tempTicket;
	tempTicket = dataOpPtr->searchTicket("NULL", p_UserId, p_FlightId, NULL, NULL, NULL, NULL, "NULL");
	
	//isTickeExisient
	if (tempTicket.size() == 0){/*throw()*/}
	
	//isTicketExpiration
	time_t tempExpTime;
	tempExpTime = tempTicket.at(0).getExpireTime();
	if (p_PayTime > tempExpTime){
		/*throw()*/
	}
	//setPayTime
	

	//updateFile
	fileOpPtr->updateTicketsFile();

}

void BasicBusiness::payForTicket(std::string p_TicketId, time_t p_PayTime){
	std::vector<Ticket> tempTicket;
	//isTickeExisient
	tempTicket = dataOpPtr->searchTicket(p_TicketId, "NULL", "NULL", NULL, NULL, NULL, NULL, "NULL");
	if (tempTicket.size() == 0){
		//throw()
	}
	//isTicketExpiration
	time_t tempExpTime;
	tempExpTime = tempTicket.at(0).getExpireTime();
	if (p_PayTime > tempExpTime){
		/*throw()*/
	};
	//setPayTime

	//updateFile
	fileOpPtr->updateTicketsFile();
}
int BasicBusiness::getPassagerOnFlight(std::string p_FlightId){
	std::vector<Ticket> tempTicket;
	tempTicket = dataOpPtr->searchTicket("NULL", NULL, p_FlightId, NULL, NULL, NULL, NULL, "NULL");
	return tempTicket.size();
}

int BasicBusiness::getSellTicketNumbers(std::string p_UserId){
	std::vector<Ticket> tempTicket;
	tempTicket = dataOpPtr->searchTicket("NULL", "NULL", "NULL", NULL, NULL, NULL, NULL, p_UserId);
	return tempTicket.size();
}

std::vector<Flight> BasicBusiness::getFlightsInfo(time_t p_date, std::string p_src, std::string p_dest){
	// wait for timeperide search
	return std::vector<Flight>();
}

int BasicBusiness::getPlaneNumber(std::string p_FlightType){
	std::vector<Plane> tempPlanes;
	tempPlanes = dataOpPtr->searchPlane("NULL", p_FlightType);
	return tempPlanes.size();
}

std::vector<Flight> BasicBusiness::getPlaneFlights(std::string p_planeId){
	vector<Flight> tempFlights;
	tempFlights = dataOpPtr->searchFlight("NULL", p_planeId, "NULL", "NULL", NULL, NULL, NULL);
	return tempFlights;
}
void BasicBusiness::modifyTicket(
	std::string p_ticketID, 
	std::string p_customerID,
	std::string p_flightID,
	time_t p_bookTime, 
	time_t p_payTime, 
	time_t p_ExpireTime, 
	int p_ticketPrice, 
	std::string p_ticketAgentID)
{
	Ticket tempTicket;
	std::vector<Ticket> tempTickets;
	tempTickets = dataOpPtr->searchTicket(p_ticketID);
	if (tempTickets.size() == 0){
		/*throw();*/
	}
	tempTicket.hardcopy(tempTickets.at(0));
	if (true){

	}
}



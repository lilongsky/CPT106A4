#pragma once

#include <vector>
#include "../BasicDataClass/Ticket.h"

class Tickets
{
	friend class DataOp;
private:
  std::vector<Ticket> ticketVector;
public:
	Tickets(){}
	std::vector<Ticket> hardcopyVector();

	int findTicketIndexByID(std::string p_ticketID);
    bool isTicketIDValid(std::string p_ticketID);
	bool isSameTicketIncluded(Ticket p_ticket);
	int findSameTicketIndex(Ticket p_ticket);
	bool isUserIncluded(User p_user);
	bool isFlightIncluded(Flight p_flight);

	void add(Ticket& p_Ticket);
	void remove(int index);
	void setTicketPayTime(Ticket oldTicket, time_t new_payTime);

	std::vector<Ticket> search(std::string ticketId);
	std::vector<Ticket> search(
		std::string ticketID,
		std::string customerID,
		std::string flightID,
		time_t bookTime, time_t payTime, time_t ExpireTime,
		int ticketPrice,
		std::string ticketAgentID
	);
};

std::vector<Ticket> Tickets::hardcopyVector(){
	std::vector<Ticket> newTicketVector(ticketVector);
	return newTicketVector;
}

int Tickets::findTicketIndexByID(std::string p_ticketID) {
	int ans = -1;
	for (int i = 0; i < ticketVector.size(); i++) {
		if (ticketVector.at(i).ticketID == (p_ticketID)) {
			ans = i;
			break;
		}
	}
	return ans;
}

bool Tickets::isTicketIDValid(std::string p_ticketID) {
	bool ans = true;
	for (int i = 0; i < ticketVector.size(); i++) {
		if (ticketVector.at(i).ticketID == p_ticketID) {
			ans = false;
			break;
		}
	}
	return ans;
}


bool Tickets::isSameTicketIncluded(Ticket p_ticket){
	bool ans = false;
	for (int i = 0; i < ticketVector.size(); i++){
		if (ticketVector.at(i).isSameTicket(p_ticket)){
			ans = true;
			break;
		}
	}
	return ans;
}

inline int Tickets::findSameTicketIndex(Ticket p_ticket){
	int ans = -1;
	for (int i = 0; i < ticketVector.size(); i++){
		if (ticketVector.at(i).isSameTicket(p_ticket)){
			ans = i;
			break;
		}
	}
	return ans;
}

bool Tickets::isUserIncluded(User p_user){
	bool ans = false;
	for (int i = 0; i < ticketVector.size(); i++){
		if (ticketVector.at(i).isSameUserIncluded(p_user)){
			ans = true;
			break;
		}
	}
	return ans;
}

bool Tickets::isFlightIncluded(Flight p_flight){
	bool ans = false;
	for (int i = 0; i < ticketVector.size(); i++){
		if (ticketVector.at(i).isSameFlight(p_flight)){
			ans = true;
			break;
		}
	}
	return ans;
}

void Tickets::add(Ticket& p_Ticket){
	ticketVector.push_back(p_Ticket);
}

void Tickets::remove(int index){
	ticketVector.erase(ticketVector.begin() + index);
}

void Tickets::setTicketPayTime(Ticket oldTicket, time_t new_payTime){
	int index = this->findSameTicketIndex(oldTicket);
	ticketVector.at(index).payTime = new_payTime;
}

inline std::vector<Ticket> Tickets::search(std::string ticketId){
	std::vector<Ticket> ansTicket;
	for (int i = 0; i < ticketVector.size(); i++){
		if (ticketVector.at(i).ticketID == ticketId){
			ansTicket.push_back(ticketVector.at(i));
		}
	}
	return ansTicket;
}

inline std::vector<Ticket> Tickets::search(
	std::string ticketID, 
	std::string customerID, 
	std::string flightID, 
	time_t bookTime, time_t payTime, time_t ExpireTime, 
	int ticketPrice, 
	std::string ticketAgentID)
{
	std::vector<Ticket> ansTicket;
	for (int i = 0; i < ticketVector.size(); i++){
		if (((ticketID == ticketVector.at(i).ticketID)||(ticketID == "NULL"))
			&&((customerID == ticketVector.at(i).getCustomer().getUserID()||(customerID == "NULL")))
			&&((flightID == ticketVector.at(i).getFlight().getFlightID())||(flightID == "NULL"))
			&&((bookTime == ticketVector.at(i).bookTime)||bookTime == -2)
			&&((payTime == ticketVector.at(i).payTime)||payTime == -2)
			&&((ExpireTime == ticketVector.at(i).ExpireTime)||(ExpireTime == -2))
			&&((ticketPrice == ticketVector.at(i).ticketPrice)||(ticketPrice == -2))
			&&((ticketAgentID == ticketVector.at(i).getTA().getUserID())||(ticketAgentID == "NULL")))
		{
			ansTicket.push_back(ticketVector.at(i));
		}
	}
	return ansTicket;
}



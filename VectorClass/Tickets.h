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

	bool isSameTicketIncluded(Ticket p_ticket);
	int findSameTicketIndex(Ticket p_ticket);
	bool isUserIncluded(User p_user);
	bool isFlightIncluded(Flight p_flight);

	void add(Ticket& p_Ticket);
	void remove(int index);
	void setTicketPayTime(Ticket oldTicket, time_t new_payTime);

};

std::vector<Ticket> Tickets::hardcopyVector(){
	std::vector<Ticket> newTicketVector(ticketVector);
	return newTicketVector;
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


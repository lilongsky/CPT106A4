#pragma once
#include<iostream>
#include<time.h>
#include"User.h"
class Ticket{
	friend class Tickects;
private:
	int customerId;
	std::string flightId;
	std::string ticketId;
	time_t bookTIme;
	time_t payTime;
	time_t dateOfExp;
	int price;
	User* ticketAgentPtr;
public:
	Ticket(int p_customerId, std::string p_flightId, std::string p_ticketId, time_t p_bookTIme, time_t p_payTime, time_t p_dateOfExp, int p_price, User* ticketAgentPtr);
};


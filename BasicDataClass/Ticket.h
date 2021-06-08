#pragma once

#include <string>
#include "../BasicDataClass/User.h"
#include "../BasicDataClass/Flight.h"

class Ticket
{
  friend class Tickets;

private:
  std::string ticketID;
  User* customerPtr;
  Flight* flightPtr;
  time_t bookTime;
  time_t payTime;
  time_t ExpireTime;
  int ticketPrice;
  User *ticketAgentPtr;

public:
    Ticket(){};
  Ticket(
    std::string p_ticketID,
    User &p_customer,
    Flight &p_flight,
    time_t p_bookTime, time_t p_payTime, time_t p_expireTime,
    int p_price,
    User &p_ticketAgent
  );
  std::string getTickerId();
  User getCustomer();
  Flight getFlight();
  time_t getBookTime();
  time_t getPayTime();
  time_t getExpireTime();
  int getPrice();
  User getTA();
  void hardcopy(Ticket p_Ticket);
};

/* Ticket class */

Ticket::Ticket(
  std::string p_ticketID,
  User &p_customer,
  Flight &p_flight,
  time_t p_bookTime, time_t p_payTime, time_t p_expireTime,
  int p_price,
  User &p_ticketAgent
) {
  ticketID = p_ticketID;
  customerPtr = &p_customer;
  flightPtr = &p_flight;
  bookTime = p_bookTime;
  payTime = p_payTime;
  ExpireTime = p_expireTime;
  ticketPrice = p_price;
  ticketAgentPtr = &p_ticketAgent;
}
std::string Ticket::getTickerId(){
    return this->ticketID;
}
User Ticket::getCustomer(){
    return *(this->customerPtr);
}
Flight Ticket::getFlight(){
    return *(this->flightPtr);
}

time_t Ticket::getBookTime(){
    return this->bookTime;
}

time_t Ticket::getPayTime(){
    return this->payTime;
}

time_t Ticket::getExpireTime(){
    return this->ExpireTime;
}

int Ticket::getPrice(){
    return this->ticketPrice;
}

User Ticket::getTA(){
     return *(this->ticketAgentPtr);
}

void Ticket::hardcopy(Ticket p_Ticket){
    this->ticketID = p_Ticket.ticketID;
    this->bookTime = p_Ticket.bookTime;
    this->customerPtr = p_Ticket.customerPtr;
    this->ExpireTime = p_Ticket.ExpireTime;
    this->flightPtr = p_Ticket.flightPtr;
    this->payTime = p_Ticket.payTime;
    this->ticketAgentPtr = p_Ticket.ticketAgentPtr;
    this->ticketPrice = p_Ticket.ticketPrice;
}


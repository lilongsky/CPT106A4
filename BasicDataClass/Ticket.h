#pragma once

#include <string>
#include "User.h"
#include "Flight.h"

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
  int col, row;
public:
  Ticket();
  Ticket(
    std::string p_ticketID,
    User &p_customer,
    Flight &p_flight,
    time_t p_bookTime, time_t p_payTime, time_t p_expireTime,
    int p_price,
    User &p_ticketAgent,
    int row,
    int col
  );
  
  void hardcopy(Ticket p_Ticket);

  std::string getTicketID();
  User getCustomer();
  Flight getFlight();
  time_t getBookTime();
  time_t getPayTime();
  time_t getExpireTime();
  int getPrice();
  User getTA();
  int getSeatRow();
  int getSeatCol();
  Seats* getFlightSeatsPtr();
  
  bool isSameUserIncluded(User p_user);

  bool isSameTicket(Ticket p_ticket);
  bool isSameCustomer(User p_customer);
  bool isSameFlight(Flight p_flghte);
  bool isSameTicketAgent(User p_ticketagent);
};

/* Ticket class */

Ticket::Ticket(){
    customerPtr = nullptr;
    flightPtr = nullptr;
    ticketAgentPtr = nullptr;
}

Ticket::Ticket(
  std::string p_ticketID,
  User &p_customer,
  Flight &p_flight,
  time_t p_bookTime, time_t p_payTime, time_t p_expireTime,
  int p_price,
  User &p_ticketAgent,
  int p_row,
  int p_col
)   {
  ticketID = p_ticketID;
  customerPtr = &p_customer;
  flightPtr = &p_flight;
  bookTime = p_bookTime;
  payTime = p_payTime;
  ExpireTime = p_expireTime;
  ticketPrice = p_price;
  ticketAgentPtr = &p_ticketAgent;
  row = p_row;
  col = p_col;
}
std::string Ticket::getTicketID(){
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

inline int Ticket::getSeatRow(){
    return this->row;
}

inline int Ticket::getSeatCol(){
    return this->col;
}

Seats* Ticket::getFlightSeatsPtr() {
    return flightPtr->getSeatsPtr();
}

bool Ticket::isSameUserIncluded(User p_user){
    if (customerPtr->isSameUser(p_user)
        ||ticketAgentPtr->isSameUser(p_user))
    {
        return true;
    }
    else{
        return false;
    }
}

bool Ticket::isSameTicket(Ticket p_Ticket){
    if ((this->ticketID == p_Ticket.ticketID)
        && (this->bookTime == p_Ticket.bookTime)
        && (this->isSameCustomer(p_Ticket.getCustomer()))
        && (this->ExpireTime == p_Ticket.ExpireTime)
        && (this->isSameFlight(p_Ticket.getFlight()))
        && (this->payTime == p_Ticket.payTime)
        && (this->isSameTicketAgent(p_Ticket.getTA()))
        && (this->ticketPrice == p_Ticket.ticketPrice))
    {   
        return true;
    }else{
        return false;
    }
}


bool Ticket::isSameCustomer(User p_customer) {
    if (customerPtr->isSameUser(p_customer))
        return true;
    else
        false;
}

bool Ticket::isSameFlight(Flight p_flghte) {
    if (flightPtr->isSameFlight(p_flghte))
        return true;
    else
        return false;
}

bool Ticket::isSameTicketAgent(User p_ticketagent) {
    if (ticketAgentPtr->isSameUser(p_ticketagent))
        return true;
    else
        false;
}
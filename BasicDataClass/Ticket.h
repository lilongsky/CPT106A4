#pragma once
#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "../BasicDataClass/User.h"
#include "../BasicDataClass/Flight.h"

class Ticket
{
  friend class Tickets;

private:
  std::string ticketID;
  int customerID;
  std::string flightID;
  time_t bookTime;
  time_t payTime;
  time_t dateOfExp;
  int ticketPrice;
  User *ticketAgentPtr;

public:
  Ticket(
    int p_customerID,
    std::string p_flightID,
    std::string p_ticketID,
    time_t p_bookTime,
    time_t p_payTime,
    time_t p_dateOfExp,
    int p_price,
    User *ticketAgentPtr);
};

/* Ticket class */

Ticket::Ticket(
  int p_customerID,
  std::string p_flightID,
  std::string p_ticketID,
  time_t p_bookTime,
  time_t p_payTime,
  time_t p_dateOfExp,
  int p_price,
  User *ticketAgentPtr)
{
  customerID = p_customerID;
  flightID = p_flightID;
  ticketID = p_ticketID;
  bookTime = p_bookTime;
  payTime = p_payTime;
  dateOfExp = p_dateOfExp;
  ticketPrice = p_price;
  this->ticketAgentPtr = ticketAgentPtr;
}
#endif // !TICKET_H

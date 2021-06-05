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
  Ticket(
    std::string p_ticketID,
    User &p_customer,
    Flight &p_flight,
    time_t p_bookTime, time_t p_payTime, time_t p_expireTime,
    int p_price,
    User &p_ticketAgent
  );
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

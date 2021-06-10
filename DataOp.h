#pragma once

#include <iostream>
#include <ctime>
#include "VectorClass/Users.h"
#include "VectorClass/Airports.h"
#include "VectorClass/Routes.h"
#include "VectorClass/Planes.h"
#include "VectorClass/Flights.h"
#include "VectorClass/Tickets.h"

class DataOp
{
friend class Business;

private:
  Users* usersPtr;
  Airports* airportsPtr;
  Routes* routesPtr;
  Planes* planesPtr;
  Flights* flightsPtr;
  Tickets* ticketsPtr;

public:
  DataOp(
    Users &users,
    Airports &airports,
    Routes &routes,
    Planes &planes,
    Flights &flights,
    Tickets &tickets
  );

  std::vector<User> getUserVectorCopy();
  std::vector<Airport> getAPVectorCopy();
  std::vector<Route> getRouteVectorCopy();
  std::vector<Plane> getPlaneVectorCopy();
  std::vector<Flight> getFlightVectorCopy();
  std::vector<Ticket> getTicketVectorCopy();

  // user
  std::vector<User> searchUser(std::string userID);
  std::vector<User> searchUser(std::string userID, std::string realName, std::string role);
  // airport
  std::vector<Airport> searchAirport(std::string APName);
  // route
  std::vector<Route> searchRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name);
  std::vector<Route> searchRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration);
  // plane
  std::vector<Plane> searchPlane(std::string planeID);
  std::vector<Plane> searchPlane(std::string planeID, std::string planeType);
  // flight
  std::vector<Flight> searchFlight(std::string flightID);
  std::vector<Flight> searchFlight(
    std::string flightID,
    std::string planeID,
    std::string TKOF_AP_Name, std::string DEST_AP_Name,
    time_t TKOFTime, time_t LandTime,
    int price
  );
  // ticket
  std::vector<Ticket> searchTicket(std::string ticketID);
  std::vector<Ticket> searchTicket(
    std::string ticketID,
    std::string customerID,
    std::string flightID,
    time_t bookTime, time_t payTime, time_t ExpireTime,
    int ticketPrice,
    std::string ticketAgentID
  );

  void addUser(std::string userID, std::string realName, std::string role);
  void addAirport(std::string APName);
  void addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration);
  void addPlane(std::string planeID, std::string planeType);
  void addFlight(
    std::string flightID,
    std::string planeID,
    std::string TKOF_AP_Name, std::string DEST_AP_Name,
    time_t TKOFTime, time_t LandTime,
    int price
  );
  void addTicket(
    std::string ticketID,
    std::string customerID,
    std::string flightID,
    time_t bookTime, time_t payTime, time_t ExpireTime,
    int ticketPrice,
    std::string ticketAgentID
  );

  void editTicketPayTime(Ticket oldTicket, time_t new_payTime);

  void delUser(std::string userID);
  void delAirport(std::string APName);
  void delRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name);
  void delPlane(std::string planeID);
  void delFlight(std::string flightID);
  void delTicket(std::string TicketID);
};

/* DataOp class */

DataOp::DataOp(
  Users &users,
  Airports &airports,
  Routes &routes,
  Planes &planes,
  Flights &flights,
  Tickets &tickets
) {
  usersPtr = &users;
  airportsPtr = &airports;
  routesPtr = &routes;
  planesPtr = &planes;
  flightsPtr = &flights;
  ticketsPtr = &tickets;
}

std::vector<User> DataOp::getUserVectorCopy() {
  return usersPtr->hardcopyVector();
}
std::vector<Airport> DataOp::getAPVectorCopy() {
  return airportsPtr->hardcopyVector();
}
std::vector<Route> DataOp::getRouteVectorCopy() {
  return routesPtr->hardcopyVector();
}
std::vector<Plane> DataOp::getPlaneVectorCopy() {
  return planesPtr->hardcopyVector();
}
std::vector<Flight> DataOp::getFlightVectorCopy() {
  return flightsPtr->hardcopyVector();
}
std::vector<Ticket> DataOp::getTicketVectorCopy() {
  return ticketsPtr->hardcopyVector();
}

void DataOp::addAirport(std::string APName) {
  if (airportsPtr->isSameAPIncluded(APName)) {
    Airport newAP(APName);
    airportsPtr->add(newAP);
  }
  // else {throw }
}

void DataOp::addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration) {
  Airport temp_TKOF_AP(TKOF_AP_Name);
  int index_TKOF_AP = airportsPtr->findSameAPIndex(temp_TKOF_AP);
  if (index_TKOF_AP == -1) {
    // throw
  }
  Airport temp_DEST_AP(DEST_AP_Name);
  int index_DEST_AP = airportsPtr->findSameAPIndex(temp_DEST_AP);
  if (index_DEST_AP == -1) {
    // throw
  }
  if (duration < 0) {
    // throw
  }

  Route newRoute(
    airportsPtr->APVector.at(index_TKOF_AP),
    airportsPtr->APVector.at(index_DEST_AP),
    duration
  );
  routesPtr->add(newRoute);
}

void DataOp::editTicketPayTime(Ticket oldTicket, time_t new_payTime){
    ticketsPtr->setTicketPayTime(oldTicket, new_payTime);
}

void DataOp::delAirport(std::string APName) {
  Airport temp_AP(APName);
  int index_AP = airportsPtr->findSameAPIndex(temp_AP);
  if (index_AP == -1) {
    // throw
  } else if (routesPtr->isSameAPIncluded(temp_AP)) {
    // throw
  } else {
    airportsPtr->remove(index_AP);
  }
}

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
    std::string ticketAgentID,
    int row, int col
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
    std::string ticketAgentID,
    int row,
    int col
  );

  void editTicketPayTime(Ticket oldTicket, time_t new_payTime);

  void delUser(User p_user);
  void delAirport(Airport p_airport);
  void delRoute(Route p_route);
  void delPlane(Plane p_plane);
  void delFlight(Flight p_flight);
  void delTicket(Ticket p_ticket);
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

// user
std::vector<User> DataOp::searchUser(std::string userID) {
    std::vector<User> ans = usersPtr->search(userID);
    return ans;
}
std::vector<User> DataOp::searchUser(std::string userID, std::string realName, std::string role) {
    std::vector<User> ans = usersPtr->search(userID, realName, role);
    return ans;
}

inline std::vector<Airport> DataOp::searchAirport(std::string APName){
    std::vector<Airport> ans = airportsPtr->search(APName);
    return ans;
}

inline std::vector<Route> DataOp::searchRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name){
    std::vector<Route> ans = routesPtr->search(TKOF_AP_Name, DEST_AP_Name);
    return ans;
}

inline std::vector<Route> DataOp::searchRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration){
    std::vector<Route> ans = routesPtr->search(TKOF_AP_Name, DEST_AP_Name, duration);
    return ans;
}

inline std::vector<Plane> DataOp::searchPlane(std::string planeID){
    std::vector<Plane> ans = planesPtr->search(planeID);
    return ans;
}

inline std::vector<Plane> DataOp::searchPlane(std::string planeID, std::string planeType){
    std::vector<Plane> ans = planesPtr->search(planeID, planeType);
    return ans;
}

inline std::vector<Flight> DataOp::searchFlight(std::string flightID){
    std::vector<Flight> ans = flightsPtr->search(flightID);
    return ans;
}

inline std::vector<Flight> DataOp::searchFlight(std::string flightID,
    std::string planeID,
    std::string TKOF_AP_Name, std::string DEST_AP_Name,
    time_t TKOFTime, time_t LandTime,
    int price)
{
    std::vector<Flight> ans = flightsPtr->search(flightID,planeID,TKOF_AP_Name,DEST_AP_Name,TKOFTime,LandTime,price);
    return ans;
}

inline std::vector<Ticket> DataOp::searchTicket(std::string ticketID){
    std::vector<Ticket> ans = ticketsPtr->search(ticketID);
    return ans;
}

inline std::vector<Ticket> DataOp::searchTicket(std::string ticketID, std::string customerID, std::string flightID, time_t bookTime, time_t payTime, time_t ExpireTime, int ticketPrice, std::string ticketAgentID,int row,int col){
    std::vector<Ticket> ans = ticketsPtr->search(ticketID,customerID,flightID,bookTime,payTime,ExpireTime,ticketPrice,ticketAgentID,row,col);
    return ans;
}


void DataOp::addUser(std::string userID, std::string realName, std::string role) {
  User new_user(userID, realName, role);
  if (usersPtr->isSameUserIncluded(new_user)) {
    throw std::logic_error("");
  } else {
    usersPtr->add(new_user);
  }
}
void DataOp::addAirport(std::string APName) {
  Airport new_AP(APName);
  if (airportsPtr->isSameAPIncluded(new_AP)) {
    throw std::logic_error("");
  } else {
    airportsPtr->add(new_AP);
  }
}
void DataOp::addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration) {
  Airport temp_TKOF_AP(TKOF_AP_Name);
  int index_TKOF_AP = airportsPtr->findSameAPIndex(temp_TKOF_AP);
  if (index_TKOF_AP == -1) {
    throw std::logic_error("");
  }
  Airport temp_DEST_AP(DEST_AP_Name);
  int index_DEST_AP = airportsPtr->findSameAPIndex(temp_DEST_AP);
  if (index_DEST_AP == -1) {
    throw std::logic_error("");
  }
  if (duration < 0) {
    throw std::logic_error("");
  }

  Route newRoute(
    airportsPtr->APVector.at(index_TKOF_AP),
    airportsPtr->APVector.at(index_DEST_AP),
    duration
  );
  routesPtr->add(newRoute);
}
void DataOp::addPlane(std::string planeID, std::string planeType) {
  Plane new_plane(planeID, planeType);
  if (planesPtr->isSamePlaneIncluded(new_plane)) {
    throw std::logic_error("");
  } else {
    planesPtr->add(new_plane);
  }
}
void DataOp::addFlight(
  std::string flightID,
  std::string planeID,
  std::string TKOF_AP_Name, std::string DEST_AP_Name,
  time_t TKOFTime, time_t LandTime,
  int price)
{
  std::vector<Plane> temp_planeVector = searchPlane(planeID);
  if (temp_planeVector.size() != 1) {
    throw std::logic_error("");
  }
  int index_plane = planesPtr->findSamePlaneIndex(temp_planeVector.at(0));

  std::vector<Route> temp_routeVector = searchRoute(TKOF_AP_Name, DEST_AP_Name);
  if (temp_routeVector.size() != 1) {
    throw std::logic_error("");
  }
  int index_route = routesPtr->findSameRouteIndex(temp_routeVector.at(0));

  if (difftime(LandTime, TKOFTime) < temp_routeVector.at(0).getDuration()) {
    throw std::logic_error("");
  }

  Flight new_flight(
    flightID,
    planesPtr->planeVector.at(index_plane),
    routesPtr->routeVector.at(index_route),
    TKOFTime, LandTime,
    price
  );
  if (flightsPtr->isSameFlightIncluded(new_flight)) {
    throw std::logic_error("");
  }
  flightsPtr->add(new_flight);
}

void DataOp::addTicket(std::string ticketID,
    std::string customerID,
    std::string flightID,
    time_t bookTime, time_t payTime, time_t ExpireTime,
    int ticketPrice,
    std::string ticketAgentID,
    int row, int col)
{
    std::vector<User> tempUserC;
    tempUserC = searchUser(customerID);
    if (tempUserC.size() != 1){
        throw std::logic_error("");
    }
    int index_UserC = usersPtr->findSameUserIndex(tempUserC.at(0));

    std::vector<User> tempUserTA;
    tempUserTA = searchUser(ticketAgentID);
    if (tempUserTA.size() != 1){
        throw std::logic_error("");
    }
    int index_UserTA = usersPtr->findSameUserIndex(tempUserTA.at(0));

    int index_flight = flightsPtr->findFlightIndexByID(flightID);
    Ticket newTicket(ticketID,
        usersPtr->userVector.at(index_UserC),
        flightsPtr->flightVector.at(index_flight),
        bookTime,
        payTime,
        ExpireTime,
        ticketPrice,
        usersPtr->userVector.at(index_UserTA),
        row,
        col
        );
    flightsPtr->flightVector.at(index_flight).getSeatsPtr()->setSeatInvalid(row, col);
    ticketsPtr->add(newTicket);
}

void DataOp::editTicketPayTime(Ticket oldTicket, time_t new_payTime) {
  ticketsPtr->setTicketPayTime(oldTicket, new_payTime);
}

void DataOp::delUser(User p_user){
    int index_User = usersPtr->findSameUserIndex(p_user);
    if (index_User == -1){
        throw std::logic_error("");
    }
    else if (ticketsPtr->isUserIncluded(p_user)){
        throw std::logic_error("");
    }
    else{
        usersPtr->remove(index_User);
    }
}

void DataOp::delAirport(Airport p_airport) {
  int index_AP = airportsPtr->findSameAPIndex(p_airport);
  if (index_AP == -1) {
    throw std::logic_error("");
  } else if (routesPtr->isSameAPIncluded(p_airport)) {
    throw std::logic_error("");
  } else {
    airportsPtr->remove(index_AP);
  }
}

void DataOp::delRoute(Route p_route){
    int index_Route = routesPtr->findSameRouteIndex(p_route);
    if (index_Route == -1){
        throw std::logic_error("");
    }
    else if (flightsPtr->isRouteIncluded(p_route)){
        throw std::logic_error("");
    }
    else{
        routesPtr->remove(index_Route);
    }
}

void DataOp::delPlane(Plane p_plane){
    int index_Plane = planesPtr->findSamePlaneIndex(p_plane);
    if (index_Plane == -1){
        throw std::logic_error("");
    }
    else if (flightsPtr->isPlaneIncluded(p_plane)){
        throw std::logic_error("");
    }
    else{
        planesPtr->remove(index_Plane);
    }
}

void DataOp::delFlight(Flight p_flight){
    int index_Flight = flightsPtr->findSameFlightIndex(p_flight);
    if (index_Flight == -1){
        throw std::logic_error("");
    }
    else if (ticketsPtr->isFlightIncluded(p_flight)){
        throw std::logic_error("");
    }
    else{
        flightsPtr->remove(index_Flight);
    }
}

void DataOp::delTicket(Ticket p_ticket){
    int index_Ticket = ticketsPtr->findSameTicketIndex(p_ticket);
    if (index_Ticket == -1){
        throw std::logic_error("");
    }
    else{
      Ticket &actual_ticket = ticketsPtr->ticketVector.at(index_Ticket);
      int temp_row = actual_ticket.getSeatRow();
      int temp_col = actual_ticket.getSeatCol();
      actual_ticket.getFlightSeatsPtr()->setSeatValid(temp_row, temp_col);
      ticketsPtr->remove(index_Ticket);
    }
}

#pragma once
#include <iostream>
#include "VectorClass/Airports.h"
#include "VectorClass/Routes.h"
#include "VectorClass/Planes.h"
#include "VectorClass/Flights.h"
#include "VectorClass/Tickets.h"
#include "VectorClass/Users.h"

class DataOp
{
private:
  Airports* airportsPtr;
  Routes* routesPtr;
  Planes* planesPtr;
  Flights* flightsPtr;
  Tickets* ticketsPtr;
  Users* usersPtr;

public:
  DataOp();

  void addAirport(std::string APName);
  void addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name);

  void removeAirport(Airport airport);
};

/* DataOp class */

void DataOp::addAirport(std::string APName) {
  if (airportsPtr->isAPNameExistent(APName)) {
    Airport newAP(APName);
    airportsPtr->add(newAP);
  }
  // else {throw }
}

void DataOp::removeAirport(Airport p_AP) {
  if (not airportsPtr->isSameAPExistent(p_AP)) {
    // throw
  } else if (routesPtr->isSameAPIncluded(p_AP)) {
    // throw
  } else {
    // TODO
  }
}
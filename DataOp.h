#pragma once

#include <iostream>
#include "VectorClass/Users.h"
#include "VectorClass/Airports.h"
#include "VectorClass/Routes.h"
#include "VectorClass/Planes.h"
#include "VectorClass/Flights.h"
#include "VectorClass/Tickets.h"

class DataOp
{
friend class BasicBusiness;

private:
  Users* usersPtr;
  Airports* airportsPtr;
  Routes* routesPtr;
  Planes* planesPtr;
  Flights* flightsPtr;
  Tickets* ticketsPtr;

public:
  DataOp() {}

  std::vector<Airport> getAPVectorCopy();

  void addAirport(std::string APName);
  void addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double p_duration);

  void removeAirport(Airport airport);
};

/* DataOp class */

std::vector<Airport> DataOp::getAPVectorCopy() {
  return airportsPtr->hardcopyVector();
}

void DataOp::addAirport(std::string APName) {
  if (airportsPtr->isSameAPIncluded(APName)) {
    Airport newAP(APName);
    airportsPtr->add(newAP);
  }
  // else {throw }
}
void DataOp::addRoute(std::string TKOF_AP_Name, std::string DEST_AP_Name, double p_duration) {
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
  if (p_duration < 0) {
    // throw
  }

  Route newRoute(
    airportsPtr->APVector.at(index_TKOF_AP),
    airportsPtr->APVector.at(index_DEST_AP),
    p_duration
  );
  routesPtr->add(newRoute);
}

void DataOp::removeAirport(Airport p_AP) {
  if (not airportsPtr->isSameAPIncluded(p_AP)) {
    // throw
  } else if (routesPtr->isSameAPIncluded(p_AP)) {
    // throw
  } else {
    // TODO
  }
}
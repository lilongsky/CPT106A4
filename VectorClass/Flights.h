#pragma once

#include <vector>
#include "../BasicDataClass/Flight.h"

class Flights
{
	friend class DataOp;

private:
  std::vector<Flight> flightVector;

public:
  Flights() {}

  std::vector<Flight> hardcopyVector();

  int findFlightIndexByID(std::string p_flightID);
  bool isFlightIDValid(std::string p_flightID);
  int findSameFlightIndex(Flight p_flight);
  bool isSameFlightIncluded(Flight p_flight);
  bool isRouteIncluded(Route p_route);
  bool isPlaneIncluded(Plane p_plane);

  void add(Flight &p_flight);
  void remove(int index);
};

/* Flights class */

std::vector<Flight> Flights::hardcopyVector() {
  std::vector<Flight> new_flightVector(flightVector);
  return new_flightVector;
}

int Flights::findFlightIndexByID(std::string p_flightID) {
    int ans = -1;
    for (int i = 0; i < flightVector.size(); i++) {
        if (flightVector.at(i).isSameFlightID(p_flightID)) {
            ans = i;
            break;
        }
    }
    return ans;
}

int Flights::findSameFlightIndex(Flight p_flight) {
  int ans = -1;
  for (int i = 0; i < flightVector.size(); i++) {
    if (flightVector.at(i).isSameFlight(p_flight)) {
      ans = i;
      break;
    }
  }
  return ans;
}

bool Flights::isFlightIDValid(std::string p_flightID) {
    bool ans = true;
    for (int i = 0; i < flightVector.size(); i++) {
        if (flightVector.at(i).isSameFlightID(p_flightID)) {
            ans = false;
            break;
        }
    }
    return ans;
}

bool Flights::isSameFlightIncluded(Flight p_flight) {
  if (findSameFlightIndex(p_flight)) {
    return false;
  } else {
    return true;
  }
}

bool Flights::isRouteIncluded(Route p_route){
    bool ans = false;
    for (int i = 0; i < flightVector.size(); i++){
        if (flightVector.at(i).isSameRoute(p_route)){
            ans = true;
            break;
        }
    }
    return ans;
}

bool Flights::isPlaneIncluded(Plane p_plane){
    bool ans = false;
    for (int i = 0; i < flightVector.size(); i++){
        if (flightVector.at(i).isSamePlane(p_plane)){
            ans = true;
            break;
        }
    }
    return ans;
}

void Flights::add(Flight &p_flight) {
  flightVector.push_back(p_flight);
}

// index starts from 0
// e.g. Flights::remove(0) removes the first element
void Flights::remove(int index){
  flightVector.erase(flightVector.begin() + index);
}

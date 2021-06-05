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

  int findSameFlightIndex(Flight p_flight);

  void add(Flight &p_flight);
  void remove(int index);
};

/* Flights class */

std::vector<Flight> Flights::hardcopyVector() {
  std::vector<Flight> new_flightVector(flightVector);
  return new_flightVector;
}

// int Flights::findSameFlightIndex(Flight p_flight) {
//   int ans = -1;
//   for (int i = 0; i < flightVector.size(); i++) {
//   }
// }

void Flights::add(Flight &p_flight) {
  flightVector.push_back(p_flight);
}

// index starts from 0
// e.g. Flights::remove(0) removes the first element
void Flights::remove(int index){
  flightVector.erase(flightVector.begin() + index);
}

#pragma once

#include <vector>
#include "../BasicDataClass/Airport.h"

class Airports
{
friend class DataOp;

private:
  std::vector<Airport> APVector;  // airportVector

public:
  Airports() {}

  bool isSameAPIncluded(Airport p_AP);
  int findSameAPIndex(Airport p_AP);

  void add(Airport &p_airport);
  void remove(int index);
};


/* Airports class */

// Check if APVector includes the same airport as the given p_AP.
bool Airports::isSameAPIncluded(Airport p_AP) {
  bool ans = false;
  for (int i = 0; i < APVector.size(); i++) {
    if (APVector.at(i).isSameAirport(p_AP)) {
      ans = true;
      break;
    }
  }
  return ans;
}

int Airports::findSameAPIndex(Airport p_AP) {
  int ans = -1;
  for (int i = 0; i < APVector.size(); i++) {
    if (APVector.at(i).isSameAirport(p_AP)) {
      ans = i;
      break;
    }
  }
  return ans;
}


void Airports::add(Airport &p_airport) {
  APVector.push_back(p_airport);
}

// index starts from 0
// e.g. Airports::remove(0) removes the first element
void Airports::remove(int index) {
  APVector.erase(APVector.begin() + index);
}

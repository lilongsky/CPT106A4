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

  std::vector<Airport> hardcopyVector();

  int findSameAPIndex(Airport p_AP);
  bool isSameAPIncluded(Airport p_AP);

  std::vector<Airport> search(std::string APName);

  void add(Airport &p_airport);
  void remove(int index);
};

/* Airports class */

std::vector<Airport> Airports::hardcopyVector() {
  std::vector<Airport> new_APVector(APVector);
  return new_APVector;
}

// Find the index of the included same airport as the given airport p_AP.
// Return -1 if p_AP is not included.
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
// Check if APVector includes the same airport as the given airport p_AP.
bool Airports::isSameAPIncluded(Airport p_AP) {
  if (findSameAPIndex(p_AP) == -1) {
    return false;
  } else {
    return true;
  }
}

inline std::vector<Airport> Airports::search(std::string APName){
    std::vector<Airport> ansAirport;
    for (int i = 0; i < APVector.size(); i++){
        if ((APName == APVector.at(i).airportName)||(APName == "NULL")){
            ansAirport.push_back(APVector.at(i));
        }
    }
    return ansAirport;
}

// ? new or not new
void Airports::add(Airport &p_airport) {
  APVector.push_back(p_airport);
}

// index starts from 0
// e.g. Airports::remove(0) removes the first element
void Airports::remove(int index) {
  APVector.erase(APVector.begin() + index);
}

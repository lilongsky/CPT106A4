#include <vector>
#include "Airport.h"

class Airports
{
friend class DataOp;

private:
  // airportVector
  std::vector<Airport> APVector;

public:
  Airports() {}

  bool isAPNameExistent(std::string p_APName);

  void add(Airport& p_airport);
  void remove(int index);
};

/* Airports class */

// Check if APVector includes the airport with name p_APName.
bool Airports::isAPNameExistent(std::string p_APName) {
  bool ans = false;
  for (int i = 0; i < APVector.size(); i++) {
    if (APVector.at(i).name == p_APName) {
      ans = true;
      break;
    }
  }
  return ans;
}

void Airports::add(Airport& p_airport) {
  APVector.push_back(p_airport);
}
// index starts from 0
// e.g. Airports::remove(0) removes the first element
void Airports::remove(int index) {
  APVector.erase(APVector.begin() + index);
}

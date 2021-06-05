#pragma once
#include <iostream>

class Airport
{
friend class Airports;

private:
	std::string airportName;

public:
  Airport();
	Airport(std::string p_airportName);

  void hardcopy(Airport p_airport);

	std::string getAirportName();

  bool isSameAirport(Airport p_AP);
};

/* Airport class */

Airport::Airport() {}
Airport::Airport(std::string p_airportName) {
	this->airportName = p_airportName;
}

void Airport::hardcopy(Airport p_airport) {
  this->airportName = p_airport.airportName;
}

std::string Airport::getAirportName() {
	return this->airportName;
}

bool Airport::isSameAirport(Airport p_AP) {
	bool ans = (airportName == p_AP.airportName);
	return ans;
}

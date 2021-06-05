#pragma once
#include <iostream>

class Airport
{
friend class Airports;

private:
	std::string airportName;

public:
	Airport(std::string p_airportName);

	void setAirportName(std::string p_airportName);

	std::string getAirportName();

  bool isSameAirport(Airport p_AP);
};

/* Airport class */

Airport::Airport(std::string p_airportName) {
	this->airportName = p_airportName;
}

void Airport::setAirportName(std::string p_airportName) {
	this->airportName = p_airportName;
}

std::string Airport::getAirportName() {
	return this->airportName;
}

bool Airport::isSameAirport(Airport p_AP) {
	bool ans = (airportName == p_AP.airportName);
	return ans;
}

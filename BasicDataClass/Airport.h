#pragma once
#include <iostream>

class Airport
{
friend class Airports;

private:
	std::string airportName;

public:
	Airport(std::string p_airportName);

	void setAirport(std::string p_airportName);

	std::string getAirport();

  bool isSameAP(Airport p_AP);
};

/* Airport class */

Airport::Airport(std::string p_airportName) {
	this->airportName = p_airportName;
}

void Airport::setAirport(std::string p_airportName) {
	this->airportName = p_airportName;
}

std::string Airport::getAirport() {
	return this->airportName;
}

bool Airport::isSameAP(Airport p_AP) {
	bool ans = (airportName == p_AP.airportName);
	return ans;
}

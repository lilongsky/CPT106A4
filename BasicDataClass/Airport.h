#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H


//#include <iostream>

class Airport
{
friend class Airports;

private:
	std::string airportName;

public:
	Airport(std::string p_airportName);

	void setAirport(std::string p_airportName);

	std::string getAirport();
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
#endif // !AIRPORT_H

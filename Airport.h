#pragma once
#include <iostream>

class Airport
{
private:
	std::string name;

public:
	Airport(std::string name);

	void setAirport(std::string name);

	std::string getAirport();
};

/* Airport class */

Airport::Airport(std::string name) {
	this->name = name;
}

void Airport::setAirport(std::string name) {
	this->name = name;
}

std::string Airport::getAirport() {
	return this->name;
}

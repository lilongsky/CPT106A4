#pragma once
#include <iostream>

class Plane
{
private:
	std::string planeID;
	std::string planeType;
	// TODO seat

public:
	Plane(std::string p_ID, std::string p_type);

	std::string getPlaneID();
	std::string getPlaneType();
};

/* Plane class */

Plane::Plane(std::string p_ID, std::string p_type) {
	planeID = p_ID;
	planeType = p_type;
}

std::string Plane::getPlaneID() {
	return this->planeID;
}
std::string Plane::getPlaneType() {
	return this->planeType;
}

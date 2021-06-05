#pragma once

#include <string>

class Plane
{
	friend class Planes;

private:
	std::string planeID;
	std::string planeType;
	// TODO seat

public:
  Plane() {}
	Plane(std::string p_ID, std::string p_type);

	void hardcopy(Plane p_plane);

	std::string getPlaneID();
	std::string getPlaneType();

	bool isSamePlane(Plane p_plane);
};

/* Plane class */

Plane::Plane(std::string p_ID, std::string p_type) {
	planeID = p_ID;
	planeType = p_type;
}

void Plane::hardcopy(Plane p_plane) {
	this->planeID = p_plane.planeID;
	this->planeType = p_plane.planeType;
}

std::string Plane::getPlaneID() { return this->planeID; }
std::string Plane::getPlaneType() { return this->planeType; }

bool Plane::isSamePlane(Plane p_plane) {
	if ((planeID == p_plane.planeID) && (planeType == p_plane.planeType)) {
		return true;
	} else {
		return false;
	}
}

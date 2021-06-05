#pragma once
#ifndef PLANE_H
#define PLANE_H


class Plane
{
	friend class Planes;
private:
	std::string planeID;
	std::string planeType;
	// TODO seat

public:
	Plane(std::string p_ID, std::string p_type);

	std::string getPlaneID();
	std::string getPlaneType();

	void hardcopy(Plane p_plane);
	bool isSamePlane(Plane p_P);
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

void Plane::hardcopy(Plane p_plane) {
	this->planeID = p_plane.planeID;
	this->planeType = p_plane.planeType;
}

bool Plane::isSamePlane(Plane p_P) {
	bool ans = (planeID == p_P.planeID);
	return ans;
}

#endif //!PLANE_H
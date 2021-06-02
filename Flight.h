#pragma once
#include <iostream>
#include "Plane.h"
#include "Route.h"

class Flight
{
private:
	std::string flightID;
	Plane* planePtr;
	Route* routePtr;
	time_t takeOffTime;
	time_t landingTime;
	int price;

public:
	Flight();

	void setID(std::string);
	void setPlane(Plane);
	void setRoute(Route);
	void setTakeOffPlane(time_t);
	void setLandingTime(time_t);
	void setPrice(int);

	std::string getID();
	Plane getPlanePtr();
	time_t getTakeOffTime();
	time_t getLandingTime();
	Route getRoutePtr();
	int getPrice();
};

/* Flight class */

Flight::Flight() {
	planePtr = nullptr;
	routePtr = nullptr;
}

void Flight::setID(std::string p_ID) {
	flightID = p_ID;
}
void Flight::setPlane(Plane p_plane) {
	planePtr = &p_plane;
}

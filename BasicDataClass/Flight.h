#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H


#include "../BasicDataClass/Plane.h"
#include "../BasicDataClass/Route.h"

class Flight
{
	friend class Filghts;
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
std::string Flight::getID(){
	return this->flightID;
}
Plane Flight::getPlanePtr(){
	return *(this->planePtr);
}
time_t Flight::getTakeOffTime(){
	return this->takeOffTime;
}

time_t Flight::getLandingTime(){
	return this->landingTime;
}

Route Flight::getRoutePtr(){
	return *(this->routePtr);
}

int Flight::getPrice(){
	return this->price;
}
#endif // !FLIGHT_H

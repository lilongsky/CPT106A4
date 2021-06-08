#pragma once

#include <string>
#include "Route.h"
#include "Plane.h"

class Flight
{
	friend class Flights;

private:
	std::string flightID;
	Plane* planePtr;
	Route* routePtr;
	time_t TKOFTime;
	time_t LandTime;
	int price;

public:
	Flight();
  Flight(
    std::string p_flightID,
    Plane &p_plane,
    Route &p_route,
    time_t p_TKOFTime, time_t p_LandTime,
    int p_price
  );

	std::string getFlightID();
	Plane getPlane();
	Route getRoute();
	time_t getTKOFTime();
	time_t getLandTime();
	int getPrice();

	bool isSameFlight(Flight p_flight);
	bool isSameFlightID(std::string p_flightID);
	bool isSamePlane(Plane p_plane);
	bool isSameRoute(Route p_routr);
	bool isSameTKOFTime(time_t p_tkofTime);
	bool isSameLandTime(time_t p_landTime);
	bool isSamePrice(int p_price);
};

/* Flight class */

Flight::Flight() {
	planePtr = nullptr;
	routePtr = nullptr;
}

Flight::Flight(
  std::string p_flightID,
  Plane &p_plane,
  Route &p_route,
  time_t p_TKOFTime, time_t p_LandTime,
  int p_price
) {
  flightID = p_flightID;
  planePtr = &p_plane;
  routePtr = &p_route;
  TKOFTime = p_TKOFTime;
  LandTime = p_LandTime;
  price = p_price;
}

std::string Flight::getFlightID() { return this->flightID; }
Plane Flight::getPlane() { return *planePtr; }
time_t Flight::getTKOFTime() { return this->TKOFTime; }
time_t Flight::getLandTime() { return this->LandTime; }
Route Flight::getRoute() { return *routePtr; }
int Flight::getPrice() { return this->price; }

bool Flight::isSameFlight(Flight p_flight) {
	if ((flightID == p_flight.flightID)
		&& (planePtr->isSamePlane(*(p_flight.planePtr)))
		&& (routePtr->isSameRoute(*(p_flight.routePtr)))
		&& (TKOFTime == p_flight.TKOFTime)
		&& (LandTime == p_flight.LandTime)
		&& (price == p_flight.price)) {
		return true;
	}
	else {
		return false;
	}
}

bool Flight::isSameFlightID(std::string p_flightID) {
	if (flightID == p_flightID)
		return true;
	else
		return false;
}

bool Flight::isSamePlane(Plane p_plane) {
	if (planePtr->isSamePlane(p_plane))
		return true;
	else
		return false;
}

bool Flight::isSameRoute(Route p_route) {
	if (routePtr->isSameRoute(p_route))
		return true;
	else
		return false;
}

bool Flight::isSameTKOFTime(time_t p_tkofTime) {
	if (TKOFTime == p_tkofTime)
		return true;
	else
		return false;
}

bool Flight::isSameLandTime(time_t p_landTime) {
	if (LandTime == p_landTime)
		return true;
	else
		return false;
}

bool Flight::isSamePrice(int p_price) {
	if (price == p_price)
		return true;
	else
		return false;
}
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

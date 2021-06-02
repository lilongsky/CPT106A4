#pragma once
#include"Plane.h"
#include"Route.h"
class Flight
{
private:
	std::string ID;
	Plane* plane_ptr;
	time_t takeOffTime;
	time_t landingTime;
	Route* route_ptr;
	int price;
public:
	Flight(std::string p_ID, Plane* p_PlanePtr, time_t p_TakeOffTime, time_t p_landingTime, Route* p_RoutePtr, int p_price);
	void setID(std::string);
	void setPlane(Plane*);
	void setTakeOffPlane(time_t);
	void setLandingTime(time_t);
	void setRoute(Route*);
	void setPrice(int);
	std::string getID();
	Plane* getPlanePtr();
	time_t getTakeOffTime();
	time_t getLandingTime();
	Route* getRoutePtr();
	int getPrice();
};
Flight::Flight(std::string p_ID, Plane* p_PlanePtr, time_t p_TakeOffTime, time_t p_landingTime,Route* p_RoutePtr,int p_price) {
	ID = p_ID;
	plane_ptr = p_PlanePtr;
	takeOffTime = p_TakeOffTime;
	landingTime = p_landingTime;
	route_ptr = p_RoutePtr;
	price = p_price;
}



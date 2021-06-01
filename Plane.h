#pragma once
#include<iostream>
class Plane
{
private:
	std::string planeID;
	std::string planeType;
	int seat;
public:
	Plane(std::string, std::string, int);
	void setPlaneID(std::string);
	void setPlaneType(std::string);
	void setSeat(int);
	std::string getPlaneID();
	std::string getPlaneType();
	/*char[][] getSeat();*/
};
Plane::Plane(std::string p_planeID, std::string p_planeType, int p_seat) {
	planeID = p_planeID;
	planeType = p_planeType;
	seat = p_seat;
}
void Plane::setPlaneID(std::string p_planeID) {
	this->planeID = p_planeID;
}
void Plane::setPlaneType(std::string p_planeTypr) {
	this->planeType = p_planeTypr;
}
void Plane::setSeat(int p_seat) {
	this->seat = p_seat;
}
std::string Plane::getPlaneID() {
	return this->planeID;
}
std::string Plane::getPlaneType() {
	return this->planeType;
}

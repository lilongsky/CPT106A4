#pragma once
#ifndef PLANES_H
#define PLANES_H


//#include <vector>
#include"../BasicDataClass/Plane.h"
class Planes{
	friend class DataOp;
private:
	std::vector<Plane> PVector;
public:
	Planes(){}

	bool isPNameExistent(std::string p_PName);

	void add(Plane p_airport);
	void remove(int index);
};

bool Planes::isPNameExistent(std::string p_PName){
	bool ans = false;
	for (int i = 0; i < PVector.size(); i++){
		if (PVector.at(i).planeID == p_PName){
			ans = true;
			break;
		}
	}
	return ans;
}
void Planes::add(Plane p_plane){
	PVector.push_back(p_plane);
}
void Planes::remove(int index){
	PVector.erase(PVector.begin() + index);
}
#endif // !PLANES_H
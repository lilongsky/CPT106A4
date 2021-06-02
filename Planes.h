#pragma once
#include <vector>
#include"Plane.h"
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
inline void Planes::add(Plane p_plane){
	PVector.push_back(p_plane);
}
inline void Planes::remove(int index){
	PVector.erase(PVector.begin() + index);
}
#pragma once

#include <vector>
#include "../BasicDataClass/Plane.h"

class Planes
{
	friend class DataOp;

private:
	std::vector<Plane> planeVector;

public:
	Planes() {}

  std::vector<Plane> hardcopyVector();

  bool isNewIDValid(std::string newID);
  int findSamePlaneIndex(Plane p_plane);
  bool isSamePlaneIncluded(Plane p_plane);

  std::vector<Plane> search(std::string planeID);
  std::vector<Plane> search(std::string planeID, std::string planeType);

	void add(Plane &p_airport);
	void remove(int index);
};

/* Planes class */

std::vector<Plane> Planes::hardcopyVector() {
  std::vector<Plane> new_routeVector(planeVector);
  return new_routeVector;
}

bool Planes::isNewIDValid(std::string newID) {
  bool ans = true;
  for (int i = 0; i < planeVector.size(); i++) {
    if (planeVector.at(i).planeID == newID) {
      ans = false;
      break;
    }
  }
  return ans;
}
int Planes::findSamePlaneIndex(Plane p_plane) {
  int ans = -1;
  for (int i = 0; i < planeVector.size(); i++) {
    if (planeVector.at(i).isSamePlane(p_plane)) {
      ans = i;
      break;
    }
  }
  return ans;
}
bool Planes::isSamePlaneIncluded(Plane p_plane) {
  if (findSamePlaneIndex(p_plane) == -1) {
    return false;
  } else {
    return true;
  }
}

inline std::vector<Plane> Planes::search(std::string planeID){
    std::vector<Plane> ansPlane;
    for (int i = 0; i < planeVector.size(); i++){
        if (planeID == planeVector.at(i).getPlaneID()){
            ansPlane.push_back(planeVector.at(i));
        }
    }
    return  ansPlane;
}

inline std::vector<Plane> Planes::search(std::string planeID, std::string planeType){
    std::vector<Plane> ansPlane;
    for (int i = 0; i < planeVector.size(); i++){
        if (((planeID == planeVector.at(i).planeID)||(planeID == "NULL"))
            &&((planeType == planeVector.at(i).planeType)||(planeType == "NULL")))
        {
            ansPlane.push_back(planeVector.at(i));
        }
    }
    return  ansPlane;
}

void Planes::add(Plane &p_plane) {
	planeVector.push_back(p_plane);
}
void Planes::remove(int index) {
	planeVector.erase(planeVector.begin() + index);
}

#pragma once

#include <vector>
#include "../BasicDataClass/Route.h"

class Routes
{
friend class DataOp;

private:
  std::vector<Route> routeVector; // RouteVector

public:
  Routes() {}

  std::vector<Route> hardcopyVector();

  bool isSameAPIncluded(Airport p_AP);
  int findSameRouteIndex(Route p_route);
  bool isRouteIncluded(Route p_route);

  std::vector<Route> search(std::string TKOF_AP_Name, std::string DEST_AP_Name);
  std::vector<Route> search(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration);

  void add(Route &p_route);
  void remove(int index);
};

/* Routes class */

std::vector<Route> Routes::hardcopyVector() {
  std::vector<Route> new_routeVector(routeVector);
  return new_routeVector;
}

bool Routes::isSameAPIncluded(Airport p_AP) {
	bool ans = false;
	for (int i = 0; i < routeVector.size(); i++) {
		if (routeVector.at(i).isSameAPIncluded(p_AP)) {
			ans = true;
			break;
		}
	}
	return ans;
}
// Find the index of the included same route as the given p_route.
// Return -1 if p_route is not included.
int Routes::findSameRouteIndex(Route p_route) {
  int ans = -1;
  for (int i = 0; i < routeVector.size(); i++) {
    if (routeVector.at(i).isSameRoute(p_route)) {
      ans = i;
      break;
    }
  }
  return ans;
}
// Check if the same route as the given p_route is included.
bool Routes::isRouteIncluded(Route p_route) {
  if (findSameRouteIndex(p_route) == -1) {
    return false;
  } else {
    return true;
  }
}

inline std::vector<Route> Routes::search(std::string TKOF_AP_Name, std::string DEST_AP_Name){
	std::vector<Route> ansRoute;
	for (int i = 0; i < routeVector.size(); i++){
		if ((TKOF_AP_Name == routeVector.at(i).getTKOF_AP().getAirportName())
			&&(DEST_AP_Name == routeVector.at(i).getDEST_AP().getAirportName())){
			ansRoute.push_back(routeVector.at(i));
		}
	}
	return ansRoute;
}

inline std::vector<Route> Routes::search(std::string TKOF_AP_Name, std::string DEST_AP_Name, double duration){
	std::vector<Route> ansRoute;
	for (int i = 0; i < routeVector.size(); i++){
		if ((TKOF_AP_Name == routeVector.at(i).getTKOF_AP().getAirportName()||(TKOF_AP_Name == "NULL"))
			&& (DEST_AP_Name == routeVector.at(i).getDEST_AP().getAirportName())||(DEST_AP_Name == "NULL")
			&&((duration == routeVector.at(i).getDuration())||duration == -2.0))
		{
			ansRoute.push_back(routeVector.at(i));
		}
	}
	return ansRoute;
}

void Routes::add(Route &p_route) {
  routeVector.push_back(p_route);
}
// index starts from 0
// e.g. Routes::remove(0) removes the first element
void Routes::remove(int index) {
  routeVector.erase(routeVector.begin() + index);
}

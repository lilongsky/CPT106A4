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

  bool isSameAPIncluded(Airport p_AP);
  int findSameRouteIndex(Route p_route);
  bool isRouteIncluded(Route p_route);

  void add(Route p_route);
  void remove(int index);
};

/* Routes class */

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

void Routes::add(Route p_route) {
  Route newRoute;
  newRoute.hardcopy(p_route);
  routeVector.push_back(newRoute);
}
// index starts from 0
// e.g. Routes::remove(0) removes the first element
void Routes::remove(int index) {
  routeVector.erase(routeVector.begin() + index);
}

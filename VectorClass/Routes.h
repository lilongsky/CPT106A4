#pragma once
#include "../BasicDataClass/Route.h"

class Routes
{
  friend class DataOp;

private:
  // RouteVector
  std::vector<Route> routeVector;

public:
  Routes() {}

  bool isSameAPIncluded(Airport p_AP);

  void add(Route &p_route);
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

void Routes::add(Route &p_route) {
  routeVector.push_back(p_route);
}
// index starts from 0
// e.g. Routes::remove(0) removes the first element
void Routes::remove(int index) {
  routeVector.erase(routeVector.begin() + index);
}

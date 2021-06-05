#pragma once

#include "Airport.h"

class Route
{
	friend class Routes;
private:
	Airport* TKOF_AP_Ptr;
	Airport* DEST_AP_Ptr;
	double duration; // second(s)

public:
	Route();
	Route(Airport &p_TKOF_AP, Airport &p_DEST_AP, double p_duration);

  void hardcopy(Route p_route);

	Airport getTKOF_AP();
	Airport getDEST_AP();
	double getDuration();

  bool isSameAPIncluded(Airport p_AP);
  bool isSameRoute(Route p_route);
};

/* Route class */

Route::Route() {
	TKOF_AP_Ptr = nullptr;
	DEST_AP_Ptr = nullptr;
	duration = -1.0;
}
Route::Route(Airport &p_TKOF_AP, Airport &p_DEST_AP, double p_duration) {
	TKOF_AP_Ptr = &p_TKOF_AP;
	DEST_AP_Ptr = &p_DEST_AP;
	duration = p_duration;
}

void Route::hardcopy(Route p_route) {
  this->TKOF_AP_Ptr = p_route.TKOF_AP_Ptr;
  this->DEST_AP_Ptr = p_route.DEST_AP_Ptr;
  this->duration = p_route.duration;
}

Airport Route::getTKOF_AP() {
	return *TKOF_AP_Ptr;
}
Airport Route::getDEST_AP() {
	return *DEST_AP_Ptr;
}
double Route::getDuration() {
	return duration;
}

bool Route::isSameAPIncluded(Airport p_AP) {
	if (TKOF_AP_Ptr->isSameAirport(p_AP)
      || DEST_AP_Ptr->isSameAirport(p_AP)) {
    return true;
  } else {
    return false;
  }
}
bool Route::isSameRoute(Route p_route) {
  if (TKOF_AP_Ptr->isSameAirport(*(p_route.TKOF_AP_Ptr))
      && DEST_AP_Ptr->isSameAirport(*(p_route.DEST_AP_Ptr))) {
    return true;
  } else {
    return false;
  }
}

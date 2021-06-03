#pragma once
#include "Airport.h"

class Route
{
	friend class Routes;
private:
	Airport* DEP_AP_Ptr;
	Airport* DEST_AP_Ptr;
	int duration; // store in minus

public:
	Route();
	Route(Airport p_DEP_AP, Airport p_DEST_AP, int p_duration);

	Airport getDEP_AP();
	Airport getDEST_AP();
	int getDuration();
};

/* Route class */

Route::Route() {
	DEP_AP_Ptr = nullptr;
	DEST_AP_Ptr = nullptr;
	duration = 0;
}
Route::Route(Airport p_DEP_AP, Airport p_DEST_AP, int p_duration) {
	DEP_AP_Ptr = &p_DEP_AP;
	DEST_AP_Ptr = &p_DEST_AP;
	duration = p_duration;
}

Airport Route::getDEP_AP() {
	return *DEP_AP_Ptr;
}
Airport Route::getDEST_AP() {
	return *DEST_AP_Ptr;
}
int Route::getDuration() {
	return duration;
}

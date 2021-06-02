#pragma once
#include "Airport.h"
#include <time.h>

class Route
{
	friend class Routes;
private:
	Airport* DEP_AP_Ptr;
	Airport* DEST_AP_Ptr;
	time_t duration;

public:
	Route();
	Route(Airport p_DEP_AP, Airport p_DEST_AP, time_t p_duration);

	Airport getDEP_AP();
	Airport getDEST_AP();
	time_t getDuration();
};

/* Route class */

Route::Route() {
	DEP_AP_Ptr = nullptr;
	DEST_AP_Ptr = nullptr;
	duration = 0;
}
Route::Route(Airport p_DEP_AP, Airport p_DEST_AP, time_t p_duration) {
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
time_t Route::getDuration() {
	return duration;
}

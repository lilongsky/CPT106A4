#pragma once
#include"Airport.h"
#include <time.h>
class Route
{
private:
	Airport* source;
	Airport* destination;
	time_t durition;
public:
	Route(Airport, Airport, time_t);
	void setSource(Airport);
	void setDestination(Airport);
	void setDuretion(time_t);
	Airport* getSourcePtr();
	Airport* getDestinationPtr();
	time_t getDurition();
};
Route::Route(Airport src, Airport dest, time_t duri)
{
	source = &src;
	destination = &dest;
	durition = duri;
}
void Route:: setSource(Airport src) {
	this->source = &src;
}
void Route::setDestination(Airport dest) {
	this->destination = &dest;
}
void Route::setDuretion(time_t duri){
	this->durition = duri;
}
Airport* Route::getSourcePtr() {
	return source;
}
Airport* Route::getDestinationPtr() {
	return destination;
}
time_t Route::getDurition() {
	return durition;
}




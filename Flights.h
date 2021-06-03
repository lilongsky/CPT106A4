#pragma once
#include"Flight.h"
class Flights{
	friend class DataOp;
private:
    // flightVector
    std::vector<Flight> FVector;

public:
    Flights(){}

    bool isFNameExistent(std::string p_FName);

    void add(Flight& p_Flight);
    void remove(int index);

};

/* Flights class */

// Check if FVector includes the airport with name P_Fid.
bool Flights::isFNameExistent(std::string p_Fid){
    bool ans = false;
    for (int i = 0; i < FVector.size(); i++){
        if (FVector.at(i).getID() == p_Fid){
            ans = true;
            break;
        }
    }
    return ans;
}

void Flights::add(Flight & p_Flight){
    //if (p_Flight.getTakeOffTime()> p_Flight.getLandingTime())	{
    //    throw "LandingTimeError";
    //}
    FVector.push_back(p_Flight);
}
// index starts from 0
// e.g. Flights::remove(0) removes the first element
void Flights::remove(int index){
    FVector.erase(FVector.begin() + index);
}




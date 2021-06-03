#pragma once
#include"Route.h"
class Routes{
	friend class DataOp;
private:
    // RouteVector
    std::vector<Route> RVector;

public:
    Routes(){}

   /* bool isRNameExistent(std::string p_APName);*/

    void add(Route& p_airport);
    void remove(int index);
};

/* Airports class */

// Check if RVector includes the airport with name p_APName.
//bool Routes::isRPNameExistent(std::string p_APName){
//    bool ans = false;
//    for (int i = 0; i < RVector.size(); i++){
//        if (RVector.at(i).name == p_APName){
//            ans = true;
//            break;
//        }
//    }
//    return ans;
//}

void Routes::add(Route& p_route){
    RVector.push_back(p_route);
}
// index starts from 0
// e.g. Routes::remove(0) removes the first element
void Routes::remove(int index){
    RVector.erase(RVector.begin() + index);
}


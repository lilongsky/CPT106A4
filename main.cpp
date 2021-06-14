#include <iostream>
#include "Submain.h"
using namespace std;

int main()
{
	// 1 Initialize
	Users users;
	Airports airports;
	Routes routes;
	Planes planes;
	Flights flights;
	Tickets tickets;
	DataOp dataOp(users, airports, routes, planes, flights, tickets);
	FileOp fileOp(dataOp);
	fileOp.readUsersFromFile();
	fileOp.readAirportsFromFile();
	fileOp.readRoutesFromFile();
	fileOp.readPlanesFromFIle();
	fileOp.readFlightsFromFIle();
	fileOp.readTicketsFromFile();
	Business basicBusiness(dataOp, fileOp);
	Submain submain(basicBusiness);

	User currentUser;
	bool isOver;

	cout << "Welcome to Airways Management System!" << endl;
	isOver = false;
	string currentUserID;
	while (!isOver) {
		cout << "Please input your user ID:" << endl;
		currentUserID = readString();
		if (dataOp.searchUser(currentUserID).size() != 1) {
			cout << "Your input is not valid. Please try again." << endl;
		} else {
			currentUser = dataOp.searchUser(currentUserID).at(0);
			cout << "Welcome " << currentUser.getUserRole() << " " << currentUser.getUserName() << "!" << endl;
			isOver = true;
		}
	}
	system("pause");
	system("cls");

	cout << "Please input the current time:" << endl;
	submain.currentTime = readTime(2);
	system("pause");
	system("cls");

	submain.currentUserPtr = &currentUser;
	if (currentUser.getUserRole() == "admin") {
		submain.admin();
	} else if (currentUser.getUserRole() == "manager") {
		submain.manager();
	} else if (currentUser.getUserRole() == "ticket_agent") {
		submain.TA();
	} else if (currentUser.getUserRole() == "customer") {
		submain.customer();
	} else {
		throw(logic_error(""));
	}

	return 0;
}

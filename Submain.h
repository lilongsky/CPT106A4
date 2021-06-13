#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Business.h"

const int INT_NO_LIMIT = -2;
const string STR_NO_LIMIT = "NULL";

class Submain
{
  friend int main();

private:
  time_t currentTime;
  User* currentUserPtr;
  Business* businessPtr;

public:
  Submain(Business &business);

  void admin();
  void TA();
  void manager();
  void customer();
};

/* external function */

int readInt() {
  int n;
  cin >> n;
  return n;
}

string readString() {
  string str;
  cin >> str;
  return str;
}

void showTime(time_t p_time) {
  struct tm temp_tm;
  gmtime_s(&temp_tm, &p_time);
  char outstr[24];
  strftime(outstr, 24, "GMT %Y/%m/%d %X", &temp_tm);
  cout << outstr;
}

/* Submain class */

Submain::Submain(Business &business) {
  currentUserPtr = nullptr;
  businessPtr = &business;
}

void Submain::admin() {
  bool isOver = false;

  while (!isOver) {
    cout << "Welcome Administrator " << currentUserPtr->getUserName() << "!" << endl;
    cout << "0 Quit." << endl;
    cout << "1 Show users." << endl;
    cout << "2 Add a user." << endl;
    cout << "3 Delete a user." << endl;
    cout << "4 Show airports." << endl;
    cout << "5 Add an airport." << endl;
    cout << "6 Delete an airport." << endl;
    cout << "7 Show routes." << endl;
    cout << "8 Add a route." << endl;
    cout << "9 Delete a route." << endl;
    cout << "10 Show planes." << endl;
    cout << "11 Add a plane." << endl;
    cout << "12 Delete a plane." << endl;
    cout << "13 Show flights." << endl;
    cout << "14 Add a flight." << endl;
    cout << "15 Delete a flight." << endl;
    cout << "16 Show tickets." << endl;
    cout << "17 Add a ticket." << endl;
    cout << "18 Delete a ticket." << endl;

    cout << "Please input your choice:" << endl;
    int choice = readInt();

    string str1, str2, str3;
    int n1;
    switch (choice) {
    case 0:
      cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
      system("@type Users.txt");
      cout << endl;
      break;

    case 2:
      cout << "Please input the new user by its ID, real name, role:" << endl;
      str1 = readString();
      str2 = readString();
      str3 = readString();
      try {
        businessPtr->addNewUser(str1, str2, str3);
      } catch (logic_error err) {
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 3:
      cout << "Please input the ID of the user you want to delete:" << endl;
      str1 = readString();   // user ID
      if (str1 == currentUserPtr->getUserID()) {
        cout << "You cannot delete yourself ..." << endl;
        break;
      }

       try {
         businessPtr->deleteUser(str1);
       } catch (logic_error err) {
         cout << "Sorry, this is not a valid operation." << endl;
       }
      break;

    case 4:
      system("@type Airports.txt");
      cout << endl;
      break;

    case 5:
      cout << "Please input the name of the new airport:" << endl;
      str1 = readString();
      try {
        businessPtr->addNewAirport(str1);
      } catch (logic_error err) {
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 6:
      cout << "Please input the airport you want to delete by its name:" << endl;
      str1 = readString();
      try {
        businessPtr->deleteAirport(str1);
      } catch (logic_error err) {
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 7:
      system("@type Routes.txt");
      cout << endl;
      break;

    case 8:
        cout << "Please input the new route by its source and destination airports:" << endl;
        str1 = readString(); // TKOF_AP_name
        str2 = readString(); // land_AP_name
        n1 = readInt(); // duration
        try {
            businessPtr->addNewRoute(str1, str2, n1);
        } catch (logic_error err) {
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;

    case 9:
        cout << "Please input the route you want to delete by its source and destination airports:" << endl;
        str1 = readString(); // TKOF_AP_name
        str2 = readString(); // land_AP_name
        try {
          businessPtr->deleteRoute(str1, str2);
        } catch (logic_error err) {
          cout << "Sorry, this is not a valid operation." << endl;
        }

    case 10:
      system("@type Planes.txt");
      cout << endl;
      break;

    case 11:
        cout << "Please input the new plane by its ID and type:" << endl;
        str1 = readString(); // plane ID
        str2 = readString(); // plane type
        try {
            businessPtr->addNewPlane(str1, str2);
        } catch (logic_error err) {
            cout << "Sorry, this is not a valid operation." << endl;
        }

    case 12:
        cout << "Please input the ID of the plane you want to delete:" << endl;
        str1 = readString();
        try {
            businessPtr->deletePlane(str1);
        }
        catch (logic_error err) {
            cout << "Sorry, this is not a valid operation." << endl;
        }

    case 13:
      system("@type Flights.txt");
      cout << endl;
      break;

    case 14:
        cout << "Please input the plane ID of the new flight:" << endl;
        str1 = readString(); // plane ID
        cout << "Please input the names of source and destination airport of this flight:" << endl;
        str2 = readString(); // 
        str3 = readString();
        try {
            // businessPtr->creatNewFlight();
        }
        catch (logic_error err) {

        }

    case 16:
      system("@type Tickets.txt");
      cout << endl;
      break;

    default:
      cout << "Your choice is not valid. Please try again!" << endl;
      break;
    }

    system("pause");
    system("cls");
  }
}

void Submain::TA() {}

void Submain::manager() {}

void Submain::customer() {
  bool isOver = false;
  vector<Ticket> ticketVector;
  int size = 0;
  while(!isOver) {
    cout << "Welcome Customer " << currentUserPtr->getUserName() << "!" << endl;
    cout << "0 Quit." << endl;
    cout << "1 Show My Tickets." << endl;

    cout << "Please input your choice:" << endl;
    int choice = readInt();

    switch (choice)
    {
    case 0:
      cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
      ticketVector = businessPtr->searchTicket(
        STR_NO_LIMIT,
        currentUserPtr->getUserID(),
        STR_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        STR_NO_LIMIT,
        currentTime
      );

      size = ticketVector.size();
      time_t temp_time_t;

      if (size == 0) {
        cout << "You have no tickets." << endl;
      } else if (size == 1) {
        cout << "You have 1 ticket:" << endl;

        Ticket ticket = ticketVector.at(0);

        cout << ticket.getTicketID() << endl;

        showTime(ticket.getFlight().getTKOFTime());
        cout << " TKOF " << ticket.getFlight().getRoute().getTKOF_AP().getAirportName() << endl;

        showTime(ticket.getFlight().getLandTime());
        cout << " DEST " << ticket.getFlight().getRoute().getDEST_AP().getAirportName() << endl;

        cout << "Seat Location: Row " << ticket.getSeatRow() << " Col " << ticket.getSeatCol() << endl;
      } else {
        cout << "You have " << size << " tickets:" << endl;

        Ticket ticket;
        for (int i = 0; i < size; i++) {
          ticket = ticketVector.at(i);

          cout << i << endl;

          cout << " " << ticket.getTicketID() << endl;

          showTime(ticket.getFlight().getTKOFTime());
          cout << " TKOF " << ticket.getFlight().getRoute().getTKOF_AP().getAirportName() << endl;

          showTime(ticket.getFlight().getLandTime());
          cout << " DEST " << ticket.getFlight().getRoute().getDEST_AP().getAirportName() << endl;

          cout << "Seat Location: Row " << ticket.getSeatRow() << " Col " << ticket.getSeatCol() << endl;
        }
      }
      break;

    default:
      cout << "Your choice is not valid. Please try again!" << endl;
      break;
    }

    system("pause");
    system("cls");
  }
}

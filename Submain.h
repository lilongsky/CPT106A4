#include <iostream>
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
    cout << "4 Show airports." << endl;
    cout << "7 Show routes." << endl;
    cout << "10 Show planes." << endl;
    cout << "13 Show flights." << endl;
    cout << "16 Show tickets." << endl;

    cout << "Please input your choice:" << endl;
    int choice = readInt();

    switch (choice) {
    case 0:
      cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
      system("@type Users.txt");
      cout << endl;
      break;

    case 4:
      cout << "airport_name" << endl;
      system("@type Airports.txt");
      cout << endl;
      break;

    case 7:
      system("@type Routes.txt");
      cout << endl;
      break;

    case 10:
      system("@type Planes.txt");
      cout << endl;
      break;

    case 13:
      system("@type Flights.txt");
      cout << endl;
      break;

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

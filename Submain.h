#include <iostream>
#include <ctime>
using namespace std;
#include "Business.h"

const int INT_NO_LIMIT = -2;
const string STR_NO_LIMIT = "NULL";

class Submain
{
private:
  time_t currentTime;
  User* currentUser;
  Business* businessPtr;

public:
  Submain(time_t currentTime, Business &business);

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
  struct tm* temp_tm;
  temp_tm = gmtime(&p_time);
  char outstr[20];
  strftime(outstr, 20, "GMT %Y/%m/%d %X", temp_tm);
  cout << outstr;
}

/* Submain class */

Submain::Submain(time_t currentTime, Business &business) {
  this->currentTime = currentTime;
  businessPtr = &business;
}

void Submain::customer() {
  bool isOver = false;
  vector<Ticket> ticketVector;
  while(!isOver) {
    cout << "Welcome Customer " << currentUser->getUserName() << "!" << endl;
    cout << "0 Quit." << endl;
    cout << "1 Show My Tickets." << endl;

    cout << "Please input your choice:" << endl;
    int choice = readInt();

    switch (choice)
    {
    case 0:
      cout << "Bye Bye, " << currentUser->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
      ticketVector = businessPtr->searchTicket(
        STR_NO_LIMIT,
        currentUser->getUserID(),
        STR_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        INT_NO_LIMIT,
        STR_NO_LIMIT,
        currentTime
      );

      int size = ticketVector.size();
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

    system("pause");
    system("cls");
    }
  }
}

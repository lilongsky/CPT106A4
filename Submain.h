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
  User *currentUserPtr;
  Business *businessPtr;

public:
  Submain(Business &business);

  void admin();
  void TA();
  void manager();
  void customer();
};

/* external function */

int readInt()
{
  int n;
  cin >> n;
  return n;
}

string readString()
{
  string str;
  cin >> str;
  return str;
}

time_t readTime(int mode) {
  bool isInputOver = false;
  time_t ansTime;
  int year, month;
  struct tm temp_tm{};
  while (!isInputOver) {   
    if (mode == 1){
        cout << endl << "Please input year: ";
        cin >> year;
        if (year == -2){
            return -2;
        }
        temp_tm.tm_year = year - 1900;
        cout << "please input month: ";
        cin >> month;
        temp_tm.tm_mon = month - 1;
        cout << "please input day: ";
        cin >> temp_tm.tm_mday;
        temp_tm.tm_hour = 0;
        temp_tm.tm_min = 0;
        temp_tm.tm_sec = 0;
    }
    else if (mode == 2){
        cout << "Please input year: ";
        cin >> year;
        if (year == -2){
            return -2;
        }
        temp_tm.tm_year = year - 1900;
        cout << "please input month: ";
        cin >> month;
        temp_tm.tm_mon = month - 1;
        cout << "please input day: ";
        cin >> temp_tm.tm_mday;
        cout << "Please input hour: ";
        cin >> temp_tm.tm_hour;
        cout << "Please input minute: ";
        cin >> temp_tm.tm_min;
        temp_tm.tm_sec = 0;
    }
    else{
        throw std::logic_error("");
    }
    cout << "<End of Time Input>" << endl;
    ansTime = mktime(&temp_tm);
    if (ansTime != -1) {
      isInputOver = true;
    }
  }
  
  return ansTime;
}

void showTime(time_t p_time)
{
  struct tm temp_tm;
  localtime_s(&temp_tm, &p_time);
  char outstr[20];
  strftime(outstr, 20, "%Y/%m/%d %X", &temp_tm);
  cout << outstr;
}


/* Submain class */

Submain::Submain(Business &business)
{
  currentUserPtr = nullptr;
  businessPtr = &business;
}

void Submain::admin()
{
  bool isOver = false;

  while (!isOver)
  {
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
    cout << "Please use \"_\" instead of \" \" when trying to input a white space." << endl;

    cout << "Please input your choice:" << endl;
    int choice = readInt();

    string str1, str2, str3;
    int n1, n2 = 0, n3;
    time_t t1, t2;
    switch (choice)
    {
    case 0:
      cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
      system("@type Users.txt");
      cout << endl;
      break;

    case 2:
      cout << "Please input the ID for the new user:" << endl;
      str1 = readString(); // user ID
      cout << "Please input the real name of the new user:" << endl;
      str2 = readString(); // user real name
      cout << "Please input the role of this user in \"admin\", \"ticket_agent\", \"manager\" and \"customer\":" << endl;
      str3 = readString(); // user role
      try
      {
        businessPtr->addNewUser(str1, str2, str3);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 3:
      cout << "Please input the ID of the user you want to delete:" << endl;
      str1 = readString(); // user ID
      if (str1 == currentUserPtr->getUserID())
      {
        cout << "You cannot delete yourself ..." << endl;
        break;
      }

      try
      {
        businessPtr->deleteUser(str1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 4:
      system("@type Airports.txt");
      cout << endl;
      break;

    case 5:
      cout << "Please input the name of the new airport:" << endl;
      str1 = readString(); // airport name
      try
      {
        businessPtr->addNewAirport(str1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 6:
      cout << "Please input the airport you want to delete by its name:" << endl;
      str1 = readString(); // airport name
      try
      {
        businessPtr->deleteAirport(str1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 7:
      system("@type Routes.txt");
      cout << endl;
      break;

    case 8:
      cout << "Please input the new route" << endl;
      cout << "Please input source airport of this route:" << endl;
      str1 = readString(); // TKOF_AP_name
      cout << "Please input destination airport of this route" << endl;
      str2 = readString(); // land_AP_name
      cout << "Please input the fly time in \033[31mSECOND\033[0m of this route:" << endl;
      n1 = readInt();      // duration
      try
      {
        businessPtr->addNewRoute(str1, str2, n1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 9:
      cout << "Please input the name of source airport of the route you want to delete:" << endl;
      str1 = readString(); // TKOF_AP_name
      cout << "Please input the name of destination airport of the route you want to delete:" << endl;
      str2 = readString(); // land_AP_name
      try
      {
        businessPtr->deleteRoute(str1, str2);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 10:
      system("@type Planes.txt");
      cout << endl;
      break;

    case 11:
      cout << "Please input the new planeID it is recommended that it like \"typename-number\":" << endl;
      str1 = readString(); // plane ID
      cout << "Please input the new plane Type name. It should be \"P62 \" or \" P124\"" << endl;
      str2 = readString(); // plane type
      try
      {
        businessPtr->addNewPlane(str1, str2);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 12:
      cout << "Please input the ID of the plane you want to delete:" << endl;
      str1 = readString(); // plane ID
      try
      {
        businessPtr->deletePlane(str1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 13:
      system("@type Flights.txt");
      cout << endl;
      break;

    case 14:
      cout << "Please input the plane ID of the new flight:" << endl;
      str1 = readString(); // plane ID
      cout << "Please input the names of source airport of this flight:" << endl;
      str2 = readString(); // TKOF AP name
      cout << "Please input the name of destination airport of this flight:" << endl;
      str3 = readString(); // land AP name
      cout << "Please input the taking off time of this flight:" << endl;
      t1 = readTime(2); // TKOF time
      cout << "PLease input the landing time of this flight:" << endl;
      t2 = readTime(2); // land time
      cout << "Please input the price of this flight:" << endl;
      n3 = readInt(); // ticket price

      try
      {
        businessPtr->creatNewFlight(str1, str2, str3, t1, t2, n3);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 15:
      cout << "Please input the ID of the flight you want to delete:" << endl;
      str1 = readString();
      try
      {
        businessPtr->deleteFlight(str1);
      }
      catch (logic_error err)
      {
          cout << err.what();
        cout << "Sorry, this is not a valid operation." << endl;
      }
      break;

    case 16:
        cout << "TicketID | CustomerID | FlightID | book time | Pay Time  -2 is not payed | Expiration Time | Ticket Price| Ticket Agent ID | Seat Row | Seat Col" << endl;
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

void Submain::TA()
{
  cout << "Welcome Ticket Agent " << currentUserPtr->getUserName() << "!" << endl;
  bool isOver = false;
  while (!isOver) {
    cout << "0 Quit " << endl;
    cout << "1 search flight with conditions" << endl;
    cout << "2 show seat of a flight" << endl;
    cout << "3 book a ticket" << endl;
    cout << "4 Pay for ticket base on ticketID" << endl;
    cout << "5 pay for ticket base on flightID and seat" << endl;
    cout << "6 refund a ticket base on ticketID" << endl;
    cout << "7 Check selled ticket quantity" << endl;
    cout << "8 show all tickets" << endl;
    cout << "10 Clear Screen." << endl;

    cout << "Please input your choice:" << endl;
    int choice;
    choice = readInt();

    string str1, str2, str3, str4;
    int n1, n2, n3;
    time_t t1, t2;
    vector<Flight> tempFlight;
    switch (choice){
    case 0:
      cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
      isOver = true;
      break;

    case 1:
        cout << "please input flightID, for no limited please input 'NULL'" << endl;
        str1 = readString();
        //cout << "please input planeID, for no limited please input 'NULL'" << endl;
        //str2 = readString();
        cout << "please input source airport, for no limited please input 'NULL'" << endl;
        str3 = readString();
        cout << "please input destination airport, for no limited please input 'NULL'" << endl;
        str4 = readString();
        cout << "please input take of time, for no limited please input '-2'@year" << endl;
        t1 = readTime(2);
        cout << "please input land time, for no limited please input '-2'@year" << endl;
        t2 = readTime(2);
        cout << "please input ticket price, for no limited please input '-2'" << endl;
        n1 = readInt();

        tempFlight = businessPtr->dataOpPtr->searchFlight(str1, STR_NO_LIMIT, str3, str4, t1, t2, n1);
        if (tempFlight.size() == 0){
            cout << "No Flight meet Requirement!" << endl;
        }
        else{
            cout<<endl << "FlightID  " << "PlaneType "
                << "source " << "destination "
                << "take of time " << "land time "
                << "price " << endl;
            for (int i = 0; i < tempFlight.size(); i++){
                cout << tempFlight.at(i).getFlightID() << " | "
                    << tempFlight.at(i).getPlane().getPlaneType() <<" | "
                    << tempFlight.at(i).getRoute().getTKOF_AP().getAirportName() << " | "
                    << tempFlight.at(i).getRoute().getDEST_AP().getAirportName() << " | ";
                showTime(tempFlight.at(i).getTKOFTime());
                cout << " | ";
                showTime(tempFlight.at(i).getLandTime());
                cout << " | ";
                cout << tempFlight.at(i).getPrice();
                cout << endl;
            }
        }
        break;

    case 2:
        cout << "please input flightID to show seats" << endl;
        str1 = readString();
        tempFlight = businessPtr->dataOpPtr->searchFlight(str1);
        tempFlight.at(0).getSeatsPtr()->showSeats();
        break;

    case 3:
        cout << "Please input the customer ID of the new ticket:" << endl;
        str1 = readString();
        cout << "Please input the flight ID for the new ticket:" << endl;
        str2 = readString();
        cout << "Please input the seat will be booked " << endl;
        cout << "please input row you like:";
        n1 = readInt();
        cout << "please input col you like:";
        n2 = readInt();
        try{
            businessPtr->bookTicket(str1, str2, currentTime, currentUserPtr->getUserID(), n1, n2);
        }
        catch (logic_error err){
            cout << err.what();
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;

    //4 Pay for ticket base on ticketID
    case 4:
        cout << "Please Input the Ticket ID" << endl;
        str1 = readString();
        cout << "please input Pay time, to use current time please input '-2'" << endl;
        t1 = readTime(2);
        if (t1 == -2){ t1 = currentTime; }
        try{
            businessPtr->payForTicket(str1, t1);
        }
        catch (logic_error err){
            cout << err.what();
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;
    case 5:
        cout << "Please Input the Flight ID" << endl;
        str1 = readString();
        cout << "please Input CustomerID" << endl;
        str2 = readString();
        cout << "Please Input seat row " << endl;
        n1 = readInt();
        cout << "Please Input seat col" << endl;
        n2 = readInt();
        cout << "please input Pay time, to use current time please input '-2'" << endl;
        t1 = readTime(2);
        if (t1 == -2){ t1 = currentTime; }
        try{
            businessPtr->payForTicket(str1, str2,t1 ,n1, n2);
        }
        catch (logic_error err){
            cout << err.what();
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;
    case 6:
        cout << "Please Input the Ticket ID" << endl;
        str1 = readString();
        try{
            businessPtr->deleteTicket(str1);
        }
        catch (logic_error err){
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;
    case 7:
        cout << "Please Input start time" << endl;
        t1 = readTime(1);
        cout << "please input end time, to use current time please input '-2'" << endl;
        t2 = readTime(1);
        if (t2 == -2){ t2 = currentTime; }
        try{
            n1 = businessPtr->getSellTicketNumbers(currentUserPtr->getUserID(), currentTime, t1, t2);
            cout << currentUserPtr->getUserName() << " has selled " << n1 << " Ticket(s)" << endl;
        }
        catch (logic_error err){
            cout << err.what();
            cout << "Sorry, this is not a valid operation." << endl;
        }
        break;

    case 8:
        cout << "TicketID | CustomerID | FlightID | book time | Pay Time  -2 is not payed | Expiration Time | Ticket Price| Ticket Agent ID | Seat Row | Seat Col" << endl;
        system("@type Tickets.txt");
        cout << endl;
        break;

    case 10:
        system("cls");
        break;

    default:
        cout << "Your choice is not valid. Please try again!" << endl;
        break;
    }
    system("pause");
  }
}

void Submain::manager(){
    bool isOver = false;
    vector<Ticket> ticketVector;
    int size = 0;

    string str1, str2, str3;
    int n1, n2, n3;
    time_t t1, t2;
    cout << "Welcome Manager" << currentUserPtr->getUserName() << "!" << endl;
    while (!isOver){
        cout << "0 Quit" << endl;
        cout << "1 Show Revenue with a start time and end time" << endl;
        cout << "2 Show Passages on a Flight" << endl;
        cout << "3 Show all airports info" << endl;
        cout << "4 Show all routes info" << endl;
        cout << "5 Show all planes info" << endl;
        cout << "6 Show all flights info" << endl;
        cout << "7 Show all tickets info" << endl;
        cout << "8 Show Plane Quantity Of each type" << endl;
        //cout << "";
        cout << "Please input your choice:" << endl;

        int choice = readInt();
        switch (choice) {
        case 0:
            cout << "Bye Bye, " << currentUserPtr->getUserName() << "!" << endl;
            isOver = true;
            break;
        case 1:
            cout << "Please input the start time of Revenue statistics" << endl;
            t1 = readTime(1);
            cout << "Please input the end time of Revenue statistics" << endl;
            t2 = readTime(1);
            try{
                n1 = businessPtr->getRevenue(t1, t2);
                cout << "Revenue from ";
                showTime(t1);
                cout << " to ";
                showTime(t2);
                cout << " is " << n1 << endl;
            }
            catch (logic_error err){
                cout << err.what();
                cout << "Sorry, this is not a valid operation." << endl;
            }
            break;
        case 2:
            cout << "Please input FlightID to check" << endl;
            str1 = readString();
            try{
                n1 = businessPtr->getPassagerOnFlight(str1, currentTime);
                cout << "their are " << n1 << " Passages on flight " << str1 << endl;
            }
            catch (logic_error err){
                cout << err.what();
                cout << "Sorry, this is not a valid operation." << endl;
            }
            break;
        case 3:
            system("@type Airports.txt");
            cout << endl;
            break;
        case 4:
            system("@type Routes.txt");
            cout << endl;
            break;
        case 5:
            system("@type Planes.txt");
            cout << endl;
            break;
        case 6:
            system("@type Flights.txt");
            cout << endl;
            break;
        case 7:
            cout << "TicketID | CustomerID | FlightID | book time | Pay Time  -2 is not payed | Expiration Time | Ticket Price| Ticket Agent ID | Seat Row | Seat Col" << endl;
            system("@type Tickets.txt");
            cout << endl;
            break;
        case 8:
            cout << "Please Input Plane Type You would like to check" << endl;
            str1 = readString();
            try{
                n1 = businessPtr->getPlanesQTY(str1);
                cout << str1 << " has " << n1 << " planes " << endl;
            }
            catch (logic_error err){
                cout << err.what();
                cout << "Sorry, this is not a valid operation." << endl;
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

void Submain::customer(){
  bool isOver = false;
  vector<Ticket> ticketVector;
  int size = 0;
  while (!isOver)
  {
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
          currentTime,
          INT_NO_LIMIT,
          INT_NO_LIMIT);

      size = ticketVector.size();
      time_t temp_time_t;

      if (size == 0)
      {
        cout << "You have no tickets." << endl;
      }
      else if (size == 1)
      {
        cout << "You have 1 ticket:" << endl;

        Ticket ticket = ticketVector.at(0);

        cout << ticket.getTicketID() << endl;

        showTime(ticket.getFlight().getTKOFTime());
        cout << " TKOF " << ticket.getFlight().getRoute().getTKOF_AP().getAirportName() << endl;

        showTime(ticket.getFlight().getLandTime());
        cout << " DEST " << ticket.getFlight().getRoute().getDEST_AP().getAirportName() << endl;

        cout << "Seat Location: Row " << ticket.getSeatRow() << " Col " << ticket.getSeatCol() << endl;
      }
      else
      {
        cout << "You have " << size << " tickets:" << endl;

        Ticket ticket;
        for (int i = 0; i < size; i++)
        {
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

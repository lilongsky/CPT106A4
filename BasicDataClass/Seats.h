#include <iostream>
#include <string>
#include <vector>

class Seats {
private:
  int rowQTY;
  int colQTY;
  std::vector<char> seatsStatus;

public:
  Seats();
  Seats(std::string planeType);

  std::vector<char> hardcopyVector();
  void setSeatValid(int row, int col);
  void setSeatInvalid(int row, int col);

  char getSeatStatus(int row, int col);

  void showSeats();
};

/* Seats class */

Seats::Seats() {
  colQTY = 0;
  rowQTY = 0;
  seatsStatus = std::vector<char>(0);
}
Seats::Seats(std::string planeType) {
  if (planeType == "P62") {
    this->rowQTY = 6;
    this->colQTY = 2;
  } else if (planeType == "P124") {
    this->rowQTY = 12;
    this->colQTY = 4;
  } else {
      throw std::logic_error("");
  }

  this->seatsStatus = std::vector<char>(rowQTY * colQTY, 'V');
}

std::vector<char> Seats::hardcopyVector(){
    std::vector<char> newSeatsVector(seatsStatus);
    return newSeatsVector;
}

void Seats::setSeatValid(int row, int col) {
  int index = (row - 1) * rowQTY + (col - 1);
  seatsStatus.at(index) = 'V';
}
void Seats::setSeatInvalid(int row, int col) {
  int index = (row - 1) * rowQTY + (col - 1);
  seatsStatus.at(index) = 'I';
}

char Seats::getSeatStatus(int row, int col) {
  int index = (row - 1) * colQTY + (col - 1);
  return seatsStatus.at(index);
}

void Seats::showSeats() {
  char ch;
  std::cout << endl;
  for (int i_row = 1; i_row <= rowQTY; i_row++) {
    for (int i_col = 1; i_col <= colQTY; i_col++) {
      ch = getSeatStatus(i_row, i_col);
      if (ch == 'I') {
        std::cout << "\033[31mI"; // red
      } else if (ch == 'V') {
        std::cout << "\033[32mV"; // green
      } else {
        throw std::logic_error("");
      }
    }
    std::cout << "\033[0m " << i_row << endl;
  }
  std::cout << "\033[0m" << endl;
}

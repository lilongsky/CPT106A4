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
    // throw
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
  int index = (row - 1) * rowQTY + (col - 1);
  return seatsStatus.at(index);
}


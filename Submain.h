#include <iostream>
using namespace std;
#include "Business.h"

class Submain
{
private:
  User* currentUser;
  Business* businessPtr;

public:
  Submain(Business &business);

  void admin();
};

/* Submain class */

Submain::Submain(Business &business) {
  businessPtr = &business;
}

void admin() {

}

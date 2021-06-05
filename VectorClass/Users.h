#pragma once

#include <vector>
#include "../BasicDataClass/User.h"

class Users
{
private:
  std::vector<User> userVector;

public:
  Users() {}

  void add(User &p_user);
};

/* Users class */

void Users::add(User &p_user) {
  userVector.push_back(p_user);
}

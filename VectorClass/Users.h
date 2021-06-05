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
  void remove(int p_index);
};

/* Users class */

void Users::add(User &p_user) {
  userVector.push_back(p_user);
}

void Users::remove(int p_index){
	userVector.erase(userVector.begin() + p_index);
}
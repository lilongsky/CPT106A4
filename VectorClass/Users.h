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
  int getUserIndex(User p_User);
  bool isUserInUsers(User p_User);
};

/* Users class */

void Users::add(User &p_user) {
  userVector.push_back(p_user);
}

void Users::remove(int p_index){
	userVector.erase(userVector.begin() + p_index);
}
bool Users::isUserInUsers(User p_User){
	if (getUserIndex(p_User) == -1){
		return false;
	}
	else{
		return true;
	}
}

int Users::getUserIndex(User p_User){
	int ans = -1;
	for (int i = 0; i < userVector.size(); i++){
		if (userVector.at(i).isSameUser(p_User)){
			ans = i;
			break;
		}
	}
	return ans;
}
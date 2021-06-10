#pragma once

#include <vector>
#include "../BasicDataClass/User.h"

class Users
{
	friend class DataOp;
private:
  std::vector<User> userVector;

public:
  Users() {}

	std::vector<User> hardcopyVector();

  int findSameUserIndex(User p_User);
  bool isSameUserIncluded(User p_User);

  void add(User &p_user);
  void remove(int p_index);
};

/* Users class */

std::vector<User> Users::hardcopyVector() {
	std::vector<User> new_userVector(userVector);
	return new_userVector;
}

void Users::add(User &p_user) {
  userVector.push_back(p_user);
}

void Users::remove(int p_index){
	userVector.erase(userVector.begin() + p_index);
}
bool Users::isSameUserIncluded(User p_User){
	if (findSameUserIndex(p_User) == -1){
		return false;
	}
	else{
		return true;
	}
}

int Users::findSameUserIndex(User p_User){
	int ans = -1;
	for (int i = 0; i < userVector.size(); i++){
		if (userVector.at(i).isSameUser(p_User)){
			ans = i;
			break;
		}
	}
	return ans;
}
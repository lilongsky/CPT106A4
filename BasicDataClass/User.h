#pragma once

#include <string>

class User
{
private:
  std::string m_userID;
  std::string m_realName;
  std::string m_role;

public:
  User() {}
  User(std::string userID, std::string realName, std::string role);
  void hardcopy(User p_User);
  std::string getUserId();
  std::string getUserName();
  std::string getUserRole();
  bool isSameUser(User p_user);
};

/* User class */

User::User(std::string userID, std::string realName, std::string role) {
  m_userID = userID;
  m_realName = realName;
  m_role = role;
}

void User::hardcopy(User p_User){
	this->m_realName = p_User.m_realName;
	this->m_userID = p_User.m_userID;
	this->m_role = p_User.m_role;
}

std::string User::getUserId(){
	return this->m_userID;
}

std::string User::getUserName(){
	return this->m_realName;
}
std::string User::getUserRole(){
	return this->m_role;
}

bool User::isSameUser(User p_user){
	bool ans;
	ans = (this->m_userID == p_user.m_userID);
	return ans;
}
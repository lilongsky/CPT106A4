#pragma once

#include <string>

class User
{
  friend class Users;

private:
  std::string m_userID;
  std::string m_realName;
  std::string m_role;

public:
  User() {}
  User(std::string userID, std::string realName, std::string role);

  void hardcopy(User p_user);

  std::string getUserID();
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

void User::hardcopy(User p_user) {
	this->m_realName = p_user.m_realName;
	this->m_userID = p_user.m_userID;
	this->m_role = p_user.m_role;
}

std::string User::getUserID() {
	return this->m_userID;
}

std::string User::getUserName() {
	return this->m_realName;
}
std::string User::getUserRole() {
	return this->m_role;
}

bool User::isSameUser(User p_user) {
  if ((m_userID == p_user.m_userID)
      && m_realName == p_user.m_realName
      && m_role == p_user.m_role)
  {
    return true;
  } else {
    return false;
  }
}
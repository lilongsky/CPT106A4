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
};

/* User class */

User::User(std::string userID, std::string realName, std::string role) {
  m_userID = userID;
  m_realName = realName;
  m_role = role;
}

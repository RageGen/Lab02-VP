#pragma once
#include <string>
#include <iostream>
#pragma once
class User
{
protected:
	std::string m_name;
	std::string m_surname;
	std::string m_login;
	std::string m_password;
	int m_age;
public:
	virtual void m_CheckAge(int,int) = 0;
};


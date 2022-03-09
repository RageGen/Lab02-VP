#include "User.hpp"
#pragma once
class Teacher : public User
{
public:
	void m_SetName();
	void m_SetSurname();
	void m_SetLogin();
	void m_SetPassword();
	std::string m_GetName();
	std::string m_GetSurname();
	std::string m_GetLogin();
	std::string m_GetPassword();
	int m_GetAge();
	virtual void m_CheckAge(int,int);
	Teacher(std::string, std::string, std::string, std::string, int);
};
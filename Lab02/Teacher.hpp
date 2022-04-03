#pragma once
#include "User.hpp"
class Teacher : public User
{
public:
	bool operator >(const Teacher& Tc)
	{
		return (this->m_surname[0] > Tc.m_surname[0]);
	}
	bool operator < (const Teacher& Tc)
	{
		return (this->m_surname[0] < Tc.m_surname[0]);
	}
	void m_SetName(std::string);
	void m_SetSurname(std::string);
	void m_SetAge(int);
	void m_SetLogin(std::string);
	void m_SetPassword(std::string);
	friend std::ostream& operator<<(std::ostream& out, const Teacher& Tc);
	friend std::istream& operator >> (std::istream& in,	Teacher& Tc);
	std::string m_GetName();
	std::string m_GetSurname();
	std::string m_GetLogin();
	std::string m_GetPassword();
	int m_GetAge();
	virtual void m_CheckAge(int,int);
	Teacher(std::string, std::string, std::string, std::string, int);
	Teacher();
};

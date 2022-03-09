#include "User.hpp"
#pragma once
class Student : public User
{
protected:
	int m_course;
	int m_MiddleEstimation;
public:
	void m_SetName();
	void m_SetSurname();
	void m_SetAge();
	void m_SetLogin();
	void m_SetPassword();
	std::string m_GetName();
	std::string m_GetSurname();
	std::string m_GetLogin();
	std::string m_GetPassword();
	int m_GetAge();
	virtual void m_CheckAge(int,int);
	Student(std::string, std::string, std::string, std::string, int, int, int);
};
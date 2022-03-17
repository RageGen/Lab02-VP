#include "User.hpp"
#pragma once
class Student : public User
{
protected:
	int m_course;
	int m_MiddleEstimation;
public:
	void m_SetName(std::string);
	void m_SetSurname(std::string);
	void m_SetAge(int);
	void m_SetLogin(std::string);
	void m_SetPassword(std::string);
	void m_SetMiddleEstimation(int);
	void m_SetCourse(int);
	std::string m_GetName();
	std::string m_GetSurname();
	std::string m_GetLogin();
	std::string m_GetPassword();
	int m_GetAge();
	int m_GetMiddleEstimation();
	virtual void m_CheckAge(int,int);
	Student(std::string, std::string, std::string, std::string, int, int, int);
	Student();
};
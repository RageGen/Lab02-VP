#pragma once
#include "User.hpp"
#include <exception>
class Student : public User
{
protected:
	int m_course;
	int m_MiddleEstimation;
public:
	bool operator >(const Student& St)
	{
		return (this->m_surname[0] > St.m_surname[0]);
	}
	bool operator < (const Student& St)
	{
		return (this->m_surname[0] < St.m_surname[0]);
	}
	void m_SetName(std::string);
	void m_SetSurname(std::string);
	void m_SetAge(int);
	void m_SetLogin(std::string);
	void m_SetPassword(std::string);
	void m_SetMiddleEstimation(int);
	void m_SetCourse(int);
	friend std::ostream& operator<<(std::ostream& out, const Student& St);
	friend std::istream& operator >> (std::istream& in,  Student& St);
	std::string m_GetName();
	std::string m_GetSurname();
	std::string m_GetLogin();
	std::string m_GetPassword();
	int m_GetAge();
	int m_GetMiddleEstimation();
	int m_GetCourse();
	virtual void m_CheckAge(int,int);
	Student(std::string, std::string, std::string, std::string, int, int, int);
	Student();
};
#include "Student.hpp"
void Student::m_SetName(std::string name) {
	m_name=name;
}
void Student::m_SetSurname(std::string surname) {
	m_surname=surname;
}
void Student::m_SetAge(int age) {
	m_age=age;
}
void Student::m_SetLogin(std::string login) {
	m_login=login;
}
void Student::m_SetPassword(std::string password) {
	m_password=password;
}
void Student::m_SetMiddleEstimation(int MiddleEstimation)
{
	m_MiddleEstimation = MiddleEstimation;
}
void Student::m_SetCourse(int Course)
{
	m_course = Course;
}
std::string Student::m_GetName() {
	return m_name;
}
std::string Student::m_GetSurname() {
	return m_surname;
}
int Student::m_GetAge() {
	return m_age;
}
void Student::m_CheckAge(int age,int ListPos)
{
	if ((0 > age) || (age > 99))
	{
		std::cout << "Некоректный возраст! У студента номер "<<ListPos+1 << std::endl;
	}
}
std::string Student::m_GetLogin() {
	return m_login;
}
std::string Student::m_GetPassword() {
	return m_password;
}
Student::Student(std::string name, std::string surname, std::string login, std::string password, int age, int course, int MiddleEstimation)
{
	m_name = name;
	m_surname = surname;
	m_login = login;
	m_password = password;
	m_age = age;
	m_course = course;
	m_MiddleEstimation = MiddleEstimation;
}
Student::Student()
{
}
int Student::m_GetMiddleEstimation()
{
	return m_MiddleEstimation;
}

int Student::m_GetCourse()
{
	return m_course;
}

std::ostream& operator<<(std::ostream& out, const Student& St)
{
	return out << St.m_name + " " + St.m_surname;
}

std::istream& operator>>(std::istream& in,  Student& St)
{
	in >> St.m_name;
	in.ignore();
	in >> St.m_surname;
	in.ignore();
	in >> St.m_age >> St.m_MiddleEstimation >> St.m_course;
	in.ignore();
	in >> St.m_login;
	in.ignore();
	in>> St.m_password;
	return in;
}

#include "Teacher.hpp"
void Teacher::m_SetName(std::string name) {
	m_name=name;
}
void Teacher::m_SetSurname(std::string surname) {
	m_surname=surname;
}
void Teacher::m_SetAge(int age)
{
	m_age = age;
}
void Teacher::m_SetLogin(std::string login) {
	m_login=login;
}
void Teacher::m_SetPassword(std::string password) {
	m_password=password;
}
std::string Teacher::m_GetName() {
	return m_name;
}
std::string Teacher::m_GetSurname() {
	return m_surname;
}
int Teacher::m_GetAge() {
	return m_age;
}
std::string Teacher::m_GetLogin() {
	return m_login;
}
std::string Teacher::m_GetPassword() {
	return m_password;
}
void Teacher::m_CheckAge(int age, int ListPos)
{
	if ((0 > age)||(age > 99))
	{
		std::cout << "Некоректный возраст! У преподавателя номер "<<ListPos+1 << std::endl;
	}
}
Teacher::Teacher(std::string name, std::string surname, std::string login, std::string password, int age)
{
	m_name = name;
	m_surname = surname;
	m_login = login;
	m_password = password;
	m_age = age;
}

Teacher::Teacher()
{
}

std::ostream& operator<<(std::ostream& out, const Teacher& Tc)
{
	return out<< Tc.m_name + " " + Tc.m_surname;
}

std::istream& operator>>(std::istream& in, Teacher& Tc)
{
	std::cout << "Введите имя преподавателя\n---> ";
	in >> Tc.m_name;
	in.ignore();
	std::cout << "Введите фамилию преподавателя\n---> ";
	in >> Tc.m_surname;
	in.ignore();
	std::cout << "Введите возраст преподавателя\n---> ";
	in >> Tc.m_age;
	std::cout << "Введите логин преподавателя\n---> ";
	in >> Tc.m_login;
	in.ignore();
	std::cout << "Введите пароль преподавателя\n---> ";
	in >> Tc.m_password;

	return in;
}

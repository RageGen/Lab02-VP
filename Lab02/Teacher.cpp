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

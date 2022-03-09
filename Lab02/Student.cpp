#include "Student.hpp"
void Student::m_SetName() {
	std::cout << "Введите имя студента ---> ";
	std::cin >> m_name;
}
void Student::m_SetSurname() {
	std::cout << "Введите фамилию студента ---> ";
	std::cin >> m_surname;
}
void Student::m_SetAge() {
	std::cout << "Введите возраст студента ---> ";
	std::cin >> m_age;
}
void Student::m_SetLogin() {
	std::cout << "Введите логин студента ---> ";
	std::cin >> m_login;
}
void Student::m_SetPassword() {
	std::cout << "Введите пароль студента ---> ";
	std::cin >> m_password;
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
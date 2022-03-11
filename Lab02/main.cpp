#include "Course.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <fstream>
using namespace std;
int StudentsAmount = 0;
int TeachersAmount = 0;
int CheckMenu = 0;
bool RunMenu = true;
Course BasicCourse;
Student InputStudentInfo()
{
	system("cls");
	string StudentName = "";
	string StudentSurname = "";
	string StudentLogin = "";
	string StudentPassword = "";
	int StudentAge = 0;
	int StudentMiddleEstimation = 0;
	int StudentCourse = 0;
	cout << "Введите имя студента\n---> ";
	cin >> StudentName;
	cout << "Введите фамилию студента\n---> ";
	cin >> StudentSurname;
	cout << "Введите возраст студента\n---> ";
	cin >> StudentAge;
	cout << "Укажите курс студента\n---> ";
	cin >> StudentCourse;
	cout << "Введите среднюю оценку\n---> ";
	cin >> StudentMiddleEstimation;
	cout << "Введите логин студента\n---> ";
	cin >> StudentLogin;
	cout << "Введите пароль студента\n---> ";
	cin >> StudentPassword;
	return 	Student(StudentName, StudentSurname, StudentLogin, StudentPassword, StudentAge, StudentCourse, StudentMiddleEstimation);
}
Teacher InputTeacherInfo()
{
	system("cls");
	string TeacherName = "";
	string TeacherSurname = "";
	string TeacherLogin = "";
	string TeacherPassword = "";
	int TeacherAge = 0;
	cin.ignore();
	cout << "Введите имя преподавателя\n---> ";
	cin >> TeacherName;
	cout << "Введите фамилию преподавателя\n---> ";
	cin >> TeacherSurname;
	cout << "Введите возраст преподавателя\n---> " ;
	cin >> TeacherAge;
	cout << "Введите логин преподавателя\n---> ";
	cin >> TeacherLogin;
	cout << "Введите пароль преподавателя\n---> " ;
	cin >> TeacherPassword;
	return Teacher(TeacherName, TeacherSurname, TeacherLogin, TeacherPassword, TeacherAge);
}
void CourseAboutTable()
{
	int TitleLength = BasicCourse.m_GetTitle().length();
	int DescriptionLength = BasicCourse.m_GetDescription().length();
	cout << setw(TitleLength) << left << BasicCourse.m_GetTitle() << '|' << setw(DescriptionLength) << left << BasicCourse.m_GetDescription() <<"|Средняя оценка студентов за курс-"<<setw(1) << BasicCourse.m_GetCourseEstimation() << endl;
}
void InputCourseInfo()
{
	string CourseTitle = "";
	string CourseDescription = "";
	cin.ignore();
	cout << "Как называется курс?\n---> ";
	getline(cin, CourseTitle);
	cout << "Укажите описание курса\n---> ";
	getline(cin, CourseDescription);
	BasicCourse=Course(CourseTitle,CourseDescription);
}
void StudentsTable(vector<Student>& StudentList)
{
	int MaxNameLength = 0;
	int MaxSurnameLength = 0;
	int MaxLoginLength = 0;
	int MaxPasswordLength = 0;
	int MaxAgeLength = 0;
	for (int i = 0; i < StudentList.size(); i++)
	{
		if (StudentList[i].m_GetName().length() > MaxNameLength)
		{
			MaxNameLength = StudentList[i].m_GetName().length();
		}
		if (StudentList[i].m_GetSurname().length() > MaxSurnameLength)
		{
			MaxSurnameLength = StudentList[i].m_GetSurname().length();
		}
		if (StudentList[i].m_GetLogin().length() > MaxLoginLength)
		{
			MaxLoginLength = StudentList[i].m_GetLogin().length();
		}
		if (StudentList[i].m_GetPassword().length() > MaxPasswordLength)
		{
			MaxPasswordLength = StudentList[i].m_GetPassword().length();
		}
	}
	for (int i = 0; i < StudentList.size(); i++)
	{
		int BufferAge = StudentList[i].m_GetAge();
		for (int k = 0; BufferAge > 0; k++)
		{
			BufferAge /= 10;
			if (k > MaxAgeLength)
			{
				MaxAgeLength = k;
			}
		}
	}
	for (int j = 0; j < StudentList.size(); j++)
	{
		cout << "|" << setw(MaxNameLength) << left << StudentList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << StudentList[j].m_GetSurname() << "|" << setw(MaxAgeLength+1) << left << StudentList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << StudentList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << StudentList[j].m_GetPassword() << '|'  << endl;
	}
}
void MenuTable()
{
	system("cls");
	cout << "1. Создать курс" << endl;
	cout << "2. Вывести всю информаци о курсе" << endl;
	cout << "3. Проверить корректность возраста всех участников курса"<<endl;
	cout << "0. Выход\n---> ";
}
void CheckAge(vector<Teacher>& TeacherList, vector<Student>& StudentList)
{
	for (int i = 0; i < StudentsAmount; i++)
	{
		StudentList[i].m_CheckAge(StudentList[i].m_GetAge(),i);
	}
	for (int i = 0; i < TeachersAmount; i++)
	{
		TeacherList[i].m_CheckAge(TeacherList[i].m_GetAge(), i);
	}

}
void TeachersTable(vector<Teacher>& TeacherList)
{
	int MaxNameLength = 0;
	int MaxSurnameLength = 0;
	int MaxLoginLength = 0;
	int MaxPasswordLength = 0;
	int MaxAgeLength = 0;
	for (int i = 0; i < TeacherList.size(); i++)
	{
		if (TeacherList[i].m_GetName().length() > MaxNameLength)
		{
			MaxNameLength = TeacherList[i].m_GetName().length();
		}
		if (TeacherList[i].m_GetSurname().length() > MaxSurnameLength)
		{
			MaxSurnameLength = TeacherList[i].m_GetSurname().length();
		}
		if (TeacherList[i].m_GetLogin().length() > MaxLoginLength)
		{
			MaxLoginLength = TeacherList[i].m_GetLogin().length();
		}
		if (TeacherList[i].m_GetPassword().length() > MaxPasswordLength)
		{
			MaxPasswordLength = TeacherList[i].m_GetPassword().length();
		}
	}
	for (int i = 0; i < TeacherList.size(); i++)
	{
		int BufferAge = TeacherList[i].m_GetAge();
		for (int k = 0; BufferAge > 0; k++)
		{
			BufferAge /= 10;
			if (k > MaxAgeLength)
			{
				MaxAgeLength = k;
			}
		}
	}
	for (int j = 0; j < TeacherList.size(); j++)
	{
		cout << "|" << setw(MaxNameLength) << left << TeacherList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << TeacherList[j].m_GetSurname() << "|" << setw(MaxAgeLength+1) << left << TeacherList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << TeacherList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << TeacherList[j].m_GetPassword() << '|' << endl;
	}
}
void ContinueOrNot()
{
	int ContinueChecker = 1;
	cout << "Вернуться в меню? 1-Да 0-Нет" << endl;
	cin >> ContinueChecker;
	if (ContinueChecker == 0)
	{
		RunMenu = false;
	}
}
void CalcCourse(vector<Student>& StudentList)
{
	int sum = 0;
	int k = 0;
	for (int i = 0; i < StudentList.size();i++)
	{
		sum += StudentList[i].m_GetMiddleEstimation();
		k++;
	}
	BasicCourse.m_SetCourseEstimation((sum / k));
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Student>StudentList;
	vector<Teacher>TeacherList;
	while (RunMenu == true)
	{
		MenuTable();
		cin >> CheckMenu;
		switch (CheckMenu)
		{
		case 1:
			system("cls");
			InputCourseInfo();
			cout << "Теперь разберемся с составом курса." << endl;
			cout << "Сколько студентов добавим на курс?\n---> ";
			cin >> StudentsAmount;
			for (int i = 0; i < StudentsAmount; i++)
			{
				StudentList.push_back(InputStudentInfo());
			}
			CalcCourse(StudentList);
			system("cls");
			cout << "Сколько преподавателей будет работать на курсе?\n---> ";
			cin >> TeachersAmount;
			for (int i = 0; i < TeachersAmount; i++)
			{
				TeacherList.push_back(InputTeacherInfo());
			}
			ContinueOrNot();
			break;
		case 2:
			CourseAboutTable();
			cout << "Состав\n" << endl;
			cout << "Студенты:" << endl;
			StudentsTable(StudentList);
			cout << "Преподаватели:" << endl;
			TeachersTable(TeacherList);
			ContinueOrNot();
			break;
		case 3:
			CheckAge(TeacherList, StudentList);
			ContinueOrNot();
			break;
		case 0:
			RunMenu = false;
			break;
		}
	}
}
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
void LocalInformation(vector<Student>& StudentList, vector<Teacher>& TeacherList,Course &BasicCourse)
{
	BasicCourse.m_SetTitle("�������");
	BasicCourse.m_SetDescription("���4-12�");
	StudentList[0].m_SetName("����");
	StudentList[0].m_SetSurname("��������");
	StudentList[0].m_SetAge(22);
	StudentList[0].m_SetCourse(3);
	StudentList[0].m_SetMiddleEstimation(3);
	StudentList[0].m_SetLogin("Egor1203");
	StudentList[0].m_SetPassword("password12345");

	StudentList[1].m_SetName("������");
	StudentList[1].m_SetSurname("������");
	StudentList[1].m_SetAge(18);
	StudentList[1].m_SetCourse(1);
	StudentList[1].m_SetMiddleEstimation(4);
	StudentList[1].m_SetLogin("Serg12");
	StudentList[1].m_SetPassword("password12345");

	StudentList[2].m_SetName("���������");
	StudentList[2].m_SetSurname("��������");
	StudentList[2].m_SetAge(21);
	StudentList[2].m_SetCourse(2);
	StudentList[2].m_SetMiddleEstimation(5);
	StudentList[2].m_SetLogin("Elz11");
	StudentList[2].m_SetPassword("password12345");

	TeacherList[0].m_SetName("��");
	TeacherList[0].m_SetSurname("�������");
	TeacherList[0].m_SetAge(35);
	TeacherList[0].m_SetLogin("Yan35");
	TeacherList[0].m_SetPassword("password12345");

	TeacherList[1].m_SetName("�����");
	TeacherList[1].m_SetSurname("��������");
	TeacherList[1].m_SetAge(45);
	TeacherList[1].m_SetLogin("Alis45");
	TeacherList[1].m_SetPassword("password12345");

	TeacherList[2].m_SetName("����");
	TeacherList[2].m_SetSurname("��������");
	TeacherList[2].m_SetAge(55);
	TeacherList[2].m_SetLogin("Ivan55");
	TeacherList[2].m_SetPassword("password12345");

}
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
	cout << "������� ��� ��������\n---> ";
	cin >> StudentName;
	cout << "������� ������� ��������\n---> ";
	cin >> StudentSurname;
	cout << "������� ������� ��������\n---> ";
	cin >> StudentAge;
	cout << "������� ���� ��������\n---> ";
	cin >> StudentCourse;
	cout << "������� ������� ������\n---> ";
	cin >> StudentMiddleEstimation;
	cout << "������� ����� ��������\n---> ";
	cin >> StudentLogin;
	cout << "������� ������ ��������\n---> ";
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
	cout << "������� ��� �������������\n---> ";
	cin >> TeacherName;
	cout << "������� ������� �������������\n---> ";
	cin >> TeacherSurname;
	cout << "������� ������� �������������\n---> " ;
	cin >> TeacherAge;
	cout << "������� ����� �������������\n---> ";
	cin >> TeacherLogin;
	cout << "������� ������ �������������\n---> " ;
	cin >> TeacherPassword;
	return Teacher(TeacherName, TeacherSurname, TeacherLogin, TeacherPassword, TeacherAge);
}
void CourseAboutTable()
{
	int TitleLength = BasicCourse.m_GetTitle().length();
	int DescriptionLength = BasicCourse.m_GetDescription().length();
	cout << setw(TitleLength) << left << BasicCourse.m_GetTitle() << '|' << setw(DescriptionLength) << left << BasicCourse.m_GetDescription() <<"|������� ������ ��������� �� ����-"<<setw(1) << BasicCourse.m_GetCourseEstimation() << endl;
}
void InputCourseInfo()
{
	string CourseTitle = "";
	string CourseDescription = "";
	cin.ignore();
	cout << "��� ���������� ����?\n---> ";
	getline(cin, CourseTitle);
	cout << "������� �������� �����\n---> ";
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
		cout << "|" << setw(MaxNameLength) << left << StudentList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << StudentList[j].m_GetSurname() << "|" << setw(MaxAgeLength+1) << left << StudentList[j].m_GetAge() <<"|"<<setw(1)<<left<<StudentList[j].m_GetMiddleEstimation()<<"|"<< setw(MaxLoginLength) << left << StudentList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << StudentList[j].m_GetPassword() << '|'  << endl;
	}
}
void MenuTable()
{
	system("cls");
	cout << "1. ������� ����" << endl;
	cout << "2. ������� ��� ��������� � �����" << endl;
	cout << "3. ��������� ������������ �������� ���� ���������� �����"<<endl;
	cout << "0. �����\n---> ";
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
	cout << "��������� � ����? 1-�� 0-���" << endl;
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
	StudentList.resize(3);
	TeacherList.resize(3);
	LocalInformation(StudentList, TeacherList, BasicCourse);
	CalcCourse(StudentList);
	while (RunMenu == true)
	{
		MenuTable();
		cin >> CheckMenu;
		switch (CheckMenu)
		{
		case 1:
			system("cls");
			InputCourseInfo();
			cout << "������ ���������� � �������� �����." << endl;
			cout << "������� ��������� ������� �� ����?\n---> ";
			cin >> StudentsAmount;
			for (int i = 0; i < StudentsAmount; i++)
			{
				StudentList.push_back(InputStudentInfo());
			}
			system("cls");
			cout << "������� �������������� ����� �������� �� �����?\n---> ";
			cin >> TeachersAmount;
			for (int i = 0; i < TeachersAmount; i++)
			{
				TeacherList.push_back(InputTeacherInfo());
			}
			ContinueOrNot();
			break;
		case 2:
			CourseAboutTable();
			cout << "������\n" << endl;
			cout << "��������:" << endl;
			StudentsTable(StudentList);
			cout << "�������������:" << endl;
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
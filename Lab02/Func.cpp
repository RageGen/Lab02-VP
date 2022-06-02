#include "Func.hpp"
#include <vector>
#include "Dector.hpp"
using namespace ZDA;
using namespace std;
bool RunMenu = true;
Dector<Student> StudentList;
Dector<Teacher> TeacherList;
Course BasicCourse;
void LocalInformation()
{
	StudentList.resize(3);
	TeacherList.resize(3);
	BasicCourse.m_SetTitle("�������");
	BasicCourse.m_SetDescription("���4-12�");
	StudentList[0].m_SetName("����");
	StudentList[0].m_SetSurname("��������");
	StudentList[0].m_SetAge(101);
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
bool InputStudentInfo()
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
	try {
		cout << "������� ������� ��������\n---> ";
		cin >> StudentAge;
		if (StudentAge>40)
		{
			throw 1;
		}
	}
	catch (int e)
	{
		if (e == 1)
		{
			cout << "����� ����� �������� �����������" << endl;
		}
	}
	cout << "������� ���� ��������\n---> ";
	cin >> StudentCourse;
	cout << "������� ������� ������\n---> ";
	cin >> StudentMiddleEstimation;
	cout << "������� ����� ��������\n---> ";
	cin >> StudentLogin;
	cout << "������� ������ ��������\n---> ";
	cin >> StudentPassword;
	Student BufferStudent = Student(StudentName,StudentSurname,StudentLogin,StudentPassword,StudentAge,StudentCourse,StudentMiddleEstimation);
	StudentList.push_back(BufferStudent);
	return true;
}
bool InputTeacherInfo()
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
	cout << "������� ������� �������������\n---> ";
	cin >> TeacherAge;
	cout << "������� ����� �������������\n---> ";
	cin >> TeacherLogin;
	cout << "������� ������ �������������\n---> ";
	cin >> TeacherPassword;
	Teacher BufferTeacher = Teacher(TeacherName,TeacherSurname,TeacherLogin,TeacherPassword,TeacherAge);
	TeacherList.push_back(BufferTeacher);
	return true;
}
void CourseAboutTable()
{
	int TitleLength = BasicCourse.m_GetTitle().length();
	int DescriptionLength = BasicCourse.m_GetDescription().length();
	cout << setw(TitleLength) << left << BasicCourse.m_GetTitle() << '|' << setw(DescriptionLength) << left << BasicCourse.m_GetDescription() << "|������� ������ ��������� �� ����-" << setw(1) << BasicCourse.m_GetCourseEstimation() << endl;
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
	BasicCourse.m_SetTitle(CourseTitle);
	BasicCourse.m_SetDescription(CourseDescription);
}
bool StudentsTable()
{
	int MaxNameSurnameCol = 0;
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
	MaxNameSurnameCol = MaxNameLength + MaxSurnameLength + 1;
	for (int j = 0; j < StudentList.size(); j++)
	{
		cout << "|" <<setw(MaxNameSurnameCol)<<left<< StudentList[j] << "|" << setw(MaxAgeLength + 1) << left << StudentList[j].m_GetAge() << "|" << setw(1) << left << StudentList[j].m_GetMiddleEstimation() << "|" <<setw(1)<<left<<StudentList[j].m_GetCourse() << "|" << setw(MaxLoginLength) << left << StudentList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << StudentList[j].m_GetPassword() << '|' << endl;
	}
	return true;
}
bool CheckAge()
{
	bool flag = true;
	int iflag = 0;
	while (flag==true)
	{
		system("cls");
		for (int i = 0; i < StudentList.size(); i++)
		{
			StudentList[i].m_CheckAge(StudentList[i].m_GetAge(), i);
		}
		for (int i = 0; i < TeacherList.size(); i++)
		{
			TeacherList[i].m_CheckAge(TeacherList[i].m_GetAge(), i);
		}
		cout << "��������� 1-�� 0-���" << endl;
		cin >> iflag;
		if (iflag == 1) {
			flag = false;
		}
	}
	return true;
}
void TeachersTable()
{
	int MaxNameLength = 0;
	int MaxSurnameLength = 0;
	int MaxLoginLength = 0;
	int MaxPasswordLength = 0;
	int MaxAgeLength = 0;
	int MaxNameSurnameCol = 0;
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
	MaxNameSurnameCol = MaxNameLength + MaxSurnameLength + 1;
	for (int j = 0; j < TeacherList.size(); j++)
	{
		cout << "|" << setw(MaxNameSurnameCol) << left <<TeacherList[j]<< "|" << setw(MaxAgeLength + 1) << left << TeacherList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << TeacherList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << TeacherList[j].m_GetPassword() << '|' << endl;
	}
}

void CalcCourse()
{
	int sum = 0;
	int k = 0;
	for (int i = 0; i < StudentList.size(); i++)
	{
		sum += StudentList[i].m_GetMiddleEstimation();
		k++;
	}
	BasicCourse.m_SetCourseEstimation (sum / k);
}
bool InputAllInfo()
{
	int StudentAmount = 0;
	int TeacherAmount = 0;
	InputCourseInfo();
	cout << "������� ��������� �������?" << endl;
	cin >> StudentAmount;
	for (int i=0;i<StudentAmount;i++)
	{
		InputStudentInfo();
	}
	cout << "������� �������������� �������?" << endl;
	cin >> TeacherAmount;
	for (int i = 0; i < TeacherAmount; i++)
	{
		InputTeacherInfo();
	}
	return true;
}
bool AllInfoTable()
{
	bool flag = true;
	int iflag = 0;
	CalcCourse();
	while (flag==true)
	{
		system("cls");
		CourseAboutTable();
		cout << "��������" << endl;
		StudentsTable();
		cout << "�������������" << endl;
		TeachersTable();
		cout << "��������� 1-�� 0-���" << endl;
		cin >> iflag;
		if (iflag == 1) {
			flag = false;
		}
	}
	return true;
}
bool AppendStudent()
{
	Student BufferStudent;
	cin >> BufferStudent;
	StudentList.push_back(BufferStudent);
	return true;
}
bool AppendTeacher()
{
	Teacher BufferTeacher;
	cin >> BufferTeacher;
	TeacherList.push_back(BufferTeacher);
	return true;
}
bool RemoveStudent()
{
	int Checker = 0;
	cout << "������ �������� �������?" << endl;
	cin >> Checker;
	StudentList.RemoveAt(Checker);
	return true;
}
bool RemoveTeacher()
{
	int Checker = 0;
	cout << "������ ������������� �������?" << endl;
	cin >> Checker;
	return true;
}

bool AppendPeople()
{
	const int ItemsNumber = 2;
	Item Items[ItemsNumber]{ Item{"��������",AppendStudent},Item{"�������������",AppendTeacher}};
	Menu menu("����������", Items, ItemsNumber);
	while (menu.runCommand())
	{
		system("cls");
	}
	return true;
}
bool RemoveStorTc()
{
	const int ItemsNumber = 2;
	Item Items[ItemsNumber]{ Item{"��������",RemoveStudent},Item{"�������������",RemoveTeacher} };
	Menu menu("��������", Items, ItemsNumber);
	while (menu.runCommand())
	{
		system("cls");
	}
	return true;
}

bool Sort()
{
	for (int i = 0; i < TeacherList.size(); i++)
	{
		for (int j = i + 1; j < TeacherList.size(); j++)
		{
			if (TeacherList[i] > TeacherList[j])
			{
				Teacher temp = TeacherList[i];
				TeacherList[i] = TeacherList[j];
				TeacherList[j] = temp;
			}
		}
	}
	for (int i = 0; i < StudentList.size(); i++)
	{
		for (int j = i + 1; j < StudentList.size(); j++)
		{
			if (StudentList[i] > StudentList[j])
			{
				Student temp = StudentList[i];
				StudentList[i] = StudentList[j];
				StudentList[j] = temp;
			}
		}
	}
	return true;
}

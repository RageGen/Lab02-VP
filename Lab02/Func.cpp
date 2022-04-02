#include "Func.hpp"
using namespace std;
bool RunMenu = true;
vector<Student>StudentList;
vector<Teacher>TeacherList;
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
		cout << "|" << setw(MaxNameLength) << left << StudentList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << StudentList[j].m_GetSurname() << "|" << setw(MaxAgeLength + 1) << left << StudentList[j].m_GetAge() << "|"<<setw(1)<<left<<StudentList[j].m_GetMiddleEstimation() << "|" << setw(MaxLoginLength) << left << StudentList[j].m_GetLogin()
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
		cout << "|" << setw(MaxNameLength) << left << TeacherList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << TeacherList[j].m_GetSurname() << "|" << setw(MaxAgeLength + 1) << left << TeacherList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << TeacherList[j].m_GetLogin()
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
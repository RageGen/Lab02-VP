#include "Func.hpp"
using namespace std;
bool RunMenu = true;
void LocalInformation(vector<Student>& StudentList, vector<Teacher>& TeacherList, Course& BasicCourse)
{
	BasicCourse.m_SetTitle("История");
	BasicCourse.m_SetDescription("ИУК4-12Б");
	StudentList[0].m_SetName("Егор");
	StudentList[0].m_SetSurname("Казанцев");
	StudentList[0].m_SetAge(22);
	StudentList[0].m_SetCourse(3);
	StudentList[0].m_SetMiddleEstimation(3);
	StudentList[0].m_SetLogin("Egor1203");
	StudentList[0].m_SetPassword("password12345");

	StudentList[1].m_SetName("Сергей");
	StudentList[1].m_SetSurname("Иванов");
	StudentList[1].m_SetAge(18);
	StudentList[1].m_SetCourse(1);
	StudentList[1].m_SetMiddleEstimation(4);
	StudentList[1].m_SetLogin("Serg12");
	StudentList[1].m_SetPassword("password12345");

	StudentList[2].m_SetName("Елизавета");
	StudentList[2].m_SetSurname("Козырева");
	StudentList[2].m_SetAge(21);
	StudentList[2].m_SetCourse(2);
	StudentList[2].m_SetMiddleEstimation(5);
	StudentList[2].m_SetLogin("Elz11");
	StudentList[2].m_SetPassword("password12345");

	TeacherList[0].m_SetName("Ян");
	TeacherList[0].m_SetSurname("Андреев");
	TeacherList[0].m_SetAge(35);
	TeacherList[0].m_SetLogin("Yan35");
	TeacherList[0].m_SetPassword("password12345");

	TeacherList[1].m_SetName("Алиса");
	TeacherList[1].m_SetSurname("Федорова");
	TeacherList[1].m_SetAge(45);
	TeacherList[1].m_SetLogin("Alis45");
	TeacherList[1].m_SetPassword("password12345");

	TeacherList[2].m_SetName("Иван");
	TeacherList[2].m_SetSurname("Щербаков");
	TeacherList[2].m_SetAge(55);
	TeacherList[2].m_SetLogin("Ivan55");
	TeacherList[2].m_SetPassword("password12345");
}
bool InputStudentInfo(vector<Student>&StudentList )
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
	Student BufferStudent = Student(StudentName,StudentSurname,StudentLogin,StudentPassword,StudentAge,StudentCourse,StudentMiddleEstimation);
	StudentList.push_back(BufferStudent);
	return true;
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
	cout << "Введите возраст преподавателя\n---> ";
	cin >> TeacherAge;
	cout << "Введите логин преподавателя\n---> ";
	cin >> TeacherLogin;
	cout << "Введите пароль преподавателя\n---> ";
	cin >> TeacherPassword;
	return Teacher(TeacherName, TeacherSurname, TeacherLogin, TeacherPassword, TeacherAge);
}
void CourseAboutTable(Course BasicCourse)
{
	int TitleLength = BasicCourse.m_GetTitle().length();
	int DescriptionLength = BasicCourse.m_GetDescription().length();
	cout << setw(TitleLength) << left << BasicCourse.m_GetTitle() << '|' << setw(DescriptionLength) << left << BasicCourse.m_GetDescription() << "|Средняя оценка студентов за курс-" << setw(1) << BasicCourse.m_GetCourseEstimation() << endl;
}
void InputCourseInfo(Course BasicCourse)
{
	string CourseTitle = "";
	string CourseDescription = "";
	cin.ignore();
	cout << "Как называется курс?\n---> ";
	getline(cin, CourseTitle);
	cout << "Укажите описание курса\n---> ";
	getline(cin, CourseDescription);
	BasicCourse = Course(CourseTitle, CourseDescription);
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
		cout << "|" << setw(MaxNameLength) << left << StudentList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << StudentList[j].m_GetSurname() << "|" << setw(MaxAgeLength + 1) << left << StudentList[j].m_GetAge() << "|"<<setw(1)<<left<<StudentList[j].m_GetMiddleEstimation() << "|" << setw(MaxLoginLength) << left << StudentList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << StudentList[j].m_GetPassword() << '|' << endl;
	}
}
void MenuTable()
{
	system("cls");
	cout << "1. Создать курс" << endl;
	cout << "2. Вывести всю информаци о курсе" << endl;
	cout << "3. Проверить корректность возраста всех участников курса" << endl;
	cout << "0. Выход\n---> ";
}
void CheckAge(vector<Teacher>& TeacherList, vector<Student>& StudentList)
{
	for (int i = 0; i < StudentList.size();i++)
	{
		StudentList[i].m_CheckAge(StudentList[i].m_GetAge(), i);
	}
	for (int i = 0; i < TeacherList.size(); i++)
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
		cout << "|" << setw(MaxNameLength) << left << TeacherList[j].m_GetName() << " " << setw(MaxSurnameLength) << left << TeacherList[j].m_GetSurname() << "|" << setw(MaxAgeLength + 1) << left << TeacherList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << TeacherList[j].m_GetLogin()
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

int CalcCourse(std::vector<Student>& StudentList)
{
	int sum = 0;
	int k = 0;
	for (int i = 0; i < StudentList.size(); i++)
	{
		sum += StudentList[i].m_GetMiddleEstimation();
		k++;
	}
	return (sum / k);
}


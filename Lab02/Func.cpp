#include "Func.hpp"
using namespace std;
bool RunMenu = true;
int const ListsAmount = 500;
int Counter = 0;
int Counter_2 = 0;
Student StudentList[ListsAmount];
Teacher TeacherList[ListsAmount];
Course BasicCourse;
void LocalInformation()
{
	Counter = 3;
	Counter_2 = 3;
	BasicCourse.m_SetTitle("История");
	BasicCourse.m_SetDescription("ИУК4-12Б");
	StudentList[0].m_SetName("Егор");
	StudentList[0].m_SetSurname("Казанцев");
	StudentList[0].m_SetAge(101);
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
	StudentList[Counter++]=BufferStudent;
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
	Teacher BufferTeacher = Teacher(TeacherName,TeacherSurname,TeacherLogin,TeacherPassword,TeacherAge);
	TeacherList[Counter_2++] = BufferTeacher;
	return true;
}
void CourseAboutTable()
{
	int TitleLength = BasicCourse.m_GetTitle().length();
	int DescriptionLength = BasicCourse.m_GetDescription().length();
	cout << setw(TitleLength) << left << BasicCourse.m_GetTitle() << '|' << setw(DescriptionLength) << left << BasicCourse.m_GetDescription() << "|Средняя оценка студентов за курс-" << setw(1) << BasicCourse.m_GetCourseEstimation() << endl;
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
	for (int i = 0; i < Counter; i++)
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
	for (int i = 0; i < Counter; i++)
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
	for (int j = 0; j < Counter; j++)
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
		for (int i = 0; i < Counter; i++)
		{
			StudentList[i].m_CheckAge(StudentList[i].m_GetAge(), i);
		}
		for (int i = 0; i < Counter; i++)
		{
			TeacherList[i].m_CheckAge(TeacherList[i].m_GetAge(), i);
		}
		cout << "Вернуться 1-Да 0-Нет" << endl;
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
	for (int i = 0; i < Counter_2; i++)
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
	for (int i = 0; i < Counter_2; i++)
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
	for (int j = 0; j < Counter_2; j++)
	{
		cout << "|" << setw(MaxNameSurnameCol) << left <<TeacherList[j]<< "|" << setw(MaxAgeLength + 1) << left << TeacherList[j].m_GetAge() << "|" << setw(MaxLoginLength) << left << TeacherList[j].m_GetLogin()
			<< "|" << setw(MaxPasswordLength) << left << TeacherList[j].m_GetPassword() << '|' << endl;
	}
}

void CalcCourse()
{
	int sum = 0;
	int k = 0;
	for (int i = 0; i < Counter; i++)
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
	cout << "Сколько студентов добавим?" << endl;
	cin >> StudentAmount;
	for (int i=0;i<StudentAmount;i++)
	{
		InputStudentInfo();
	}
	cout << "Сколько преподавателей добавим?" << endl;
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
		cout << "Студенты" << endl;
		StudentsTable();
		cout << "Преподаватели" << endl;
		TeachersTable();
		cout << "Вернуться 1-Да 0-Нет" << endl;
		cin >> iflag;
		if (iflag == 1) {
			flag = false;
		}
	}
	return true;
}

bool AppendPeople()
{
	int Checker = 0;
	Student BufferStudent;
	Teacher BufferTeacher;
	cout << "1. Студента" << endl;
	cout << "2. Преподавателя\n>>> ";
	cin >> Checker;
	switch (Checker)
	{
	case 1:
		cout << "Введите информацию(Имя, фамилия, возраст, средняя оценка, курс, логин, пароль)" << endl;
		cin >> BufferStudent;
		StudentList[Counter++] = BufferStudent;
		break;
	case 2:
		cout << "Введите информацию(Имя, фамилия, возраст, логин, пароль)" << endl;
		cin >> BufferTeacher;
		TeacherList[Counter_2++] = BufferTeacher;
		break;
	}	
	return true;
}
bool RemoveStorTc()
{
	int Checker = 0;
	int StIn = 0;
	int TcIn = 0;
	cout << "1. Студента" << endl;
	cout << "2. Преподавателя\n>>> ";
	cin >> Checker;
	switch (Checker)
	{
	case 1:
		cout << "Какого студента удалить?" << endl;
		cin >> StIn;
		for (int i = StIn; i < Counter - 1; i++)
		{
			StudentList[i] = StudentList[i + 1];
		}
		Counter--;
		break;
	case 2:
		cout << "Какого преподавателя удалить?" << endl;
		cin >> TcIn;
		for (int i = TcIn; i < Counter_2 - 1; i++)
		{
			TeacherList[i] = TeacherList[i + 1];
		}
		Counter_2--;
		break;
	}
	return true;
}

bool Sort()
{
	for (int i = 0; i < Counter_2; i++)
	{
		for (int j = i + 1; j < Counter_2; j++)
		{
			if (TeacherList[i] > TeacherList[j])
			{
				Teacher temp = TeacherList[i];
				TeacherList[i] = TeacherList[j];
				TeacherList[j] = temp;
			}
		}
	}
	for (int i = 0; i < Counter; i++)
	{
		for (int j = i + 1; j < Counter; j++)
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

#include "Func.hpp"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Student>StudentList;
	vector<Teacher>TeacherList;
	Course BasicCourse;
	int StudentsAmount = 0;
	int TeachersAmount = 0;
	int CheckMenu = 0;
	bool RunMenu = true;
	StudentList.resize(3);
	TeacherList.resize(3);
	LocalInformation(StudentList, TeacherList, BasicCourse);
	BasicCourse.m_SetCourseEstimation(CalcCourse(StudentList));
	while (RunMenu == true)
	{
		MenuTable();
		cin >> CheckMenu;
		switch (CheckMenu)
		{
		case 1:
			system("cls");
			InputCourseInfo(BasicCourse);
			cout << "Теперь разберемся с составом курса." << endl;
			cout << "Сколько студентов добавим на курс?\n---> ";
			cin >> StudentsAmount;
			for (int i = 0; i < StudentsAmount; i++)
			{
				StudentList.push_back(InputStudentInfo());
			}
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
			system("cls");
			if (TeacherList.size() == 0 || StudentList.size() == 0)
			{
				cout << "Недостаточно информации!" << endl;
				break;
			}
			else
			{
				CourseAboutTable(BasicCourse);
				cout << "Состав\n" << endl;
				cout << "Студенты:" << endl;
				StudentsTable(StudentList);
				cout << "Преподаватели:" << endl;
				TeachersTable(TeacherList);
				ContinueOrNot();
				break;
			}
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
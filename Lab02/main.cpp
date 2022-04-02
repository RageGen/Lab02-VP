#include "Func.hpp"
#include "Menu.hpp"
#include "Item.hpp"
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
	const int ItemsNumber = 1;
	bool RunMenu = true;
	StudentList.resize(3);
	TeacherList.resize(3);
	LocalInformation(StudentList, TeacherList, BasicCourse);
	BasicCourse.m_SetCourseEstimation(CalcCourse(StudentList));
	ZDA::Item Items[ItemsNumber]{ ZDA::Item { "Ввод информации о студенте",InputStudentInfo(StudentList) } };
}

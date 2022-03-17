#include "Course.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include <Windows.h>
#include <iomanip>
Student InputStudentInfo();
Teacher InputTeacherInfo();
void CourseAboutTable();
void InputCourseInfo();
void StudentsTable(vector<Student>& StudentList);
void MenuTable();
void CheckAge(vector<Teacher>& TeacherList, vector<Student>& StudentList);
void TeachersTable(vector<Teacher>& TeacherList);
void ContinueOrNot();
void CalcCourse(vector<Student>& StudentList);
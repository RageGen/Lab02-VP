#pragma once
#include "Course.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include <Windows.h>
#include <iomanip>
Student InputStudentInfo();
Teacher InputTeacherInfo();
void CourseAboutTable(Course);
void InputCourseInfo(Course);
void StudentsTable(std::vector<Student>& StudentList);
void MenuTable();
void CheckAge(std::vector<Teacher>& TeacherList, std::vector<Student>& StudentList);
void TeachersTable(std::vector<Teacher>& TeacherList);
void ContinueOrNot();
int CalcCourse(std::vector<Student>& StudentList);
void LocalInformation(std::vector<Student>& StudentList, std::vector<Teacher>& TeacherList, Course& BasicCourse);
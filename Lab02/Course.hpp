#include <string>
#include <iostream>
#pragma once
class Course
{
private:
	std::string m_CourseTitle;
	std::string m_CourseDescription;
	int m_CourseEstimation;
public:
	std::string m_GetTitle();
	std::string m_GetDescription();
	int m_GetCourseEstimation();
	void m_SetCourseEstimation(int);
	Course(std::string, std::string);
	Course();
};
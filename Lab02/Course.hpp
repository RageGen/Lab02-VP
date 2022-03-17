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
	void m_SetTitle(std::string);
	void m_SetDescription(std::string);
	Course(std::string, std::string);
	Course();
};
#include "Course.hpp"
Course::Course(std::string title, std::string description)
{
	m_CourseTitle = title;
	m_CourseDescription = description;
}
Course::Course()
{
}
int Course::m_GetCourseEstimation()
{
	return m_CourseEstimation;
}
bool Course::m_SetCourseEstimation(int Estimation)
{
	if (Estimation < 0||Estimation==0)
	{
		return false;
	}
	else
	{
		m_CourseEstimation = Estimation;
		return true;
	}
}
void Course::m_SetTitle(std::string Title)
{
	m_CourseTitle = Title;
}
void Course::m_SetDescription(std::string Description)
{
	m_CourseDescription = Description;
}
std::string Course::m_GetDescription()
{
	return m_CourseDescription;
}
std::string Course::m_GetTitle() 
{
	return m_CourseTitle;
}
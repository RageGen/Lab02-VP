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
void Course::m_SetCourseEstimation(int Estimation)
{
	m_CourseEstimation = Estimation;
}
std::string Course::m_GetDescription()
{
	return m_CourseDescription;
}
std::string Course::m_GetTitle() 
{
	return m_CourseTitle;
}
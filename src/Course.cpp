#include "Course.h"
#include <iostream>
#include <iomanip>

Course::Course() : m_courseCode(""), m_courseTitle(""), m_courseCreditHours(0) {}

Course::Course(std::string code, std::string title, int credits)
    : m_courseCode(code), m_courseTitle(title), m_courseCreditHours(credits) {}

void Course::setCourseCode(const std::string& code) { m_courseCode = code; }
void Course::setCourseTitle(const std::string& title) { m_courseTitle = title; }
void Course::setCourseCreditHours(int credits) { m_courseCreditHours = credits; }

void Course::displayCourseInfo() const {
    std::cout << std::left << std::setw(10) << m_courseCode 
              << std::setw(25) << m_courseTitle 
              << "Credits: " << m_courseCreditHours << std::endl;
}
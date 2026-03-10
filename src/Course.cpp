#include "Course.h"
#include <iomanip>

Course::Course() : m_courseCode(0), m_courseTitle("N/A"), m_courseCreditHours(0) {}

Course::Course(int code, std::string title, int credits) {
    setCourseCode(code);
    setCourseTitle(title);
    setCourseCreditHours(credits);
}

void Course::setCourseCreditHours(int credits) {
    // Logic: Một môn học thường có từ 1 đến 6 tín chỉ
    if (credits < 1 || credits > 10) {
        m_courseCreditHours = 3; // Mặc định 3 tín nếu nhập sai
    } else {
        m_courseCreditHours = credits;
    }
}

void Course::displayCourseInfo() const {
    std::cout << "| " << std::setw(8)  << m_courseCode 
              << " | " << std::setw(25) << m_courseTitle 
              << " | " << std::setw(4)  << m_courseCreditHours << " TC |" << std::endl;
}

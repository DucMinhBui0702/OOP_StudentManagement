#include "Course.h"
#include <iomanip>
#include <stdexcept>

// Constructor mặc định: Khởi tạo giá trị an toàn
Course::Course() 
    : m_courseCode(0), m_courseTitle("N/A"), m_courseCreditHours(0) {}

// Constructor đầy đủ: Dùng const string& để tối ưu như Student
Course::Course(int code, const std::string& title, int credits) {
    setCourseCode(code);
    setCourseTitle(title);
    setCourseCreditHours(credits);
}

// --- SETTERS (Phần logic Minh yêu cầu giống Student) ---

void Course::setCourseCode(int code) {
    if (code < 0) throw std::invalid_argument("Mã môn học không được âm!");
    m_courseCode = code;
}

void Course::setCourseTitle(const std::string& title) {
    // Tối ưu bộ nhớ bằng cách dùng tham chiếu hằng
    m_courseTitle = title;
}

void Course::setCourseCreditHours(int credits) {
    // Validation tương tự logic của năm sinh/gpa bên Student
    if (credits < 1 || credits > 15) {
        m_courseCreditHours = 3; // Mặc định nếu nhập sai logic
    } else {
        m_courseCreditHours = credits;
    }
}

// --- GETTERS ---
int Course::getCourseCode() const { return m_courseCode; }
std::string Course::getCourseTitle() const { return m_courseTitle; }
int Course::getCourseCreditHours() const { return m_courseCreditHours; }

// --- DISPLAY (Kẻ bảng giống Student cho An làm UI) ---
void Course::displayCourseInfo() const {
    std::cout << "| " << std::left << std::setw(10) << m_courseCode 
              << "| " << std::setw(25) << m_courseTitle 
              << "| " << std::setw(5)  << m_courseCreditHours << " TC |" << std::endl;
}

#include "Course.h"
#include <iomanip>
#include <stdexcept>

// Constructor mặc định: Khởi tạo giá trị an toàn
Course::Course() 
    : m_courseCode(0), m_courseTitle("N/A"), m_courseCreditHours(0) {}

// Constructor đầy đủ:
Course::Course(int code, const std::string& title, int credits) 
    : m_courseTitle(title) { // đã sửa nhe 
    setCourseCode(code);
    setCourseCreditHours(credits);
}

// --- SETTERS (Phần logic Minh yêu cầu đồng bộ với Student) ---

void Course::setCourseCode(int code) {
    // Validation: Mã môn học không được âm
    if (code < 0) throw std::invalid_argument("Mã môn học không được âm!");
    m_courseCode = code;
}

void Course::setCourseTitle(const std::string& title) {
    // Tối ưu bộ nhớ bằng cách dùng tham chiếu hằng
    m_courseTitle = title;
}

void Course::setCourseCreditHours(int credits) {
    // Logic kiểm tra số tín chỉ hợp lệ
    if (credits < 1 || credits > 15) {
        m_courseCreditHours = 3; // Giá trị mặc định nếu nhập sai
    } else {
        m_courseCreditHours = credits;
    }
}

// --- GETTERS ---
int Course::getCourseCode() const { return m_courseCode; }
std::string Course::getCourseTitle() const { return m_courseTitle; }
int Course::getCourseCreditHours() const { return m_courseCreditHours; }

// --- DISPLAY (Sử dụng setw để kẻ bảng chuyên nghiệp như Student) ---
void Course::displayCourseInfo() const {
    // Dùng iomanip để căn lề chuẩn cho UI của An
    std::cout << "| " << std::left << std::setw(10) << m_courseCode 
              << "| " << std::setw(25) << m_courseTitle 
              << "| " << std::setw(5)  << m_courseCreditHours << " TC |" << std::endl;
}

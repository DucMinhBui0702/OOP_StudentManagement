#include "Student.h"
#include <iomanip>
#include <stdexcept> // Thư viện để ném lỗi logic

// Constructor mặc định
Student::Student() 
    : m_studentID(0), m_studentName("Unknown"), m_studentAge(18), 
      m_studentMajor("N/A"), m_studentGPA(0.0), m_studentNumber("0000000000") {}

// Constructor đầy đủ với Validation
Student::Student(int id, std::string name, int age, std::string major, float gpa, std::string phone) {
    setStudentID(id);
    setStudentName(name);
    setStudentAge(age);
    setStudentMajor(major);
    setStudentGPA(gpa);
    setStudentNumber(phone);
}

// Logic cho GPA: Nếu sai thì đặt về 0 và thông báo nhẹ
void Student::setStudentGPA(float gpa) {
    if (gpa < 0.0f || gpa > 4.0f) {
        m_studentGPA = 0.0f;
    } else {
        m_studentGPA = gpa;
    }
}

void Student::setStudentAge(int age) {
    // Logic: Sinh viên đại học thường từ 17-50 tuổi
    m_studentAge = (age >= 17 && age <= 60) ? age : 18;
}

void Student::setStudentID(int id) {
    if (id < 0) throw std::invalid_argument("ID không được là số âm!");
    m_studentID = id;
}

// Cải tiến hàm hiển thị: Căn lề chuẩn để An làm UI Console dễ dàng hơn
void Student::displayStudentInfo() const {
    std::cout << "| " << std::setw(6)  << m_studentID 
              << " | " << std::setw(20) << m_studentName 
              << " | " << std::setw(4)  << m_studentAge 
              << " | " << std::setw(15) << m_studentMajor 
              << " | " << std::setw(5)  << std::fixed << std::setprecision(2) << m_studentGPA 
              << " | " << std::setw(12) << m_studentNumber << " |" << std::endl;
}

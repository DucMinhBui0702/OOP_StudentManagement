#include "Student.h"
#include <iomanip>
#include <stdexcept>

// Constructor mặc định: Dùng Member Initializer List
Student::Student() 
    : m_studentID("0"), 
      m_studentName("Unknown"), 
      m_studentBirthYear(2005), 
      m_studentMajor("N/A"), 
      m_studentGPA(0.0), 
      m_studentNumber("0000000000") {}

// Constructor đầy đủ: Tối ưu với const string& và Initializer List
Student::Student(const std::string& id, const std::string& name, int birthYear, 
                const std::string& major, double gpa, const std::string& phone)
    : m_studentID(id), 
      m_studentName(name), 
      m_studentMajor(major), 
      m_studentGPA(gpa), 
      m_studentNumber(phone) {
    
    // Riêng BirthYear vẫn cần qua hàm set để kiểm tra tính hợp lệ (Validation)
    setStudentBirthYear(birthYear);
}

// Logic cho Năm sinh
void Student::setStudentBirthYear(int birthYear) {
    if (birthYear < 1900 || birthYear > 2026) {
        m_studentBirthYear = 2005; // Giá trị mặc định an toàn
    } else {
        m_studentBirthYear = birthYear;
    }
}

// Các Setter dùng const string& theo yêu cầu của Minh
void Student::setStudentID(const std::string& id) { m_studentID = id; }
void Student::setStudentName(const std::string& name) { m_studentName = name; }
void Student::setStudentMajor(const std::string& major) { m_studentMajor = major; }
void Student::setStudentNumber(const std::string& phone) { m_studentNumber = phone; }

// Getters (Đã bổ sung getStudentMajor bị thiếu)
std::string Student::getStudentID() const { return m_studentID; }
std::string Student::getStudentName() const { return m_studentName; }
int Student::getStudentBirthYear() const { return m_studentBirthYear; }
std::string Student::getStudentMajor() const { return m_studentMajor; }
double Student::getStudentGPA() const { return m_studentGPA; }
std::string Student::getStudentNumber() const { return m_studentNumber; }

// Hiển thị bảng chuẩn UI với setw và định dạng GPA
void Student::displayStudentInfo() const {
    std::cout << "| " << std::left << std::setw(10) << m_studentID 
              << "| " << std::setw(20) << m_studentName 
              << "| " << std::setw(6)  << m_studentBirthYear 
              << "| " << std::setw(15) << m_studentMajor 
              << "| " << std::setw(5)  << std::fixed << std::setprecision(2) << m_studentGPA 
              << "| " << std::setw(12) << m_studentNumber << " |" << std::endl;
}
// Thêm vào cuối file Student.cpp
std::string Student::toDataLine() const {
    // Thứ tự: ID, Tên, Năm sinh, Ngành, GPA, Số điện thoại
    // Dùng dấu phẩy để Minh dễ dùng getline(ss, token, ',')
    return m_studentID + "," + 
           m_studentName + "," + 
           std::to_string(m_studentBirthYear) + "," + 
           m_studentMajor + "," + 
           std::to_string(m_studentGPA) + "," + 
           m_studentNumber;
}

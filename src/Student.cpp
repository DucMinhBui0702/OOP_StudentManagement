#include "Student.h"
#include <iomanip>
#include <stdexcept>

// Constructor mặc định
Student::Student() 
    : m_studentID("0"), m_studentName("Unknown"), m_studentBirthYear(2005), 
      m_studentMajor("N/A"), m_studentGPA(0.0), m_studentNumber("0000000000") {}

// Constructor đầy đủ
Student::Student(const std::string& id, const std::string& name, int birthYear, 
                const std::string& major, double gpa, const std::string& phone) {
    m_studentID = id;
    m_studentName = name;
    setStudentBirthYear(birthYear);
    m_studentMajor = major;
    m_studentGPA = gpa; // Gán trực tiếp, không dùng setter vì đã bỏ hàm đó
    m_studentNumber = phone;
}

// Logic cho Năm sinh
void Student::setStudentBirthYear(int birthYear) {
    if (birthYear < 1900 || birthYear > 2026) {
        m_studentBirthYear = 2005; // Giá trị mặc định an toàn
    } else {
        m_studentBirthYear = birthYear;
    }
}

// Các Setter tối ưu với const string&
void Student::setStudentID(const std::string& id) { m_studentID = id; }
void Student::setStudentName(const std::string& name) { m_studentName = name; }
void Student::setStudentMajor(const std::string& major) { m_studentMajor = major; }
void Student::setStudentNumber(const std::string& phone) { m_studentNumber = phone; }

// Getters
std::string Student::getStudentID() const { return m_studentID; }
std::string Student::getStudentName() const { return m_studentName; }
int Student::getStudentBirthYear() const { return m_studentBirthYear; }
double Student::getStudentGPA() const { return m_studentGPA; }
std::string Student::getStudentNumber() const { return m_studentNumber; }

// Hàm tính tuổi bổ trợ (Optionally)
int Student::getAge() const {
    return 2026 - m_studentBirthYear;
}

// Cải tiến hiển thị theo đúng yêu cầu UI
void Student::displayStudentInfo() const {
    std::cout << "| " << std::left << std::setw(10) << m_studentID 
              << "| " << std::setw(20) << m_studentName 
              << "| " << std::setw(6)  << m_studentBirthYear 
              << "| " << std::setw(15) << m_studentMajor 
              << "| " << std::setw(5)  << std::fixed << std::setprecision(2) << m_studentGPA 
              << "| " << std::setw(12) << m_studentNumber << " |" << std::endl;
}

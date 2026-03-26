#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student() : m_studentID(""), m_studentName(""), m_studentAge(0), 
                     m_studentMajor(""), m_studentGPA(0.0f), m_studentNumber("") {}

Student::Student(std::string id, std::string name, int age, std::string major, float gpa, std::string phone)
    : m_studentID(id), m_studentName(name), m_studentAge(age), 
      m_studentMajor(major), m_studentGPA(gpa), m_studentNumber(phone) {}

// Setters với Const Reference
void Student::setStudentID(const std::string& id) { m_studentID = id; }
void Student::setStudentName(const std::string& name) { m_studentName = name; }
void Student::setStudentAge(int age) { m_studentAge = age; }
void Student::setStudentMajor(const std::string& major) { m_studentMajor = major; }
void Student::setStudentGPA(float gpa) { m_studentGPA = gpa; }
void Student::setStudentNumber(const std::string& phone) { m_studentNumber = phone; }

void Student::displayStudentInfo() const {
    std::cout << std::left << std::setw(12) << m_studentID 
              << std::setw(20) << m_studentName 
              << std::setw(6) << m_studentAge 
              << std::setw(15) << m_studentMajor 
              << std::setw(6) << std::fixed << std::setprecision(2) << m_studentGPA 
              << std::setw(15) << m_studentNumber << std::endl;
}
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <iomanip>

class Student {
private:
    std::string m_studentID;     // VD: "SE180001"
    std::string m_studentName;
    int m_studentAge;
    std::string m_studentMajor;
    float m_studentGPA;
    std::string m_studentNumber; // Số điện thoại liên lạc

public:
    Student();
    Student(std::string id, std::string name, int age, std::string major, float gpa, std::string phone);

    // Getters
    std::string getStudentID() const { return m_studentID; }
    std::string getStudentName() const { return m_studentName; }
    int getStudentAge() const { return m_studentAge; }
    std::string getStudentMajor() const { return m_studentMajor; }
    float getStudentGPA() const { return m_studentGPA; }
    std::string getStudentNumber() const { return m_studentNumber; }

    // Setters - Truyền tham số hằng (const reference) để tránh copy vô ích (MISRA-friendly)
    void setStudentID(const std::string& id);
    void setStudentName(const std::string& name);
    void setStudentAge(int age);
    void setStudentMajor(const std::string& major);
    void setStudentGPA(float gpa);
    void setStudentNumber(const std::string& phone);

    void displayStudentInfo() const;
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string m_studentID;
    std::string m_studentName;
    int m_studentBirthYear;      // Đã đổi tên
    std::string m_studentMajor;
    double m_studentGPA;         // Kiểu double
    std::string m_studentNumber;

public:
    Student();
    Student(const std::string& id, const std::string& name, int birthYear, 
            const std::string& major, double gpa, const std::string& phone);

    // Getters
    std::string getStudentID() const;
    std::string getStudentName() const;
    int getStudentBirthYear() const;
    double getStudentGPA() const;
    std::string getStudentNumber() const;

    // Setters 
    void setStudentID(const std::string& id);
    void setStudentName(const std::string& name);
    void setStudentBirthYear(int birthYear);
    void setStudentMajor(const std::string& major);
    void setStudentNumber(const std::string& phone);

    void displayStudentInfo() const;
};

#endif

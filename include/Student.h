#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
    
    friend class StudentEnrollment;
    friend class SystemManager;

private:
    std::string m_studentID;
    std::string m_studentName;
    int m_studentBirthYear;
    std::string m_studentMajor;
    double m_studentGPA;
    std::string m_studentNumber;

public:
    Student();
    Student(const std::string& id, const std::string& name, int birthYear, 
            const std::string& major, double gpa, const std::string& phone);

    // Getters
    std::string getStudentID() const;
    std::string getStudentName() const;
    int getStudentBirthYear() const;
    std::string getStudentMajor() const; // Đã thêm
    double getStudentGPA() const;
    std::string getStudentNumber() const;

    // Setters - Dùng const string& và đã bỏ setGPA theo yêu cầu của Minh
    void setStudentID(const std::string& id);
    void setStudentName(const std::string& name);
    void setStudentBirthYear(int birthYear);
    void setStudentMajor(const std::string& major);
    void setStudentNumber(const std::string& phone);

    void displayStudentInfo() const;
};

#endif

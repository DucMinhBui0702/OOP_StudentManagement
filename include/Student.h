#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
    // Cho phép các lớp quản lý truy cập trực tiếp vào private members
    friend class Enrollment;
    friend class SystemManager;

private:
    std::string m_studentID;
    std::string m_studentName;
    int m_studentBirthYear;
    std::string m_studentMajor;
    double m_studentGPA;
    std::string m_studentNumber;

public:
    // Constructors
    Student();
    Student(const std::string& id, const std::string& name, int birthYear, 
            const std::string& major, double gpa, const std::string& phone);

    // Getters
    std::string getStudentID() const;
    std::string getStudentName() const;
    int getStudentBirthYear() const;
    std::string getStudentMajor() const;
    double getStudentGPA() const;
    std::string getStudentNumber() const;

    // Setters
    void setStudentID(const std::string& id);
    void setStudentName(const std::string& name);
    void setStudentBirthYear(int birthYear);
    void setStudentMajor(const std::string& major);
    void setStudentNumber(const std::string& phone);

    // Methods
    void displayStudentInfo() const;
    
    // Hàm Minh yêu cầu để lưu file .txt
    std::string toDataLine() const;
};

#endif

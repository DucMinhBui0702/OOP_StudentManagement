#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    int m_studentID;
    std::string m_studentName;
    int m_studentAge;
    std::string m_studentMajor;
    float m_studentGPA;
    std::string m_studentNumber;

public:
    // Constructor
    Student();
    Student(int id, std::string name, int age, std::string major, float gpa, std::string phone);

    // Getters
    int getStudentID() const;
    std::string getStudentName() const;
    int getStudentAge() const;
    std::string getStudentMajor() const;
    float getStudentGPA() const;
    std::string getStudentNumber() const;

    // Setters
    void setStudentID(int id);
    void setStudentName(std::string name);
    void setStudentAge(int age);
    void setStudentMajor(std::string major);
    void setStudentGPA(float gpa);
    void setStudentNumber(std::string phone);

    // Display
    void displayStudentInfo() const;
};

#endif

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Student.h"
#include "Course.h"
#include "Enrollment.h"

class SystemManager {
private:
    // Dùng shared_ptr để quản lý lifetime của Student và Course khi được trỏ bởi Enrollment
    std::vector<std::shared_ptr<Student>> m_vStudent;
    std::vector<std::shared_ptr<Course>> m_vCourse;
    std::vector<StudentEnrollment> m_vStudentEnrollment;

public:
    // Quản lý Student
    void addStudent(const Student& s);
    void removeStudent(const std::string& studentID);
    std::shared_ptr<Student> findStudent(const std::string& studentID) const;

    // Quản lý Course
    void addCourse(const Course& c);
    std::shared_ptr<Course> findCourse(const std::string& courseCode) const;

    // Đăng ký học (Liên kết logic)
    void enroll(const std::string& studentID, const std::string& courseCode, double grade);

    // File I/O
    void saveToFile(const std::string& filename, bool isBinary = false);
    void loadFromFile(const std::string& filename, bool isBinary = false);

    // Getters phục vụ UI
    const std::vector<std::shared_ptr<Student>>& getStudentList() const { return m_vStudent; }
};

#endif
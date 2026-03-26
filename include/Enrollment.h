#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "Student.h"
#include "Course.h"
#include <memory>
#include <vector>

struct StudentEnrollment {
    std::shared_ptr<Student> m_ptrStudent;
    std::shared_ptr<Course> m_ptrCourse;
    double m_courseGrade;

    StudentEnrollment(std::shared_ptr<Student> s, std::shared_ptr<Course> c, double grade)
        : m_ptrStudent(s), m_ptrCourse(c), m_courseGrade(grade) {}
};

// Lớp tiện ích quản lý logic Enrollment
class EnrollmentManager {
public:
    // Tính toán GPA dựa trên danh sách các môn đã học (Weighted Average)
    static double calculateOverallGPA(const std::string& studentID, const std::vector<StudentEnrollment>& enrollments);
    static void displayEnrollmentRecord(const StudentEnrollment& e);
};

#endif
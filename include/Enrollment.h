#ifndef STUDENT_ENROLLMENT_H
#define STUDENT_ENROLLMENT_H
#include<iostream>
#include<string>
#include<vector>
#include<memory>

#include "Student.h"
#include "Course.h"

struct StudentEnrollment {
    std::shared_ptr<Student> m_ptrStudent;
    std::shared_ptr<Course> m_ptrCourse;
    double m_courseGrade;
    StudentEnrollment(): m_courseGrade(0.0) {}
    StudentEnrollment(std::shared_ptr<Student> ptrStudent, std::shared_ptr<Course> ptrCourse):
    m_ptrStudent(ptrStudent), m_ptrCourse(ptrCourse), m_courseGrade(0.0) {}
};

void CourseEnroll(std::shared_ptr<Student> ptrStudent, std::shared_ptr<Course> ptrCourse);
double getCourseGrade(std::shared_ptr<Student> ptrStudent, std::shared_ptr<Course> ptrCourse);
double getStudentGPA(std::shared_ptr<Student> ptrStudent);
#endif //STUDENT_ENROLLMENT_H
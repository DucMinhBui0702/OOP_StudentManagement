#include "Enrollment.h"
#include <iostream>

double EnrollmentManager::calculateOverallGPA(const std::string& studentID, const std::vector<StudentEnrollment>& enrollments) {
    double totalPoints = 0;
    int totalCredits = 0;
    bool found = false;

    for (const auto& e : enrollments) {
        if (e.m_ptrStudent->getStudentID() == studentID) {
            totalPoints += (e.m_courseGrade * e.m_ptrCourse->getCourseCreditHours());
            totalCredits += e.m_ptrCourse->getCourseCreditHours();
            found = true;
        }
    }

    return (totalCredits > 0) ? (totalPoints / totalCredits) : 0.0;
}

void EnrollmentManager::displayEnrollmentRecord(const StudentEnrollment& e) {
    std::cout << "Student: " << e.m_ptrStudent->getStudentName() 
              << " | Course: " << e.m_ptrCourse->getCourseTitle() 
              << " | Grade: " << e.m_courseGrade << std::endl;
}
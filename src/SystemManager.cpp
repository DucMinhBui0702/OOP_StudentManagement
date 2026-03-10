#include "include/SystemManager.h"
#include "include/Student.h"
#include "include/Course.h"
#include "include/Enrollment.h"
#include <iostream>
#include <algorithm>
#include <memory> // For shared_ptr
#include <numeric> // For std::accumulate

// Triển khai các hàm cho Student
void addStudent(std::vector<Student>& students, const Student& student) {
    students.push_back(student);
}

bool editStudent(std::vector<Student>& students, int id, const Student& newStudent) {
    for (Student& s : students) {
        if (s.getStudentID() == id) {
            s.setStudentName(newStudent.getStudentName());
            s.setStudentAge(newStudent.getStudentAge());
            s.setStudentMajor(newStudent.getStudentMajor());
            s.setStudentGPA(newStudent.getStudentGPA());
            s.setStudentNumber(newStudent.getStudentNumber());
            return true;
        }
    }
    return false;
}

Student* searchStudent(std::vector<Student>& students, int id) {
    for (Student& s : students) {
        if (s.getStudentID() == id) {
            return &s;
        }
    }
    return nullptr;
}

bool deleteStudent(std::vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].getStudentID() == id) {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

void sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getStudentID() < b.getStudentID();
    });
}

// Triển khai các hàm cho Course
void addCourse(std::vector<Course>& courses, const Course& course) {
    courses.push_back(course);
}

bool editCourse(std::vector<Course>& courses, int code, const Course& newCourse) {
    for (Course& c : courses) {
        if (c.getCourseCode() == code) {
            c.setCourseTitle(newCourse.getCourseTitle());
            c.setCourseCreditHours(newCourse.getCourseCreditHours());
            return true;
        }
    }
    return false;
}

Course* searchCourse(std::vector<Course>& courses, int code) {
    for (Course& c : courses) {
        if (c.getCourseCode() == code) {
            return &c;
        }
    }
    return nullptr;
}

bool deleteCourse(std::vector<Course>& courses, int code) {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i].getCourseCode() == code) {
            courses.erase(courses.begin() + i);
            return true;
        }
    }
    return false;
}

void sortCourses(std::vector<Course>& courses) {
    std::sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
        return a.getCourseCode() < b.getCourseCode();
    });
}

// Triển khai các hàm cho Enrollment

// Helper function to find StudentEnrollment by student and course IDs
Enrollment::StudentEnrollment* findStudentEnrollment(Enrollment& enrollment, int studentId, int courseCode) {
    for (auto& se : enrollment.m_studentEnrollments) {
        if (se.m_ptrStudent && se.m_ptrStudent->getStudentID() == studentId &&
            se.m_ptrCourse && se.m_ptrCourse->getCourseCode() == courseCode) {
            return &se;
        }
    }
    return nullptr;
}

bool registerEnrollment(Enrollment& enrollment, const std::vector<Student>& students, const std::vector<Course>& courses, int studentId, int courseCode) {
    // Check if student and course exist
    Student* studentPtr = nullptr;
    for (Student& s : students) {
        if (s.getStudentID() == studentId) {
            studentPtr = &s;
            break;
        }
    }

    Course* coursePtr = nullptr;
    for (Course& c : courses) {
        if (c.getCourseCode() == courseCode) {
            coursePtr = &c;
            break;
        }
    }

    if (!studentPtr || !coursePtr) {
        std::cerr << "Error: Student or Course not found." << std::endl;
        return false;
    }

    // Check if enrollment already exists
    if (findStudentEnrollment(enrollment, studentId, courseCode) != nullptr) {
        std::cout << "Enrollment already exists." << std::endl;
        return false;
    }

    // Create a new StudentEnrollment
    Enrollment::StudentEnrollment newEnrollment;
    newEnrollment.m_ptrStudent = std::make_shared<Student>(*studentPtr);  // Copy the student
    newEnrollment.m_ptrCourse = std::make_shared<Course>(*coursePtr);    // Copy the course
    newEnrollment.m_courseGrade = 0.0;  // Default grade

    // Add the new enrollment to the Enrollment object
    enrollment.m_studentEnrollments.push_back(newEnrollment);
    return true;
}


bool deleteEnrollment(Enrollment& enrollment, int studentId, int courseCode) {
    for (size_t i = 0; i < enrollment.m_studentEnrollments.size(); ++i) {
        if (enrollment.m_studentEnrollments[i].m_ptrStudent && enrollment.m_studentEnrollments[i].m_ptrStudent->getStudentID() == studentId &&
            enrollment.m_studentEnrollments[i].m_ptrCourse && enrollment.m_studentEnrollments[i].m_ptrCourse->getCourseCode() == courseCode) {
            enrollment.m_studentEnrollments.erase(enrollment.m_studentEnrollments.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<Enrollment::StudentEnrollment> searchEnrollmentsByStudent(const Enrollment& enrollment, int studentId) {
    std::vector<Enrollment::StudentEnrollment> results;
    for (const auto& se : enrollment.m_studentEnrollments) {
        if (se.m_ptrStudent && se.m_ptrStudent->getStudentID() == studentId) {
            results.push_back(se);
        }
    }
    return results;
}

std::vector<Enrollment::StudentEnrollment> searchEnrollmentsByCourse(const Enrollment& enrollment, int courseCode) {
    std::vector<Enrollment::StudentEnrollment> results;
    for (const auto& se : enrollment.m_studentEnrollments) {
        if (se.m_ptrCourse && se.m_ptrCourse->getCourseCode() == courseCode) {
            results.push_back(se);
        }
    }
    return results;
}

void printEnrollments(const Enrollment& enrollment) {
    for (const auto& se : enrollment.m_studentEnrollments) {
        if (se.m_ptrStudent && se.m_ptrCourse) {
            std::cout << "Student ID: " << se.m_ptrStudent->getStudentID() << std::endl;
            std::cout << "Course Code: " << se.m_ptrCourse->getCourseCode() << std::endl;
            std::cout << "Course Grade: " << se.m_courseGrade << std::endl;
            std::cout << "---" << std::endl;
        }
    }
}

// Implementation of Enrollment functions (moved from Enrollment.h for better separation)

void Enrollment::enrollStudent() {
    // This function is likely redundant now, as the registerEnrollment function in system_functions.cpp handles the enrollment process.
    std::cerr << "Warning: Enrollment::enrollStudent() is likely redundant. Use registerEnrollment() in system_functions.cpp." << std::endl;
}

double Enrollment::getCourseGrade() const {
    // This function likely doesn't belong in Enrollment class itself.  Should be accessed via StudentEnrollment
    std::cerr << "Warning: Enrollment::getCourseGrade() should be accessed via StudentEnrollment. Returning 0." << std::endl;
    return 0.0;
}

double Enrollment::getStudentGPA(const std::vector<Student>& students, const std::vector<Course>& courses) const {
  double totalCredits = 0.0;
  double weightedSum = 0.0;

  for (const auto& enrollment : m_studentEnrollments) {
    if (enrollment.m_ptrStudent && enrollment.m_ptrCourse) {
      double grade = enrollment.m_courseGrade;
      int creditHours = enrollment.m_ptrCourse->getCourseCreditHours();

      totalCredits += creditHours;
      weightedSum += grade * creditHours;
    }
  }

  if (totalCredits > 0) {
    return weightedSum / totalCredits;
  } else {
    return 0.0;
  }
}
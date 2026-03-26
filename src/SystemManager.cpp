#include "SystemManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// 1. Quản lý Student
void SystemManager::addStudent(const Student& s) {
    // Dùng make_shared để quản lý bộ nhớ an toàn (RAII)
    m_vStudent.push_back(std::make_shared<Student>(s));
}

void SystemManager::removeStudent(const std::string& studentID) {
    auto it = std::remove_if(m_vStudent.begin(), m_vStudent.end(),
        [&studentID](const std::shared_ptr<Student>& s) {
            return s->getStudentID() == studentID;
        });
    if (it != m_vStudent.end()) {
        m_vStudent.erase(it, m_vStudent.end());
    }
}

std::shared_ptr<Student> SystemManager::findStudent(const std::string& studentID) const {
    for (const auto& s : m_vStudent) {
        if (s->getStudentID() == studentID) return s;
    }
    return nullptr;
}

// 2. Quản lý Course
void SystemManager::addCourse(const Course& c) {
    m_vCourse.push_back(std::make_shared<Course>(c));
}

std::shared_ptr<Course> SystemManager::findCourse(const std::string& courseCode) const {
    for (const auto& c : m_vCourse) {
        if (c->getCourseCode() == courseCode) return c;
    }
    return nullptr;
}

// 3. Đăng ký học (Enrollment)
void SystemManager::enroll(const std::string& studentID, const std::string& courseCode, double grade) {
    auto student = findStudent(studentID);
    auto course = findCourse(courseCode);

    if (!student || !course) {
        throw std::runtime_error("Loi: Khong tim thay ma SV hoac ma Mon hoc!");
    }

    // Tao ban ghi enrollment moi
    m_vStudentEnrollment.emplace_back(student, course, grade);

    // Tu dong cap nhat GPA cho Student sau khi co diem moi
    double newGPA = EnrollmentManager::calculateOverallGPA(studentID, m_vStudentEnrollment);
    student->setStudentGPA(static_cast<float>(newGPA));
}

// 4. File I/O - Luu tat ca 3 danh sach theo yeu cau cua Minh
void SystemManager::saveToFile(const std::string& folder, bool isBinary) {
    // Luu Student
    std::ofstream sFile(folder + "/students.txt");
    for (const auto& s : m_vStudent) {
        sFile << s->getStudentID() << "|" << s->getStudentName() << "|" 
              << s->getStudentAge() << "|" << s->getStudentMajor() << "|" 
              << s->getStudentGPA() << "|" << s->getStudentNumber() << "\n";
    }

    // Luu Course
    std::ofstream cFile(folder + "/courses.txt");
    for (const auto& c : m_vCourse) {
        cFile << c->getCourseCode() << "|" << c->getCourseTitle() << "|" 
              << c->getCourseCreditHours() << "\n";
    }

    // Luu Enrollment
    std::ofstream eFile(folder + "/enrollments.txt");
    for (const auto& e : m_vStudentEnrollment) {
        eFile << e.m_ptrStudent->getStudentID() << "|" 
              << e.m_ptrCourse->getCourseCode() << "|" 
              << e.m_courseGrade << "\n";
    }
    
    std::cout << ">>> He thong da luu tat ca du lieu vao thu muc: " << folder << std::endl;
}

// 5. Load du lieu (Co ban)
void SystemManager::loadFromFile(const std::string& folder, bool isBinary) {
    // Luu y: Can doc Student va Course truoc khi doc Enrollment de re-link pointer
    std::cout << ">>> Dang tai du lieu tu thu muc: " << folder << "..." << std::endl;
    // (Phan trien khai load chi tiet co the bo sung theo nhu cau thuc te)
}
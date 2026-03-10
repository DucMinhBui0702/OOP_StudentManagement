#ifndef SYSTEM_HEADER_H
#define SYSTEM_HEADER_H
#include "include/Course.h"
#include "include/Student.h"
#include "include/Enrollment.h"    
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
// Khai báo các hàm cho Student

// Thêm một sinh viên mới
void addStudent(std::vector<Student>& students, const Student& student);

// Chỉnh sửa thông tin sinh viên
bool editStudent(std::vector<Student>& students, int id, const Student& newStudent);

// Tìm kiếm sinh viên theo ID
Student* searchStudent(std::vector<Student>& students, int id);

// Xóa sinh viên theo ID
bool deleteStudent(std::vector<Student>& students, int id);

// Sắp xếp danh sách sinh viên (ví dụ, theo ID)
void sortStudents(std::vector<Student>& students);




// Khai báo các hàm cho Course

// Thêm một khóa học mới
void addCourse(std::vector<Course>& courses, const Course& course);

// Chỉnh sửa thông tin khóa học
bool editCourse(std::vector<Course>& courses, int id, const Course& newCourse);

// Tìm kiếm khóa học theo ID
Course* searchCourse(std::vector<Course>& courses, int id);

// Xóa khóa học theo ID
bool deleteCourse(std::vector<Course>& courses, int id);

// Sắp xếp danh sách khóa học (ví dụ, theo ID)
void sortCourses(std::vector<Course>& courses);





// Khai báo các hàm cho Enrollment

// Đăng ký sinh viên vào một khóa học
bool registerEnrollment(std::vector<Enrollment>& enrollments, int student_id, int course_id);

// Hủy đăng ký sinh viên khỏi một khóa học
bool deleteEnrollment(std::vector<Enrollment>& enrollments, int student_id, int course_id);

// Tìm kiếm các enrollment của một sinh viên
std::vector<Enrollment> searchEnrollmentsByStudent(const std::vector<Enrollment>& enrollments, int student_id);

// Tìm kiếm các enrollment của một khóa học
std::vector<Enrollment> searchEnrollmentsByCourse(const std::vector<Enrollment>& enrollments, int course_id);

// In ra danh sách enrollment
void printEnrollments(const std::vector<Enrollment>& enrollments);

#endif 
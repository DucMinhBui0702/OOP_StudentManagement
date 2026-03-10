#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>

// Include các file, giả sử chúng nằm trong thư mục con "include":
#include "Student.h"
#include "Course.h"
#include "Enrollment.h"

// Khai báo trước (tùy chọn nhưng là một thói quen tốt)
class Student;
class Course;
class Enrollment;

// Khai báo hàm
void addStudent(std::vector<Student>& students, const Student& student);
bool editStudent(std::vector<Student>& students, int id, const Student& newStudent); // Đã sửa lỗi chính tả
Student* searchStudent(std::vector<Student>& students, int id);
bool deleteStudent(std::vector<Student>& students, int id);
void sortStudents(std::vector<Student>& students);

void addCourse(std::vector<Course>& courses, const Course& course);
bool editCourse(std::vector<Course>& courses, int code, const Course& newCourse);
Course* searchCourse(std::vector<Course>& courses, int code);
bool deleteCourse(std::vector<Course>& courses, int code);
void sortCourses(std::vector<Course>& courses);

bool registerEnrollment(Enrollment& enrollment, const std::vector<Student>& students, const std::vector<Course>& courses, int studentId, int courseCode); // Đã sửa và hoàn thành khai báo
bool deleteEnrollment(Enrollment& enrollment, int studentId, int courseCode);
std::vector<Enrollment::StudentEnrollment> searchEnrollmentsByStudent(const Enrollment& enrollment, int studentId);
std::vector<Enrollment::StudentEnrollment> searchEnrollmentsByCourse(const Enrollment& enrollment, int courseCode);
void printEnrollments(const Enrollment& enrollment);

#endif
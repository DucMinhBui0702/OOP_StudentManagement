#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
private:
    int m_courseCode;
    std::string m_courseTitle;
    int m_courseCreditHours;

public:
    // Constructor
    Course();
    Course(int code, const std::string& title, int credits);

    // Getters
    int getCourseCode() const;
    std::string getCourseTitle() const;
    int getCourseCreditHours() const;

    // Setters
    void setCourseCode(int code);
    //  Thêm const và & để tránh copy chuỗi vô ích
    void setCourseTitle(const std::string& title); 
    void setCourseCreditHours(int credits);

    // Display
    void displayCourseInfo() const;
};

#endif

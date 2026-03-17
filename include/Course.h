#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course {
    // Minh cũng cần quyền truy cập ở đây để quản lý môn học
    friend class Enrollment;
    friend class SystemManager;

private:
    int m_courseCode;
    std::string m_courseTitle;
    int m_courseCreditHours;

public:
    // Constructors
    Course();
    Course(int code, const std::string& title, int credits);

    // Getters
    int getCourseCode() const;
    std::string getCourseTitle() const;
    int getCourseCreditHours() const;

    // Setters
    void setCourseCode(int code);
    void setCourseTitle(const std::string& title);
    void setCourseCreditHours(int credits);

    // Methods
    void displayCourseInfo() const;
    
    // Hàm Minh yêu cầu để lưu file .txt
    std::string toDataLine() const;
};

#endif

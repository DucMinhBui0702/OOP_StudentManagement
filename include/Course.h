#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string m_courseCode;    // VD: "PCP291"
    std::string m_courseTitle;
    int m_courseCreditHours;

public:
    Course();
    Course(std::string code, std::string title, int credits);

    // Getters
    std::string getCourseCode() const { return m_courseCode; }
    std::string getCourseTitle() const { return m_courseTitle; }
    int getCourseCreditHours() const { return m_courseCreditHours; }

    // Setters
    void setCourseCode(const std::string& code);
    void setCourseTitle(const std::string& title);
    void setCourseCreditHours(int credits);

    void displayCourseInfo() const;
};

#endif
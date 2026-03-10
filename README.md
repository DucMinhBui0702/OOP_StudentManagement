# OOP_StudentManagement

Assignment Project of Group MAPL

Brief description of the project

## Team Roles

* **Minh**: Repo Manager, Slides, Code Review, MISRA check, Final Intergration
* **Long**: Development of `Student` and `Course` modules
* **Phong**: `Enrollment` logic and Grade management
* **An**: `SystemManager` implementation and `Console UI`

## Project structure

```OOP_StudentManagement
├── include/      # Header files (.h)
├── src/          # Source files (.cpp)
├── data/         # I/O Data files (.txt/.bin)
└── bin/          # Compiled executables
```

## Coding standards

### Naming conventions

* **Classes**: Use `PascalCase`: `Student`, `SystemManager`...
* **Methods/Function**: Use `camelCase`, start with a verb: `calculateGPA`, `displayInfo`...
* **Members Variables**: Use `m_camelCase`: `m_studentID`, `m_courseName`... 
* **Constants**: Use `UPPER_SNAKE_CASE`: `MAX_STUDENT`...
* **File**: Match with class name: `Student.txt`...

### Technic

* Don't use `namespace std` except in main.cpp
* Use smart pointers `unique_ptr` `shared_ptr`
* Follow RAII principles

## Github Workflow

1. Switch to your branch
2. Coding
3. `Commit` your work
4. `Push` to your branch
5. Open a `Pull Request`

### Branches

* **Long**: dev-student-course
* **Phong**: dev-enrollment
* **An**: dev-system

### Sync with main

1. Switch to your branch
2. Fetch origin: to update from GitHub Web
3. Branch -> Choose a branch to merge into -> main
4. Push origin

## Name

### Student

* **Attributes**:
    + int m_studentID;
    + string m_studentName;
    + int m_studentAge;
    + string m_studentMajor;
    + float m_studentGPA;
    + string m_studentNumber;
* **Function**:
    + Student();
    + int getStudentID();
    + string getStudentName();
    + int getStudentAge();
    + string getStudentMajor();
    + float getStudentGPA();
    + string getStudentNumber();
    + void setStudentID();
    + void setStudentName();
    + void setStudentAge();
    + void setStudentMajor();
    + void setStudentGPA();
    + void setStudentNumber();
    + void displayStudentInfo();

### Course

* **Attributes**:
    + int m_courseCode;
    + string m_courseTitle;
    + int m_courseCreditHours;
* **Functions**:
    + Course();
    + int getCourseCode();
    + string getCourseTitle();
    + int getCourseCreditHours;
    + void setCourseCode();
    + void setCourseTitle();
    + void setCourseCreditHours();
    + void displayCourseInfo();


### Enrollment

* **Attributes**:
    - Struct StudentEnrollment{
        + shared_ptr<Student> m_ptrStudent;
        + shared_ptr<Course> m_ptrCourse;

        double m_courseGrade;

        CourseEnrollment();
    }

* **Functions**:
    + void enrollStudent();
    + double getCourseGrade();
    + double getStudentGPA();

### System

* **Attributes**:
    + vector<Student> m_vStudent
    + vector<Course> m_vCourse
    + vector<StudentEnrollment> m_vStudentEnrollment

* **Function**:

### Console UI
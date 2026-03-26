#include <iostream>
#include <string>
#include <limits>
#include "SystemManager.h"
#include "Student.h"
#include "Course.h"

using namespace std; // Cho phép dùng namespace std duy nhất tại main.cpp theo README

void displayMenu() {
    cout << "\n===== FPT UNIVERSITY - STUDENT MANAGEMENT SYSTEM =====" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add Course" << endl;
    cout << "3. Enroll Student to Course (Calculate GPA)" << endl;
    cout << "4. Display All Students" << endl;
    cout << "5. Save Data to File" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
}

int main() {
    SystemManager manager;

    // 1. Tạo dữ liệu mẫu (Mock Data) để Minh test nhanh
    manager.addStudent(Student("SE180001", "Nguyen Van Minh", 20, "Auto Software", 0.0, "0912345678"));
    manager.addStudent(Student("SE180002", "Tran Hoang Long", 20, "AI Agent", 0.0, "0987654321"));
    manager.addCourse(Course("PCP292", "C++ Programming", 3));
    manager.addCourse(Course("AUT101", "AUTOSAR Basics", 4));

    int choice;
    string id, code, name, major, phone;
    int age, credits;
    double grade;

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter Student ID (e.g., SE123): "; cin >> id;
                    cin.ignore();
                    cout << "Enter Name: "; getline(cin, name);
                    cout << "Enter Age: "; cin >> age;
                    cout << "Enter Major: "; cin >> major;
                    cout << "Enter Phone: "; cin >> phone;
                    manager.addStudent(Student(id, name, age, major, 0.0, phone));
                    break;

                case 2:
                    cout << "Enter Course Code (e.g., PCP292): "; cin >> code;
                    cin.ignore();
                    cout << "Enter Title: "; getline(cin, name);
                    cout << "Enter Credits: "; cin >> credits;
                    manager.addCourse(Course(code, name, credits));
                    break;

                case 3:
                    cout << "Enter Student ID: "; cin >> id;
                    cout << "Enter Course Code: "; cin >> code;
                    cout << "Enter Grade (0-10): "; cin >> grade;
                    manager.enroll(id, code, grade);
                    cout << "Enrollment successful! Student GPA updated." << endl;
                    break;

                case 4:
                    cout << "\n" << left << setw(12) << "ID" << setw(20) << "Name" << setw(6) << "Age" 
                         << setw(15) << "Major" << setw(6) << "GPA" << setw(15) << "Phone" << endl;
                    cout << string(75, '-') << endl;
                    for (const auto& s : manager.getStudentList()) {
                        s->displayStudentInfo();
                    }
                    break;

                case 5:
                    manager.saveToFile("data");
                    cout << "Data saved successfully" << endl;
                    break;

                case 0:
                    cout << "Exiting... Goodbye Minh!" << endl;
                    return 0;

                default:
                    cout << "Invalid choice!" << endl;
            }
        } catch (const exception& e) {
            cerr << "\a[ERROR]: " << e.what() << endl; // Phát tiếng chuông báo lỗi và in thông báo
        }
    }

    return 0;
}
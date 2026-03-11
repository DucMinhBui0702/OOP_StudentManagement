#include<iostream>
#include "SystemManager.h"

int main() {
    SystemManager system;
    int choice;
    bool running = true;
    while (running) {
        std::cout << "--- Student Management System ---" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            
            case 6:
                running = false;
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    return 0;
}
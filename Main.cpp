#include "StudentManager.h"
#include <iostream>

int main() {
    StudentManager manager;
    int choice;

    do {
        std::cout << "\n1. Add Student\n2. Display All Students\n3. Search Student by ID\n";
        std::cout << "4. Update Student\n5. Delete Student\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                int id, age;
                std::string name, course;
                float gpa;

                std::cout << "Enter student ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter student name: "; std::getline(std::cin, name);
                std::cout << "Enter age: "; std::cin >> age;
                std::cin.ignore();
                std::cout << "Enter course: "; std::getline(std::cin, course);
                std::cout << "Enter GPA: "; std::cin >> gpa;

                Student student;
                student.setData(id, name, age, course, gpa);
                manager.addStudent(student);
                break;
            }
            case 2:
                manager.displayAllStudents();
                break;
            case 3: {
                int id;
                std::cout << "Enter student ID to search: "; std::cin >> id;
                manager.searchStudentById(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter student ID to update: "; std::cin >> id;
                std::cin.ignore();
                manager.updateStudentById(id);
                break;
            }
            case 5: {
                int id;
                std::cout << "Enter student ID to delete: "; std::cin >> id;
                manager.deleteStudentById(id);
                break;
            }
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

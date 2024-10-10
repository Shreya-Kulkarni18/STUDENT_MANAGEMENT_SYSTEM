#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

StudentManager::StudentManager() {
    loadFromFile();
}

StudentManager::~StudentManager() {
    saveToFile();
}

void StudentManager::addStudent(const Student &student) {
    students.push_back(student);
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    for (const auto &student : students) {
        student.displayData();
        std::cout << "-----------------------\n";
    }
}

void StudentManager::searchStudentById(int id) const {
    for (const auto &student : students) {
        if (student.getId() == id) {
            student.displayData();
            return;
        }
    }
    std::cout << "Student not found!\n";
}

void StudentManager::updateStudentById(int id) {
    for (auto &student : students) {
        if (student.getId() == id) {
            std::string name, course;
            int age;
            float gpa;
            std::cout << "Enter new name: "; std::getline(std::cin, name);
            std::cout << "Enter new age: "; std::cin >> age;
            std::cin.ignore();
            std::cout << "Enter new course: "; std::getline(std::cin, course);
            std::cout << "Enter new GPA: "; std::cin >> gpa;

            student.setData(id, name, age, course, gpa);
            std::cout << "Student updated successfully!\n";
            return;
        }
    }
    std::cout << "Student not found!\n";
}

void StudentManager::deleteStudentById(int id) {
    auto it = std::remove_if(students.begin(), students.end(), [id](const Student &s) { return s.getId() == id; });
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Student deleted successfully!\n";
    } else {
        std::cout << "Student not found!\n";
    }
}

void StudentManager::saveToFile() {
    std::ofstream ofs(filename);
    for (const auto &student : students) {
        ofs << student;
    }
}

void StudentManager::loadFromFile() {
    std::ifstream ifs(filename);
    if (ifs) {
        Student student;
        while (ifs >> student) {
            students.push_back(student);
        }
    }
}

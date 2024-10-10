#include "Student.h"
#include <iostream>

Student::Student() : id(0), age(0), gpa(0.0f) {}

void Student::setData(int id, const std::string &name, int age, const std::string &course, float gpa) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->course = course;
    this->gpa = gpa;
}

void Student::displayData() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age 
              << "\nCourse: " << course << "\nGPA: " << gpa << std::endl;
}

int Student::getId() const {
    return id;
}

std::ofstream &operator<<(std::ofstream &ofs, const Student &student) {
    ofs << student.id << "\n" << student.name << "\n" << student.age << "\n" 
        << student.course << "\n" << student.gpa << "\n";
    return ofs;
}

std::ifstream &operator>>(std::ifstream &ifs, Student &student) {
    ifs >> student.id;
    ifs.ignore();
    std::getline(ifs, student.name);
    ifs >> student.age >> student.course >> student.gpa;
    return ifs;
}

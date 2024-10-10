#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>
#include <string>

class StudentManager {
private:
    std::vector<Student> students;
    const std::string filename = "students.txt";

public:
    StudentManager();
    ~StudentManager();
    
    void addStudent(const Student &student);
    void displayAllStudents() const;
    void searchStudentById(int id) const;
    void updateStudentById(int id);
    void deleteStudentById(int id);
    void saveToFile();
    void loadFromFile();
};

#endif

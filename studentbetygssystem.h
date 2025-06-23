#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;          // Studentens namn
    std::vector<double> grades;  // Listan med betyg

public:
    Student(std::string name);  // Konstruktor för att skapa en student
    void addGrade(double grade); // Lägg till ett betyg för studenten
    double calculateAverage() const;  // Beräkna genomsnittet av betygen
    void displayStudentInfo() const;  // Visa studentens namn och genomsnitt
};

#endif

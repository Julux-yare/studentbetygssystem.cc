#include "Student.h"
#include <iostream>

Student::Student(std::string name) {
    this->name = name;  // Tilldela studentens namn
}

void Student::addGrade(double grade) {
    grades.push_back(grade);  // Lägger till ett betyg i listan
}

double Student::calculateAverage() const {
    if (grades.empty()) {
        return 0.0;  // Om inga betyg finns, returnera 0
    }

    double sum = 0;
    for (double grade : grades) {
        sum += grade;  // Summera alla betyg
    }
    return sum / grades.size();  // Returnera genomsnittet
}

void Student::displayStudentInfo() const {
    std::cout << "Student: " << name << "\n";
    std::cout << "Average Grade: " << calculateAverage() << "\n";  // Visa genomsnittsbetyget
}

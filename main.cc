#include <iostream>
#include "Student.h"

int main() {
    std::vector<Student> students;  // Lista över alla studenter
    int choice;

    do {
        std::cout << "\nStudent Grade Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Grade to Student\n";
        std::cout << "3. Show Student Info\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string name;
        double grade;

        switch (choice) {
            case 1: {
                std::cout << "Enter student name: ";
                std::cin.ignore();  // Rensa inmatningsbufferten
                std::getline(std::cin, name);  // Läs in studentens namn
                students.push_back(Student(name));  // Skapa en ny student och lägg till i listan
                std::cout << "Student added successfully.\n";
                break;
            }

            case 2: {
                std::cout << "Enter student name: ";
                std::cin.ignore();  // Rensa inmatningsbufferten
                std::getline(std::cin, name);  // Läs in studentens namn

                bool studentFound = false;
                for (Student& student : students) {
                    if (student.calculateAverage() == 0) {  // Kontrollera om studenten finns
                        std::cout << "Enter grade to add: ";
                        std::cin >> grade;
                        student.addGrade(grade);  // Lägg till betyget för studenten
                        studentFound = true;
                        std::cout << "Grade added successfully.\n";
                        break;
                    }
                }
                if (!studentFound) {
                    std::cout << "Student not found.\n";  // Om studenten inte finns
                }
                break;
            }

            case 3: {
                std::cout << "Enter student name: ";
                std::cin.ignore();  // Rensa inmatningsbufferten
                std::getline(std::cin, name);  // Läs in studentens namn

                bool studentFound = false;
                for (const Student& student : students) {
                    if (student.calculateAverage() == 0) {
                        student.displayStudentInfo();  // Visa studentens information
                        studentFound = true;
                        break;
                    }
                }
                if (!studentFound) {
                    std::cout << "Student not found.\n";  // Om studenten inte finns
                }
                break;
            }

            case 4:
                std::cout << "Exiting the program.\n";  // Avsluta programmet
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";  // Om användaren matar in ett ogiltigt alternativ
        }
    } while (choice != 4);  // Fortsätt tills användaren väljer att avsluta

    return 0;  // Programmet avslutas här
}

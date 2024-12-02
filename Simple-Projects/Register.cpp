/*
Student Management System in C++

This program allows users to manage a list of students. 
Features include:
1. Adding new students with their names, IDs, and grades.
2. Automatically calculating and displaying the average grade of each student.
3. Viewing all registered students with their details.

Example Interaction:
Student Management System:
1. Add Student
2. View Students
3. Exit
Choose an option: 1
Enter student name: John Doe
Enter student ID: 101
Enter number of grades: 3
Enter grade 1: 85
Enter grade 2: 90
Enter grade 3: 88
Student added successfully!

Student Management System:
1. Add Student
2. View Students
3. Exit
Choose an option: 2

Name: John Doe
ID: 101
Average Grade: 87.6667
----------------------
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class to store details of each student
class Student {
private:
    string name;
    int id;
    vector<float> grades;
    float average;

public:
    // Constructor
    Student(string name, int id, vector<float> grades)
        : name(name), id(id), grades(grades), average(0.0) {
        calculateAverage();
    }

    // Calculates the average grade
    void calculateAverage() {
        float sum = 0;
        for (float grade : grades) {
            sum += grade;
        }
        average = grades.empty() ? 0 : sum / grades.size();
    }

    // Displays student information
    void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAverage Grade: " << average << "\n";
    }
};

// Main function for managing the menu
int main() {
    vector<Student> students; // List of students
    int option; // Menu option

    do {
        // Display menu
        cout << "\nStudent Management System:\n1. Add Student\n2. View Students\n3. Exit\nChoose an option: ";
        cin >> option;

        if (option == 1) {
            string name;
            int id, numGrades;
            vector<float> grades;

            // Get student details
            cout << "Enter student name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, name);

            cout << "Enter student ID: ";
            cin >> id;

            cout << "Enter number of grades: ";
            cin >> numGrades;

            // Input grades
            for (int i = 0; i < numGrades; ++i) {
                float grade;
                cout << "Enter grade " << (i + 1) << ": ";
                cin >> grade;
                grades.push_back(grade);
            }

            // Add student to the list
            students.emplace_back(name, id, grades);
            cout << "Student added successfully!\n";

        } else if (option == 2) {
            // Display all students
            if (students.empty()) {
                cout << "No students available.\n";
            } else {
                for (const auto& student : students) {
                    student.displayInfo();
                    cout << "----------------------\n";
                }
            }
        }
    } while (option != 3); // Exit when option 3 is selected

    cout << "Goodbye!\n";
    return 0;
}

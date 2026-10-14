/*
 * Student Grade Management System
 * Data Structures Project - Arrays Application
 *
 * Uses PARALLEL ARRAYS to manage student records.
 * studentNames[i] and studentGrades[i] belong to the same student.
 *
 * Includes a simple AI-style grade classification and
 * performance prediction feature.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 100;

// ---------- Parallel arrays ----------
string studentNames[MAX_STUDENTS];
int studentGrades[MAX_STUDENTS];
int studentCount = 0;

// ---------- Helper: clear input buffer ----------
void clearInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- AI FEATURE 1: Grade Classification ----------
string aiGrade(int score) {
    if (score >= 80) return "A - Excellent";
    if (score >= 70) return "B - Very Good";
    if (score >= 60) return "C - Good";
    if (score >= 50) return "D - Pass";
    return "F - Fail";
}

// ---------- AI FEATURE 2: Performance Prediction ----------
string aiPredict(int score) {
    if (score >= 75) return "Likely to excel in final exams";
    if (score >= 55) return "Average performance, needs improvement";
    return "At risk - recommend remedial classes";
}

// ---------- Add a student ----------
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Database full!\n";
        return;
    }

    string name;
    int grade;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter grade (0-100): ";
    while (!(cin >> grade) || grade < 0 || grade > 100) {
        cout << "Invalid. Enter grade (0-100): ";
        cin.clear();
        clearInput();
    }
    clearInput();

    studentNames[studentCount] = name;
    studentGrades[studentCount] = grade;
    studentCount++;

    cout << "Student added successfully!\n";
}

// ---------- Display all students with AI insights ----------
void displayAll() {
    if (studentCount == 0) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n" << setw(5) << "No."
         << setw(15) << "Name"
         << setw(8) << "Grade"
         << setw(18) << "AI Grade"
         << "  AI Prediction\n";
    cout << string(90, '-') << "\n";

    for (int i = 0; i < studentCount; i++) {
        cout << setw(5) << (i + 1)
             << setw(15) << studentNames[i]
             << setw(8) << studentGrades[i]
             << setw(18) << aiGrade(studentGrades[i])
             << "  " << aiPredict(studentGrades[i]) << "\n";
    }
}

// ---------- Search ----------
void searchStudent() {
    if (studentCount == 0) {
        cout << "No records to search.\n";
        return;
    }

    string target;
    cout << "Enter student name to search: ";
    getline(cin, target);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentNames[i] == target) {
            cout << "Found: " << studentNames[i]
                 << " | Grade: " << studentGrades[i]
                 << " | AI Grade: " << aiGrade(studentGrades[i]) << "\n";
            found = true;
            break;
        }
    }

    if (!found) cout << "Student not found.\n";
}

// ---------- Class statistics ----------
void showStats() {
    if (studentCount == 0) {
        cout << "No data available.\n";
        return;
    }

    int sum = 0;
    int highest = studentGrades[0];
    int lowest = studentGrades[0];
    string topStudent = studentNames[0];

    for (int i = 0; i < studentCount; i++) {
        sum += studentGrades[i];
        if (studentGrades[i] > highest) {
            highest = studentGrades[i];
            topStudent = studentNames[i];
        }
        if (studentGrades[i] < lowest) {
            lowest = studentGrades[i];
        }
    }

    double average = (double)sum / studentCount;

    cout << fixed << setprecision(2);
    cout << "\n--- Class Statistics ---\n";
    cout << "Total students : " << studentCount << "\n";
    cout << "Average grade  : " << average << "\n";
    cout << "Highest grade  : " << highest << " (" << topStudent << ")\n";
    cout << "Lowest grade   : " << lowest << "\n";
}

// ---------- Main menu ----------
int main() {
    int choice;

    do {
        cout << "\n===== Student Grade Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students (with AI insights)\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Class Statistics\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "Invalid. Enter 1-5: ";
            cin.clear();
            clearInput();
        }
        clearInput();

        switch (choice) {
            case 1: addStudent();       break;
            case 2: displayAll();       break;
            case 3: searchStudent();    break;
            case 4: showStats();        break;
            case 5: cout << "Goodbye!\n"; break;
        }
    } while (choice != 5);

    return 0;
}

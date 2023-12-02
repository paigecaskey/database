#include <iostream>
#include <fstream>  
#include <string>
#include <limits>
#include <cstdlib>
#include "database.h"
using namespace std;

int main() {
    database database; 
    int choice;
    while (true) {
        cout << "Database Menu:\n";
        cout << "1. Print all students\n";
        cout << "2. Print all faculty\n";
        cout << "3. Find and display student information\n";
        cout << "4. Find and display faculty information\n";
        cout << "5. Add a new student\n";
        cout << "6. Delete a student\n";
        cout << "7. Add a new faculty member\n";
        cout << "8. Delete a faculty member\n";
        cout << "9. Change a student’s advisor\n";
        cout << "10. Remove an advisee from a faculty member\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)|| cin.peek() != '\n') {
            cout << "Invalid input. Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }
        if (choice < 1 || choice > 11) {
            cout << "Invalid choice. Please enter a number between 1 and 11.\n";
            continue;
        }
        switch (choice) {
            case 1:
                database.printAllStudents();
                break;
            case 2:
                database.printAllFaculty();
                break;
            case 3:
                database.findAndDisplayStudent();
                break;
            case 4:
                database.findAndDisplayFaculty();
                break;
            case 5:
                database.addNewStudent();
                break;
            case 6:
                database.deleteStudent();
                break;
            case 7:
                database.addNewFaculty();
                break;
            case 8:
                database.deleteFaculty();
                break;
            case 9:
                database.changeStudentAdvisor();
                break;
            case 10:
                database.removeAdviseeFromFaculty();
                break;
            case 11:
                database.exitAndCreateRunLog();
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 11.\n";
        }
    }
    return 0;
}


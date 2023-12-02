#include "Student.h"
#include <iostream>
using namespace std;
// default constructor for student 
Student::Student(){
    ID = 0;
    name = "";
    level = "";
    major = "";
    GPA = 0.0;
    advisor = 0;
}
// overloaded constructor for student 
// @param integer ID representing the student's unique ID
// @param string name representing the student's name
// @param string level representing the student's level
// @param string major representing the student's major
// @param double GPA represeniting a student's GPA
// @param integer advisor representing the ID of the student's advisor
Student::Student(int ID, string name, string level, string major, double GPA, int advisor){
    this->ID = ID;
    this->name = name;
    this->level = level;
    this->major = major;
    this->GPA = GPA;
    this->advisor = advisor;
}
// destructor for student
Student::~Student() {

}
// Equality operator for comparing two students based on their IDs.
bool Student::operator==(const Student& other) const {
    return ID == other.ID;
}
// Inequality operator for comparing two students based on their IDs
bool Student::operator!=(const Student& other) const {
    return ID != other.ID;
}
// Less than operator for comparing two students based on their IDs.
bool Student::operator<(const Student& other) const {
    return ID < other.ID;
}
// Less than or equal to operator for comparing two students based on their IDs.
bool Student::operator<=(const Student& other) const {
    return ID <= other.ID;
}
// Greater than operator for comparing two students based on their IDs.
bool Student::operator>(const Student& other) const {
    return ID > other.ID;
}
// Greater than or equal to operator for comparing two students based on their IDs.
bool Student::operator>=(const Student& other) const {
    return ID >= other.ID;
}
// Print function to display the information of a student.
void Student::print() const {
    cout << "ID: " << ID << ", Name: " << name << ", Level: " << level << ", Major: " << major << ", GPA: " << GPA << ", Advisor: " << advisor << endl;
}
// changes the student's advisor to the one specified
// @return none
// @param integer newAdvisor the new advisor for the student
void Student::changeAdvisor(int newAdvisor){
    if(newAdvisor != advisor){
        this->advisor = newAdvisor;
        cout << "Student with ID " << ID << " now has advisor " << newAdvisor << endl;
    }else{
        cout << "Student is already assigned this advisor." << endl;
    }
}
// returns the student ID
// @return integer representing the student ID
// @param none
int Student::getID(){
    return ID;
}
// returns the ID representing the student's midterm
// @return integer representing the student's advisor
// @param none
int Student::getAdvisor(){
    return advisor;
}

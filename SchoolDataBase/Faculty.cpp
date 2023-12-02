#include "Faculty.h"
#include "Student.h"
#include <iostream>
using namespace std;
// default constructor for faculty members 
Faculty::Faculty(){
    ID = 0;
    name = "";
    level = "";
    department = "";
    advisees = nullptr;
}
// overloaded constructor for faculty members
// @param ID integer representing the faculty unique ID
// @param name string representing faculty name
// @param level string representing faculty level
// @param department string representing faculty department
Faculty::Faculty(int ID, string name, string level, string department){
    this->ID = ID;
    this->name = name;
    this->level = level;
    this->department = department;
    advisees = new DblList<int>();
}
// destructor for faculty 
Faculty::~Faculty() {
    delete advisees;
}
// copy constructor for faculty class, copies attributes of another faculty object 
// @param faculty object to be copied
Faculty::Faculty(const Faculty& other) {
    ID = other.ID;
    name = other.name;
    level = other.level;
    department = other.department;
    advisees = (other.advisees != nullptr) ? new DblList<int>(*other.advisees) : nullptr;
}
// copy assignment operator for faculty class, assigns attributes of another faculty to current
// @param faculty object to be assigned
// @return reference to faculty after it has been assigned
Faculty& Faculty::operator=(const Faculty& other) {
    if (this != &other) {
        ID = other.ID;
        name = other.name;
        level = other.level;
        department = other.department;
        delete advisees;
        advisees = (other.advisees != nullptr) ? new DblList<int>(*other.advisees) : nullptr;
    }
    return *this;
}
// Equality operator for comparing two faculty based on IDs
bool Faculty::operator==(const Faculty& other) const {
    return ID == other.ID;
}
// Inequality operator for comparing two faculty based on IDs
bool Faculty::operator!=(const Faculty& other) const {
    return ID != other.ID;
}
// Less than ooperator for comparing two faculty based on IDs
bool Faculty::operator<(const Faculty& other) const {
    return ID < other.ID;
}
// Less than or equal to operator for comparing two faculty based on IDs
bool Faculty::operator<=(const Faculty& other) const {
    return ID <= other.ID;
}
// Greater than operator for comparing two faculty based on IDs
bool Faculty::operator>(const Faculty& other) const {
    return ID > other.ID;
}
// Greater than or equal to operator for comparing two faculty based on IDs
bool Faculty::operator>=(const Faculty& other) const {
    return ID >= other.ID;
}
// print function to print out faculty member 
void Faculty::print() const{
    cout << "ID: " << ID << ", Name: " << name << ", Level: " << level << ", Department: " << department << endl;
    printAdvisees();
}
// prints all advisees stored in the advisee list
// @return none
// @param none
void Faculty::printAdvisees() const{
    cout << "Advisees: ";
    if(advisees->isEmpty()){
         cout << "No advisees." << endl;
    }else{
       for(int i = 0; i < advisees->getSize(); i++){
        int adviseeID = advisees->get(i);
        cout << "Advisee " << i << " ID:" << adviseeID << endl;
        }
    }
}
// returns the ID of the faculty
// @return integer representing ID of the faculty
// @param none
int Faculty::getID(){
    return ID;
}
// removes an advisee from the advisee list
// @return none
// @param integer representing ID to remove from the list
void Faculty::removeAdviseeFromList(int ID){
    bool found = false;
    for(int i = 0; i < advisees->getSize(); i++){
        int IDtoCompare = advisees->get(i);
        if(IDtoCompare == ID){
            advisees->remove(i);
            found = true;
        }
    }
    if(!found){
        cout << "Advisee to remove does not exist. Removal cancelled." << endl;
    }
}
// adds an advisee to the advisee list
// @return none
// @param integer representing ID to add to the list
void Faculty::addAdvisee(int ID){
    advisees->addFront(ID);
    cout << "Advisee with ID " << ID << " added." << endl;
}
// returns whether or not the advisee list is empty
// @return boolean representing whether or not the advisee list is empty
// @param none
bool Faculty::adviseesIsEmpty(){
    return(advisees->isEmpty());
}
// returns the advisee from the advisee list at the specified index
// @return integer representing the advisee ID
// @param integer representing the index of the advisee to return
int Faculty::getAdvisee(int i){
    return advisees->get(i);
}

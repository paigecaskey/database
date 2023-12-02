#include "database.h"
#include <limits>
using namespace std;
// constructor for database
database::database(){
    studentTree = new LazyBST<Student>();
    facultyTree = new LazyBST<Faculty>();
}
// destructor for database 
database::~database(){ 
    delete studentTree;
    delete facultyTree;
}
// prints all students in the database in ascending order
// @return none
// @param none
void database::printAllStudents(){
    studentTree->printTreeInOrder();
}
// prints all faculty in the database in ascending order
// @return none
// @param none
void database::printAllFaculty(){
    facultyTree->printTreeInOrder();
}

// finds a student and displays their information based on ID
// @return none
// @param none
void database::findAndDisplayStudent(){
    int ID;
    cout << "Enter Student ID: " << endl;
    if(!(cin >> ID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    Student studentToDisplay;
    if(findStudent(ID, studentToDisplay)){
        studentToDisplay.print();
    }else{
        cout << "Student " << ID << " not found." << endl;
    }
}
// finds a student and displays their information based on ID
// @return none
// @param none
void database::findAndDisplayFaculty(){
    int ID;
    cout << "Enter Faculty ID: " << endl;
    if(!(cin >> ID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    Faculty facultyToDisplay;
    if(findFaculty(ID, facultyToDisplay)){
        facultyToDisplay.print();
    }else{
        cout << "Faculty " << ID << " not found." << endl;
    }
}
// adds a new student to the database
// @return none
// @param none
void database::addNewStudent(){
    int ID;
    string name;
    string level;
    string major;
    double GPA;
    int advisorID;
    Student studentToCheck;
    cout << "Enter Student ID: " << endl;
    if(!(cin >> ID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }else if(findStudent(ID, studentToCheck)){
        cout << "Student already exists in the table. Please enter a unique ID." << endl;
        return;
    }
    cin.ignore();
    cout << "Enter Student Name: " << endl;
    getline(cin, name);

    cout << "Enter Student Level: " << endl;
    getline(cin, level);

    cout << "Enter Student Major: " << endl;
    getline(cin, major);

    cout << "Enter Student GPA: " << endl;
    if(!(cin >> GPA) || cin.peek() != '\n'){
        cout << "Invalid GPA. Please enter a valid double sequence." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }else if(GPA < 0.0 || GPA > 4.0){
        cout << "Invalid GPA. Please enter a valid GPA between 0.0 and 4.0." << endl;
        return;
    }
    cout << "Enter ID of the Student's Advisor: " << endl;
    if(!(cin >> advisorID) || cin.peek() != '\n'){
        cout << "Invalid Advisor ID. Please enter a valid integer sequence." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();
    Faculty advisor;
    if(findFaculty(advisorID, advisor)){
        Student newStudent(ID, name, level, major, GPA, advisor.getID());
        studentTree->insert(newStudent);
        advisor.addAdvisee(newStudent.getID());
        facultyTree->remove(advisor);
        facultyTree->insert(advisor);
        cout << "Student added." << endl;
    }else{
        cout << "Advisor with ID " << advisorID << " not found. Add advisor or try different ID." << endl;
        return;
    }
}
// deletes a student from the database based on ID
// @return none
// @param none
void database::deleteStudent(){
    int ID;
    cout << "Enter ID of student to delete: " << endl;
    if(!(cin >> ID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    Student studentToRemove;
    if(findStudent(ID, studentToRemove)){
        studentTree->remove(studentToRemove);
        cout << "Student " << ID << " removed." << endl;
    }else{
        cout << "Student with ID " << ID << " not found. Removal cancelled." << endl;
    }
}
// adds a new faculty to the database
// @return none
// @param none
void database::addNewFaculty() {
    int ID;
    string name;
    string level;
    string dept;
    Faculty facultyToCheck;
    cout << "Enter Faculty ID: " << endl;
    if (!(cin >> ID) || cin.peek() != '\n') {
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }else if(findFaculty(ID, facultyToCheck)){
        cout << "Faculty already exists in the table. Please enter a unique ID." << endl;
        return;
    }
    cin.ignore();  

    cout << "Enter Faculty Name: " << endl;
    getline(cin, name);

    cout << "Enter Faculty Level: " << endl;
    getline(cin, level);

    cout << "Enter Faculty Department: " << endl;
    getline(cin, dept);
    Faculty newFaculty(ID, name, level, dept);
    facultyTree->insert(newFaculty);
    cout << "Faculty added." << endl;
}
// deletes a faculty from the database
// @return none
// @param none
void database::deleteFaculty(){
    int ID;
    cout << "Enter ID of faculty to delete: " << endl;
    if(!(cin >> ID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    Faculty facultyToRemove;
    if(findFaculty(ID, facultyToRemove)){
        if(!facultyToRemove.adviseesIsEmpty()){
            cout << "Advisees must be reassigned to new advisor" << endl;
            while(!facultyToRemove.adviseesIsEmpty()){
                int count = 0;
                int IDtoReassign = facultyToRemove.getAdvisee(count);
                Student studentToReassign;
                findStudent(IDtoReassign, studentToReassign);
                cout << "Student " << IDtoReassign << " must be reassigned an advisor. Advisors listed below." << endl;
                facultyTree -> printTreeInOrder();
                cout << "Enter faculty ID of new advisor." << endl;
                int IDnewAdvisor;
                if (!(cin >> IDnewAdvisor) || cin.peek() != '\n') {
                    cout << "Invalid ID. Please enter a valid integer sequence.";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }else if(ID == IDnewAdvisor){
                    cout << "Your new advisor cannot be the same as the old advisor. Please try again" << endl;
                    return;
                }else{
                    Faculty newAdvisor;
                    facultyToRemove.removeAdviseeFromList(IDtoReassign);
                    findFaculty(IDnewAdvisor, newAdvisor);
                    newAdvisor.addAdvisee(IDtoReassign);
                    studentToReassign.changeAdvisor(IDnewAdvisor);
                    studentTree->remove(studentToReassign);
                    studentTree->insert(studentToReassign);
                    facultyTree->remove(facultyToRemove);
                    cout << "Faculty " << ID << " removed." << endl;
                    count++;
                }
            }
        }else{
            facultyTree->remove(facultyToRemove);
            cout << "Faculty " << ID << " removed." << endl;
        }
    }else{
        cout << "Faculty with ID " << ID << " not found. Removal canceled." << endl;
    }
}
// changes the advisor of a student
// @return none
// @param none
void database::changeStudentAdvisor(){
    int newAdvisorID;
    int studentID;
    cout << "Enter Student ID: " << endl;
    if(!(cin >> studentID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "Enter New Faculty ID: " << endl;
    if(!(cin >> newAdvisorID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    Student studentToChange;
    if(findStudent(studentID, studentToChange)){
        Faculty newAdvisor;
        if(findFaculty(newAdvisorID, newAdvisor)){
            int oldAdvisorID = studentToChange.getAdvisor();
            Faculty oldAdvisor;
            findFaculty(oldAdvisorID, oldAdvisor);
            oldAdvisor.removeAdviseeFromList(studentToChange.getID());
            studentToChange.changeAdvisor(newAdvisor.getID());
            newAdvisor.addAdvisee(studentToChange.getID());
            studentTree->remove(studentToChange);
            studentTree->insert(studentToChange);
        } else {
            cout << "New advisor with ID " << newAdvisorID << " not found. Change canceled." << endl;
        }
    } else {
        cout << "Student with ID " << studentID << " not found. Change canceled." << endl;
    }
}
// removes a student advisee from the faculty's list of advisees
// @return none
// @param none
void database::removeAdviseeFromFaculty(){
    int facultyID;
    int studentID;
    Faculty facultyToChange;
    Student studentToRemove;
    cout << "Enter Faculty ID: " << endl;
    if(!(cin >> facultyID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        return;
    }
    cout << "Enter Student ID: " << endl;
    if(!(cin >> studentID) || cin.peek() != '\n'){
        cout << "Invalid ID. Please enter a valid integer sequence.";
        return;
    }

    if(findFaculty(facultyID, facultyToChange)){
        if(findStudent(studentID, studentToRemove)){
            facultyToChange.removeAdviseeFromList(studentToRemove.getID());
        }
        else{
            cout << "Student does not exist or is not an advisee of the given faculty. Please enter valid IDs.";
            return;
        }
    }
    else{
        cout << "Faculty does not exist. Please enter a valid faculty ID.";
        return;
    }
}
// exits the program menu and creates a run log of the data stored in the database
// @return none
// @param none
void database::exitAndCreateRunLog(){
    ofstream runLogFile("runLog.txt");
    if(runLogFile.is_open()){
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(runLogFile.rdbuf());
        cout << "STUDENTS:" << endl;
        printAllStudents();
        cout << "FACULTY:" << endl;
        printAllFaculty();
        cout.rdbuf(coutbuf);
        runLogFile.close();
        cout << "Data saved to runLog.txt" << endl;
    }else{
        cout << "Error unable to open file." << endl;
    }
}
// Searches for a student in the database based on their ID.
// If the student is found, the function returns true and sets the 'foundStudent' parameter to the information of the located student.
// If the student is not found, the function returns false.
// @param ID The ID of the student to search for.
// @param foundStudent A reference to a Student object where the information of the located student will be stored if found.
// @return true if the student is found, false otherwise.
bool database::findStudent(int ID, Student& foundStudent){
    TreeNode<Student>* studentNode = studentTree->search(Student(ID, "","","", 0.0, 0));
    if (studentNode != nullptr){
        foundStudent = studentNode->getData();
        return true;
    }else{
        return false;
    }
}
// Searches for a faculty in the database based on their ID.
// If the faculty is found, the function returns true and sets the 'foundFaculty' parameter to the information of the located faculty.
// If the faculty is not found, the function returns false.
// @param ID The ID of the faculty to search for.
// @param foundFaculty A reference to a faculty object where the information of the located faculty will be stored if found.
// @return true if the faculty is found, false otherwise.
bool database::findFaculty(int ID, Faculty& foundFaculty){
    TreeNode<Faculty>* facultyNode = facultyTree->search(Faculty(ID, "","",""));
    if(facultyNode != nullptr){
        foundFaculty = facultyNode->getData();
        return true;
    }else{
        return false;
    }
}




#ifndef DATABASE_H
#define DATABASE_H
#include "Student.h"
#include "Faculty.h"
#include "LazyBST.h"
#include <fstream>

class database{
    public:
        database();
        ~database();
        void printAllStudents();
        void printAllFaculty();
        void findAndDisplayStudent();
        void findAndDisplayFaculty();
        void addNewStudent();
        void deleteStudent();
        void addNewFaculty();
        void deleteFaculty();
        void changeStudentAdvisor();
        void removeAdviseeFromFaculty();
        void exitAndCreateRunLog();

    private:
        LazyBST<Student>* studentTree;
        LazyBST<Faculty>* facultyTree;

        bool findStudent(int ID, Student& foundStudent);
        bool findFaculty(int ID, Faculty& foundFaculty);
};
#endif
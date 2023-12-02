#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student {
    public:
        Student();
        Student(int ID, string name, string level, string major, double GPA, int advisor);
        virtual ~Student();
        bool operator==(const Student& other) const;
        bool operator!=(const Student& other) const;
        bool operator<(const Student& other) const;
        bool operator<=(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator>=(const Student& other) const;
        void print() const;
        void changeAdvisor(int newAdvisor);
        int getID();
        int getAdvisor();

    private:
        int ID;
        string name;
        string level;
        string major;
        double GPA;
        int advisor;
};

#endif
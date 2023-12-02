#ifndef FACULTY_H
#define FACULTY_H
#include "DblList.h"
#include <string>
using namespace std;

class Faculty {
    public:
        Faculty();
        Faculty(int ID, string name, string level, string department);
        virtual ~Faculty();
        Faculty(const Faculty& other);
        Faculty& operator=(const Faculty& other);
        bool operator==(const Faculty& other) const;
        bool operator!=(const Faculty& other) const;
        bool operator<(const Faculty& other) const;
        bool operator<=(const Faculty& other) const;
        bool operator>(const Faculty& other) const;
        bool operator>=(const Faculty& other) const;
        void releaseAdvisees();
        void print() const;
        void printAdvisees() const;
        int getID();
        void removeAdviseeFromList(int ID);
        void addAdvisee(int ID);
        bool adviseesIsEmpty();
        int getAdvisee(int i);

    private:
        int ID;
        string name;
        string level;
        string department;
        DblList<int>* advisees;
};

#endif
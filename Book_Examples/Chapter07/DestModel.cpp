#include <iostream>
#include <cstring>
using namespace std;

class Person {
    private:
        char* name;
    public:
        Person(const char* myName) {
            name = new char[strlen(myName) + 1];
            strcpy(name, myName);
        }
        ~Person() {
            delete []name;
        }
        void WhatYourName() const {
            cout << "My name is " << name << endl;
        }
};

class UnivStudent : public Person {
    private:
        char* major;
    public:
        UnivStudent(const char* myName, const char* myMajor) : Person(myName) {
            major = new char[strlen(myMajor) + 1];
            strcpy(major, myMajor);
        }
        ~UnivStudent() {
            delete []major;
        }
        void WhoAreYou() const {
            WhatYourName();
            cout << "My major is " << major << endl << endl;
        }
};

int main(void) {
    UnivStudent st1("Kim", "Mathematics");
    st1.WhoAreYou();
    UnivStudent st2("Hong", "Physics");
    st2.WhoAreYou();
    return 0;
}
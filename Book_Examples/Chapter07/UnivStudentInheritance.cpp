#include <iostream>
#include <cstring>
using namespace std;

class Person {
    private:
        int age;
        char name[50];
    public:
        Person(int myAge, const char* myName) : age(myAge) {
            strcpy(name, myName);
        }
        void WhatYourName() const {
            cout << "My name is " << name << endl;
        }
        void HowOldAreYou() const {
            cout << "I'm " << age << " years old" << endl;
        }
};

class UnivStudent : public Person {
    private:
        char major[50];
    public:
        UnivStudent(const char* myName, int myage, const char* myMajor)
            : Person(myage, myName) {
                strcpy(major, myMajor);
            }
        
        void WhoAreYou() const {
            WhatYourName();
            HowOldAreYou();
            cout << "My major is " << major << endl << endl;
        }
};

int main(void) {
    UnivStudent ustd1("Lee", 22, "CS");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Yoon", 21, "EE");
    ustd2.WhoAreYou();
    return 0;
}
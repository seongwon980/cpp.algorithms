#include <iostream>
using namespace std;

class Person {
    public:
        int studentID;
    
    public:
        Person(int studentID) {
            this -> studentID = studentID;
        }

        void Show() {
            cout << "ID: " << studentID << endl;
        }
};

int main(void) {
    Person p1(2017147573);
    Person p2 = p1;

    p1.studentID = 2018;
    p1.Show();
    p2.Show();

}
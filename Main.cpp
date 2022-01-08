#include <iostream>
#include <cstring>
using namespace std;

class Person {
    private:
        char* name;
        int age;
    
    public:
        Person(const char* myname, int myage) {
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }

        void ShowPersonInfo() const {
            cout << "이름: " << name << endl;
            cout << "나이: " << age<< endl;
        }

        ~Person() {
            delete []name;
            cout << "called destructor!" << endl;
        }
};

int main(void) {
    Person man1("Cho Seongwon", 24);
    Person man2("Cho Seongjun", 22);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    private:
        char* name;
        int age;
    
    public:
        Person(const char* _name, int _age) {
            age = _age;
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }
        
        Person& operator=(const Person &ref) {
            delete []name;
            name = new char[strlen(ref.name) + 1];
            strcpy(name, ref.name);
            age = ref.age;
            return *this;
        }

        void ShowPersonInfo() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
        
        ~Person() {
            delete []name;
            cout << "Called destructor!" << endl;
        }
};

int main(void) {
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class First {
    private:
        char* strOne;
    public:
        First(const char* _strOne) {
            strOne = new char[strlen(_strOne) + 1];
        }

        virtual ~First() {
            cout << "~First()" << endl;
            delete []strOne;
        }
};

class Second : public First {
    private:
        char* strTwo;
    public:
        Second(const char* _strOne, const char* _strTwo) : First(_strOne) {
            strTwo = new char[strlen(_strTwo) + 1];
        }
        virtual ~Second() {
            cout << "~Second()" << endl;
            delete []strTwo;
        }
};

int main(void) {
    First* ptr = new Second("simple", "complex");
    delete ptr;
    return 0;
}
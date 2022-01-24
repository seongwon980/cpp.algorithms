#include <iostream>
using namespace std;

class SoSimple {
    public:
        virtual void ShowSimpleInfo() {
            cout << "SoSimple Base Class" << endl;
        }
};

class SoComplex : public SoSimple {
    public:
        void ShowSimpleInfo() {
            cout << "SoComplex Derived Class" << endl;
        }
};

int main(void) {
    SoSimple* simplePtr = new SoComplex;
    SoComplex* complexPtr = dynamic_cast<SoComplex*>(simplePtr);
    complexPtr->ShowSimpleInfo();

    return 0;
}
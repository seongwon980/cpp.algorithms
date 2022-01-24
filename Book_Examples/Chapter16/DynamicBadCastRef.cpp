#include <iostream>
#include <typeinfo>
using namespace std;

class SoSimple {
    public:
        virtual void ShowSimpleInfo() {
            cout << "SoSimple Base Class\n";
        }
};

class SoComplex : public SoSimple {
    public:
        void ShowSimpleInfo() {
            cout << "SoComplex Derived Class\n";
        }
};

int main(void) {
    SoSimple simObj;
    SoSimple& ref = simObj;

    try {
        SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
        comRef.ShowSimpleInfo();
    } catch (bad_cast expn) {
        cout << expn.what() << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

class SoSimple {
    private:
        static int simpleObjCnt;
    public:
        SoSimple() {
            simpleObjCnt++;
            cout << simpleObjCnt << "th SoSimple instance created!" << endl;
        }
};

int SoSimple::simpleObjCnt = 0;

class SoComplex {
    private:
        static int cmxObjCount;
    public:
        SoComplex() {
            cmxObjCount++;
            cout << cmxObjCount << "th SoComplex instance created!" << endl;
        }
        SoComplex(SoComplex &copy) {
            cmxObjCount++;
            cout << cmxObjCount << "th SoComplex instance created!" << endl;
        }
};

int SoComplex::cmxObjCount = 0;

int main(void) {
    SoSimple sim1;
    SoSimple sim2;
    
    SoComplex cmx1;
    SoComplex cmx2 = cmx1;
    SoComplex();
    return 0;
}


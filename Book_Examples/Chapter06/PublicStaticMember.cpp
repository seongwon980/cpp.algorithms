#include <iostream>
using namespace std;

class SoSimple {
    public:
        static int simpleObjectCount;
    public:
        SoSimple() {
            simpleObjectCount++;
        }
};

int SoSimple::simpleObjectCount = 0;

int main(void) {
    cout << SoSimple::simpleObjectCount << "th SoSimple instance!" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simpleObjectCount << "th SoSimple instance!" << endl;
    cout<< sim1.simpleObjectCount << "th SoSimple instance!" << endl;
    cout << sim2.simpleObjectCount << "th SoSimple instance!" << endl;
    return 0;
}
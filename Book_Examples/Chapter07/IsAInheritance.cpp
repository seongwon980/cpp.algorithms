#include <iostream>
#include <cstring>
using namespace std;

class Computer {
    private:
        char owner[50];
    public:
        Computer(const char* _owner) {
            strcpy(owner, _owner);
        }

        void Calculate() {
            cout << "Calculating..." << endl;
        }
};

class LaptopComputer : public Computer {
    private:
        int battery;
    public:
        LaptopComputer(const char* _owner, int _battery)
            : Computer(_owner), battery(_battery) {}
        void Charging() {battery += 5;}
        void UseBattery() {battery -= 1;}
        int GetBatteryInfo() const {return battery;}
        void MovingCall() {
            if (GetBatteryInfo() < 1) {
                cout << "Need to be charged" << endl;
                return;
            }
            cout << "While moving : ";
            Calculate();
            UseBattery();
        }
};

class Tablet : public LaptopComputer {
    private:
        char registeredPenModel[50];
    public:
        Tablet(const char* _owner, int _battery, const char* _registeredPenModel)
            : LaptopComputer(_owner, _battery) {
                strcpy(registeredPenModel, _registeredPenModel);
            }
        void Write(const char* penInfo) {
            if (GetBatteryInfo() < 1) {
                cout << "Need to be charged" << endl;
                return;
            }

            if (strcmp(registeredPenModel, penInfo) != 0) {
                cout << "Not a registered pen model..." << endl;
                return;
            }

            cout << "Processing written elements..." << endl;
            UseBattery();
        }
};

int main(void) {
    LaptopComputer nc("Lee", 5);
    Tablet tn("Jung", 5, "ISE-241-242");
    nc.MovingCall();
    tn.Write("ISE-241-242");
    return 0;
}
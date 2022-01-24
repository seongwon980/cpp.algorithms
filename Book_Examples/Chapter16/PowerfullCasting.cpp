#include <iostream>
using namespace std;

class Car {
    private:
        int fuelGauge;
    public:
        Car(int _fuelGauge) : fuelGauge(_fuelGauge) {}
        void ShowCarState() {
            cout << "Remaining fuel: " << fuelGauge << endl;
        }
};

class Truck : public Car {
    private:
        int freightWeight;
    public:
        Truck(int _fuel, int _freightWeight)
            : Car(_fuel), freightWeight(_freightWeight) {}

        void ShowTruckState() {
            Car::ShowCarState();
            cout << "Weight loaded : " << freightWeight << endl;
        }
};

int main(void) {
    Car* pcar1 = new Truck(80, 200);
    Truck* ptruck1 = (Truck*)pcar1;
    ptruck1->ShowTruckState();
    cout << endl;

    Car* pcar2 = new Car(120);
    Truck* ptruck2 = (Truck*)pcar2;
    ptruck2->ShowTruckState();
    return 0;
}
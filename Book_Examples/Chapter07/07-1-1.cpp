#include <iostream>
#include <cstring>
using namespace std;

class Car {
    private:
        int gasolineGauge;
    public:
        Car() : gasolineGauge(0) {}
        Car(int gg) : gasolineGauge(gg) {}

        int GetGasGauge() {
            return gasolineGauge;
        }
};

class HybridCar : public Car {
    private:
        int electricGauge;
    public:
        HybridCar() : Car(), electricGauge(0) {}
        HybridCar(int eg) : Car(), electricGauge(eg) {}
        HybridCar(int gg, int eg) : Car(gg), electricGauge(eg) {}

        int GetElecGauge() {
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar {
    private:
        int waterGauge;
    public:
        HybridWaterCar() : HybridCar(), waterGauge(0) {}
        HybridWaterCar(int wg) : HybridCar(), waterGauge(wg) {}
        HybridWaterCar(int gg, int eg, int wg) : HybridCar(gg, eg), waterGauge(wg) {}

        int GetWaterGauge() {
            return waterGauge;
        }

        void ShowCurrentGauge() {
            cout << "Remaining gasoline: " << GetGasGauge() << endl;
            cout << "Remaining electricity: " << GetElecGauge() << endl;
            cout << "Remaining water: " << GetWaterGauge() << endl;
        }  
};

int main(void) {
    HybridWaterCar hwc(10, 20, 30);
    hwc.ShowCurrentGauge();
}
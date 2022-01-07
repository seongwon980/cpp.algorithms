#include <iostream>
#include <cstring>
using namespace std;

class Calculator {
    private:
        int addCount;
        int subCount;
        int mulCount;
        int divCount;
    
    public:
        void Init() {
            addCount = subCount = mulCount = divCount = 0;
        }
        double Add(double num1, double num2);
        double Sub(double num1, double num2);
        double Mul(double num1, double num2);
        double Div(double num1, double num2);
        void ShowOpCount(void);
};

double Calculator::Add(double num1, double num2) {
    addCount++;
    return num1 + num2;
}

double Calculator::Sub(double num1, double num2) {
    subCount++;
    return num1 - num2;
}

double Calculator::Mul(double num1, double num2) {
    mulCount++;
    return num1 * num2;
}

double Calculator::Div(double num1, double num2) {
    divCount++;
    return num1 / num2;
}

void Calculator::ShowOpCount(void) {
    cout << "덧셈: " << addCount << " 뺄셈: " << subCount
    << " 곱셈: " << mulCount << " 나눗셈: " << divCount << endl;
}

int main(void) {
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}
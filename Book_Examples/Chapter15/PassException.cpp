#include <iostream>
using namespace std;

void Divide(int num1, int num2) {
    if (num2 == 0)
        throw num2;
    cout << "Quotient: " << num1 / num2 << endl;
    cout << "Remainder: " << num1 % num2 << endl;
}

int main(void) {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try {
        Divide(num1, num2);
        cout << "Finished divide opratrion." << endl;
    } catch (int expn) {
        cout << "Divisor cannot be zero." << endl;
        cout << "Restart the program." << endl;
    }
    return 0;
}
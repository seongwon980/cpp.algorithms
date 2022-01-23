#include <iostream>
using namespace std;

int main(void) {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try {
        if (num2 == 0)
            throw num2;
        cout << "Quotient: " << num1/num2 << endl;
        cout << "Remainder: " << num1%num2 << endl;
    } catch(int expn) {
        cout << "Divisor cannot be " << expn << ".\n";
        cout << "Restart the program...\n";
    }
    cout << "end of main" << endl;
    return 0;
}
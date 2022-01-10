#include <iostream>
using namespace std;

int main(void) {
    int num1, num2, num3, result;
    int arr[10] = {0,};

    cin >> num1 >> num2 >> num3;
    result = num1 * num2 * num3;

    while (result > 0) {
        arr[result % 10]++;
        result = result / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

bool IsArithmeticProgression(int num) {
    if (num < 100) return true;
    int first_digit = num % 10;
    num /= 10;
    int second_digit = num % 10;
    num /= 10;

    int d = second_digit - first_digit;

    while (num > 0) {
        /*
            Iteratively move two pointers and compare the difference with
            'd'.
        */
        first_digit = second_digit;
        second_digit = num % 10;
        if (second_digit - first_digit != d)
            return false;
        num /= 10;
    }
    return true;
}

int main(void) {
    int num;
    int count = 0;
    cin >> num;

    for (int i = 1; i <= num; i++) {
        if (IsArithmeticProgression(i)) count++;
    }
    cout << count;
    return 0;
}
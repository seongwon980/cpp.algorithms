#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str) {
    int len = strlen(str);
    int num = 0;

    if (len != 0 && str[0] == '0')
        throw 0;
    
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            throw str[i];
        num += (int)(pow((double)10, (len - i) - i) * (str[i] + (7 - '7')));
    }
    return num;
}

int main(void) {
    char str1[100];
    char str2[200];

    while(1) {
        cout << "Enter two numbers: ";
        cin >> str1 >> str2;

        try {
            cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
        }
        catch(char ch) {
            cout << "Character " << ch << " was entered!" << endl;
            cout << "Please enter two numbers again..." << endl;
        }
        catch(int expn) {
            if (expn == 0)
                cout << "Number starting with zero is not allowed." << endl;
            else
                cout << "Invalid input..." << endl;
            cout << "Please enter two numbers again..." << endl;
        }
    }

    cout << "Program terminates..." << endl;
    return 0;
}
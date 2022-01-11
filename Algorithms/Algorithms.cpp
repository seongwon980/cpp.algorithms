#include <iostream>
using namespace std;

int main(void) {
    const int MAX_LENGTH = 80;
    int num;
    cin >> num;

    const char* arr[num];
    for (int i = 0; i < num; i++)
        cin >> arr[i];


    return 0;
}
#include <iostream>
using namespace std;

int main(void) {
    char arr[50] = {'a', 'b', 'c', 'd', 'e'};
    cout << sizeof(arr);
    for (int i = 0; i < 50; i++)
        cout << (arr[i] == 'b');
    return 0;
}
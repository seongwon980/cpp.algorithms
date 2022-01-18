#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int (*fp)(int, int);
    fp = add;
    cout << fp(10, 20) << endl;
}

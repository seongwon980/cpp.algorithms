#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
    private:
        int* arr;
        int arrLen;
        BoundCheckIntArray(const BoundCheckIntArray &ref) {}
        BoundCheckIntArray& operator=(const BoundCheckIntArray &ref) {}
        
    public:
        BoundCheckIntArray(int len) : arrLen(len) {
            arr = new int[len];
        }

        int& operator[] (int idx) {
            if (idx < 0 || idx >= arrLen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        ~BoundCheckIntArray() {
            delete []arr;
        }
};

int main(void) {
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;
    return 0;
}
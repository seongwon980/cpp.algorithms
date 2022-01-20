#include <iostream>
using namespace std;

class BoundCheckIntArray {
    private:
        int* arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray &ref) {}
        BoundCheckIntArray& operator=(const BoundCheckIntArray &ref) {}
    
    public:
        BoundCheckIntArray(int len) : arrlen(len) {
            arr = new int[arrlen];
        }

        int& operator[] (int idx) {
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        int operator[] (int idx) const {
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        int GetArrLen() const {
            return arrlen;
        }

        ~BoundCheckIntArray() {
            delete []arr;
        }
};

class BoundCheck2DIntArray {
    private:
        BoundCheckIntArray** arr;       // 1차원 배열을 가리키는 포인터로 구성된 포인터 배열이다.
        int arrlen;
        BoundCheck2DIntArray(const BoundCheck2DIntArray &ref) {}
        BoundCheck2DIntArray& operator= (const BoundCheck2DIntArray &ref) {}
    
    public:
        BoundCheck2DIntArray(int row, int col) : arrlen(row) {
            arr = new BoundCheckIntArray*[row];
            for (int i = 0; i < row; i++)
                arr[i] = new BoundCheckIntArray(col);
        }

        BoundCheckIntArray& operator[] (int idx) {
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return *(arr[idx]);     // 포인터 배열이었기 때문에 dereferencing을 해준다.
        }

        ~BoundCheck2DIntArray() {
            for (int i = 0; i < arrlen; i++) {
                delete arr[i];
            }
            delete []arr;
        }
};

int main(void) {
    BoundCheck2DIntArray arr2d(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            arr2d[i][j] = i + j;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr2d[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {}
        friend ostream& operator<< (ostream &os, const Point &pos);
        friend ostream& operator<< (ostream &os, const Point* ptr);
};

ostream& operator<< (ostream &os, const Point &pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << "]\n";
    return os;
}

ostream& operator<< (ostream &os, const Point* ptr) {
    // 호출할 때에는 cout << ptr;
    // 실행되면 cout.operator<<(ptr) 이렇게 바뀐다.
    // cout은 ostream의 객체, ptr은 Point* 형이므로 아래와 같이 코드 작성

    os << '[' << ptr->xpos << ", " << ptr->ypos << "]\n";
    return os;
}

class BoundCheckPointPtrArray {
    private:
        Point** arr;        // Point 객체들의 주소를 저장하는 배열이므로 포인터 배열이다.
        int arrlen;
        BoundCheckPointPtrArray(const BoundCheckPointPtrArray &ref) {}
        BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray &ref) {}

    public:
        BoundCheckPointPtrArray(int len) : arrlen(len) {
            arr = new Point*[len];
        }

        Point*& operator[] (int idx) {
            // arr[3]을 하면 arr.operator[](3)이 호출된다는 것이다. 이 때는 원본 변경이 가능해야 하므로 레퍼런스 반환.
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        Point* operator[] (int idx) const {
            // 이 때는 함수명에 const가 붙었으므로 멤버 변수를 수정하지 않는다. (여기서는 객체 배열이 됨)
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        int GetArrLen() const {
            return arrlen;
        }

        ~BoundCheckPointPtrArray() {
            delete []arr;
        }
};

int main(void) {
    BoundCheckPointPtrArray arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++)
        cout << arr[i];
    delete arr[0];
    delete arr[1];
    delete arr[2];
    return 0;
}
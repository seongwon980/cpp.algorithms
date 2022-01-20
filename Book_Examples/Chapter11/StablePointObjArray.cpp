#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {}
        friend ostream& operator<< (ostream &os, const Point &pos);
};

ostream& operator<< (ostream &os, const Point &pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << "]\n";
    return os;
}

class BoundCheckPointArray {
    private:
        Point* arr;
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray &ref) {}
        BoundCheckPointArray& operator=(const BoundCheckPointArray &ref) {}
    
    public:
        BoundCheckPointArray(int len) : arrlen(len) {
            arr = new Point[len];
        }

        Point& operator[] (int idx) {
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        Point operator[] (int idx) const {
            if (idx < 0 || idx >= arrlen) {
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        int GetArrLen() const {
            return arrlen;
        }

        ~BoundCheckPointArray() {
            delete []arr;
        }
};

int main(void) {
    BoundCheckPointArray arr(3);
    arr[0] = Point(3, 4);
    arr[1] = Point(5, 6);
    arr[2] = Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++)
        cout << arr[i];

    return 0;
}

#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {
            cout << "Point 按眉 积己!" << endl;
        }
        ~Point() {
            cout << "Point 按眉 家戈!" << endl;
        }

        void SetPos(int x, int y) {
            xpos = x;
            ypos = y;
        }

        friend ostream& operator<< (ostream &os, const Point &pos);
};

ostream& operator<< (ostream &os, const Point &pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << "]\n";
    return os;
}

class SmartPtr {
    private:
        Point* posptr;
    public:
        SmartPtr(Point* ptr) : posptr(ptr) {}
        
        Point& operator*() const {
            return *posptr;
        }

        Point* operator->() const {
            return posptr;
        }

        ~SmartPtr() {
            delete posptr;
        }
};

int main(void) {
    SmartPtr ptr1(new Point(1, 2));
    SmartPtr ptr2(new Point(2, 3));
    SmartPtr ptr3(new Point(4, 5));

    cout << *ptr1;
    cout << *ptr2;
    cout << *ptr3;

    ptr1 -> SetPos(10, 20);
    ptr2 -> SetPos(30, 40);
    ptr3 -> SetPos(50, 60);

    cout << *ptr1;
    cout << *ptr2;
    cout << *ptr3;
    
    return 0;
}
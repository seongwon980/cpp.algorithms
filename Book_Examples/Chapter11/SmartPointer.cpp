#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {
            cout << "Point initialized!" << endl;
        }

        ~Point() {
            cout << "Point detructed!" << endl;
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
        Point* ptr;
    public:
        SmartPtr(Point* _ptr) : ptr(_ptr) {}

        Point& operator*() const {
            return *ptr;        // Point 객체를 참조형으로 반환
        }

        Point* operator->() const {
            return ptr;     // Point 객체를 가리키는 포인터를 반환
        }

        ~SmartPtr() {
            delete ptr;
        }
};

int main(void) {
    SmartPtr ptr1(new Point(1, 2));     // 새로 생성된 Point 객체의 주소를 넘겨줌
    SmartPtr ptr2(new Point(2, 3));
    SmartPtr ptr3(new Point(4, 5));

    cout << *ptr1;
    cout << *ptr2;
    cout << *ptr3;

    ptr1 -> SetPos(10, 20);     // Point의 주소가 반환된 뒤 ->가 하나 더 추가됨.
    ptr2 -> SetPos(30, 40);
    ptr3 -> SetPos(50, 60);

    cout << *ptr1;
    cout << *ptr2;
    cout << *ptr3;
    return 0;
}
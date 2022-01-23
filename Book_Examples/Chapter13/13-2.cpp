#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {}
        void SetPos(int x, int y) {
            xpos = x;
            ypos = y;
        }
        void ShowPosition() const {
            cout << "[" << xpos << ", " << ypos << "]\n";
        }
};

template <class T>
class SmartPtr {
    private:
        T* ptr;
    public:
        SmartPtr(T* _ptr) : ptr(_ptr) {}
        T& operator*() const {
            return *ptr;
        }
        T* operator->() const {
            return ptr;
        }
        ~SmartPtr() {
            delete ptr;
        }
};


int main(void) {
    SmartPtr<Point> sptr1(new Point(1, 2));
    SmartPtr<Point> sptr2(new Point(3, 4));
    sptr1->ShowPosition();
    sptr2->ShowPosition();
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr1->ShowPosition();
    sptr2->ShowPosition();

    return 0;
}

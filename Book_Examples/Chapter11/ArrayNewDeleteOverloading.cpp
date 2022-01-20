#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0) : xpos(_xpos), ypos(_ypos) {}
        friend ostream& operator<< (ostream &os, const Point &pos);

        void* operator new(size_t size) {
            cout << "operator new : " << size << endl;
            void* addr = new char[size];
            return addr;
        }

        void operator delete(void* addr) {
            cout << "operator delete ()" << endl;
            delete []addr;
        }

        void* operator new[](size_t size) {
            cout << "operator new [] : " << size << endl;
            void* addr = new char[size];
            return addr;
        }

        void operator delete[] (void* addr) {
            cout << "operator delete[]" << endl;
            delete []addr;
        }
};

ostream& operator<< (ostream &os, const Point &pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << "]\n";
    return os;
}


int main(void) {
    Point* ptr = new Point(3, 4);
    Point* arr = new Point[3];
    delete ptr;
    delete []arr;
    return 0;
}
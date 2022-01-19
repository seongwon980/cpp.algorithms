#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    
    public:

        Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

        void ShowPosition() const {
                cout << "[" << xpos << ", " << ypos << "]\n";
        }

        friend ostream& operator<<(ostream&, const Point&);
        friend istream& operator>>(istream&, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    // 호출한 객체 자신이 left-argument로 전달된다.
    os<<"[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os;
}

istream& operator>>(istream& is, const Point& pos) {
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main(void) {
    Point pos1;
    cout << "Enter x, y : ";
    cin >> pos1;
    cout << pos1;
    
    return 0;
}

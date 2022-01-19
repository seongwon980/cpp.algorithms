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
        friend istream& operator>>(istream&, Point& pos);
};

ostream& operator<<(ostream& os, const Point& point) {
    os << "[" << point.xpos << ", " << point.ypos << "]" << endl;
    return os;
}

istream& operator>>(istream& is, Point& point) {
    is >> point.xpos >> point.ypos;
    return is;
}

int main(void) {
    Point pos1;
    cout << "Enter x, y : ";
    cin >> pos1;
    cout << pos1;
    
    return 0;
}

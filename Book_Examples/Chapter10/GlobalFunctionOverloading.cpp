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
        friend Point operator+(const Point &pos1, const Point &pos2);
        friend Point operator-(const Point &pos1, const Point &pos2);

        Point& operator+=(const Point &ref) {
            xpos += ref.xpos;
            ypos += ref.ypos;
            return *this;
        }
        
        Point& operator-=(const Point &ref) {
            xpos -= ref.xpos;
            ypos -= ref.ypos;
            return *this;
        }

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);
};

Point operator+(const Point &pos1, const Point &pos2) {
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2) {
    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2) {
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return true;
    else
        return false;
}

bool operator!=(const Point &pos1, const Point &pos2) {
    return !(pos1 == pos2);
}

int main(void) {
    Point pos1(3, 4);
    Point pos2(10, 10);
    Point pos3 = pos1 + pos2;
    Point pos4 = pos1 - pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();
    return 0;
}
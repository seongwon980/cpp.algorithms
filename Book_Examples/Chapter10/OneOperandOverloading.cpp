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

        Point& operator++() {
            xpos += 1;
            ypos += 1;
            return *this;
        }

        const Point operator++(int) {
            const Point retPoint(xpos, ypos);
            xpos += 1;
            ypos += 1;
        }
        
        Point operator-() {
            Point retPoint(xpos * -1, ypos * -1);
            return retPoint;
        }
        friend Point& operator--(Point &ref);
        friend Point operator~(const Point &ref);
};

Point& operator--(Point &ref) {
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point operator~(const Point &ref) {
    Point pos(ref.ypos, ref.xpos);
    return pos;
}


int main(void) {
    Point pos(1, 2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    Point pos2 = -pos;
    pos2.ShowPosition();
    return 0;
}
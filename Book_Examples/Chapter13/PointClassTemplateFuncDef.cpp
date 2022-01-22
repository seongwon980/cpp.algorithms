#include <iostream>
using namespace std;

template <typename T>
class Point {
    private:
        T xpos, ypos;
    public:
        Point(T _xpos = 0, T _ypos = 0);
        void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T _xpos, T _ypos) : xpos(_xpos), ypos(_ypos) {}

template <typename T>
void Point<T>::ShowPosition() const {
    cout << '[' << xpos << ", " << ypos << "]\n";
}

int main(void) {
    Point<int> pos1(3, 4);
    pos1.ShowPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    Point<char> pos3('P', 'F');
    pos3.ShowPosition();
    return 0;
}
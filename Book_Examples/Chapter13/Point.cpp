#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int _xpos, int _ypos) : xpos(_xpos), ypos(_ypos) {}

ostream& operator<< (ostream& os, const Point &ref) {
    os << '[' << ref.xpos << ", " << ref.ypos << "]\n";
    return os;
}
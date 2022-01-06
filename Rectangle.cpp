#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) {
        cout << "Inappropriate position" << endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "Up left: " << "[" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
    cout << "Low right: " << "[" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << endl << endl;
}


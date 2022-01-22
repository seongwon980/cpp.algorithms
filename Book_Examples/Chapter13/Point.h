#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

class Point {
    private:
        int xpos, ypos;
    public:
        Point(int _xpos = 0, int _ypos = 0);
        friend ostream& operator<< (ostream& os, const Point &ref);
};

#endif
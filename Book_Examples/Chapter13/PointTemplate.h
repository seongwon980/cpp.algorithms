#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template <typename T>
class Point {
    private:
        int xpos, ypos;
    public:
        Point(T _xpos = 0, T _ypos = 0);
        void ShowPosition() const;
};
#endif
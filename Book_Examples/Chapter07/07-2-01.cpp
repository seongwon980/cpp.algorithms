#include <iostream>
#include <cstring>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;
    
    public:
        Rectangle(int _width, int _height)
            : width(_width), height(_height) {}

        void ShowAreaInfo() {
            cout << "Area: " << width * height << endl;
        }
};

class Square : public Rectangle {
    public:
        Square(int _width) : Rectangle(_width, _width) {}
};

int main(void) {
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
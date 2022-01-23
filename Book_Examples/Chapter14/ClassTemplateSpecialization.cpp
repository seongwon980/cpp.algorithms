#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point {
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const {
            cout << "[" << xpos << ", " << ypos << "]\n";
        }
};

template <typename T>
class SimpleDataWrapper {
    private:
        T mData;
    public:
        SimpleDataWrapper(T data) : mData(data) {}
        void ShowDataInfo(void) {
            cout << "Data: " << mData << endl;
        }
};

template <>
class SimpleDataWrapper <char*> {
    private:
        char* mData;
    public:
        SimpleDataWrapper(const char* data) {
            mData = new char[strlen(data) + 1];
            strcpy(mData, data);
        }
        void ShowDataInfo(void) {
            cout << "String: " << mData << endl;
            cout << "Length: " << strlen(mData) << endl;
        }
        ~SimpleDataWrapper() {
            delete []mData;
        }
};

template<>
class SimpleDataWrapper <Point<int>> {
    private:
        Point<int> mData;
    public:
        SimpleDataWrapper(int x, int y) : mData(x, y) {}
        void ShowDataInfo(void) {
            mData.ShowPosition();
        }
};

int main(void) {
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo();

    SimpleDataWrapper<char*> swrap("Class Template Specialization");
    swrap.ShowDataInfo();

    SimpleDataWrapper<Point<int>> poswrap(3, 7);
    poswrap.ShowDataInfo();
    
    return 0;
}
#include <iostream>
using namespace std;

class Number {
    private:
        int num;
    public:
        Number(int _num) : num(_num) {}
        void ShowData() {
            cout << num << endl;
        }

        Number* operator->() {
            return this;
        }

        Number& operator*() {
            return *this;
        }
};

int main(void) {
    Number num(20);
    num.ShowData();

    num = 30;
    num -> ShowData();
    return 0;
}
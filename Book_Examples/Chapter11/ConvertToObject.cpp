#include <iostream>
using namespace std;

class Number {
    private:
        int num;
    public:
        Number(int _num = 0) : num(_num) {
            cout << "Number(int _num = 0)" << endl;
        }

        Number& operator=(const Number& ref) {
            cout << "operator=()" << endl;
            num = ref.num;
            return *this;
        }

        void ShowNumber() {
            cout << num << endl;
        }

        operator int () {
            return num;
        }
};

int main(void) {
    Number num1;
    num1 = 30;  // 1. Number(30)으로 임시객체 생성 (형 맞추기), 2. 대입 연산자 operator= 호출
    num1.ShowNumber();

    Number num2 = num1 + 20;
    num2.ShowNumber();
    return 0;
}
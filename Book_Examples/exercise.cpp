#include <iostream>
using namespace std;

class A {
    private:
        int num;
    public:
        A(int n) : num(n) {
            cout << "생성된 객체의 주소: " << this << endl;
        }
        A(const A& a) : num(a.num) {
            cout << "복사되어 생성된 객체의 주소: " << this << endl;
        }
        ~A() {
            cout << "삭제될 객체의 주소: " << this << endl;
        }
};

A ReturnA(A a) {
    cout << "매개변수로 전달된 객체의 주소: " << &a << endl;
    return a;
}

int main(void) {
    A a(3);
    ReturnA(a);
    cout << endl;

    A ref = ReturnA(a);
    cout << "두 번째 함수 호출에 의해서 반환된 객체의 주소: " << &ref << endl;
    return 0;
}
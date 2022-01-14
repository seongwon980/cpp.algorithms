#include <iostream>
using namespace std;

class A {
    private:
        int num;
    public:
        A(int n) : num(n) {
            cout << "������ ��ü�� �ּ�: " << this << endl;
        }
        A(const A& a) : num(a.num) {
            cout << "����Ǿ� ������ ��ü�� �ּ�: " << this << endl;
        }
        ~A() {
            cout << "������ ��ü�� �ּ�: " << this << endl;
        }
};

A ReturnA(A a) {
    cout << "�Ű������� ���޵� ��ü�� �ּ�: " << &a << endl;
    return a;
}

int main(void) {
    A a(3);
    ReturnA(a);
    cout << endl;

    A ref = ReturnA(a);
    cout << "�� ��° �Լ� ȣ�⿡ ���ؼ� ��ȯ�� ��ü�� �ּ�: " << &ref << endl;
    return 0;
}
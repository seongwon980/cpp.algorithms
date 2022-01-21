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
            // 이는 주소를 반환하는 형태로 오버로딩해야 한다.
            return this;
        }

        Number& operator*() {
            // 이는 자기 자신의 레퍼런스를 반환하는 형태로 오버로딩해야 한다.
            return *this;
        }
};

int main(void) {
    Number num(20);
    num.ShowData();

    num = 30;       // 이게 이상해 보이는데 사실은 생성자가 호출돼서 Number(30)이 된다.
    num -> ShowData();      // num은 객체의 이름이고 ->를 쓰면 주소가 반환된다.
    return 0;
}
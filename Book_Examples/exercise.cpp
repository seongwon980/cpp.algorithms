#include <iostream>
using namespace std;

class Point {
    public:
        int x;
        int y;
    public:
        Point(int px, int py)
            : x(px), y(py) {}       // 첫 번째 중요한 부분
        
        void Print() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
};

int main(void) {
    Point p1(3, 4);     // 두 번째 중요한 부분 (자바와 달리 new가 없고 생성자 호출 방식도 다름)
    Point p2(p1);       // 가장 중요한 부분 (생성자에 Point 객체를 전달한다?) 
    p1.x = 999;         // 예시의 단순화를 위해서 어쩔 수 없이 객체지향 설계를 위반
    p1.Print();         // p1은 당연히 x가 999로 바뀐다.
    p2.Print();         // p2도 바뀌는지가 궁금한 것이다.
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class Gun {
    private:
        int bullet;
    public:
        Gun(int _bullet) : bullet(_bullet) {}

        void Shot() {
            cout << "BANG!" << endl;
            bullet--;
        }
};

class Police {
    private:
        int handcuffs;
        Gun* pistol;
    
    public:
        Police(int _bullet, int _handcuffs)
            : handcuffs(_handcuffs) {
                if (_bullet > 0)
                    pistol = new Gun(_bullet);
                else
                    pistol = NULL;
        }

        Police(const Police &ref) {
            // 복사 생성자는 return값이 없다. (생성자니까)
            // 항상 shallow-copy와 deep-copy를 주의하자.
            handcuffs = ref.handcuffs;

            if (ref.pistol == NULL) {
                pistol = NULL;
            } else {
                pistol = new Gun(*(ref.pistol));
            }
        }

        Police& operator=(const Police &ref) {
            // 대입 연산자는 return값이 있다. (연속적인 대입을 위함)
            // 대입 연산자는 메모리 누수에 주의해야 한다.
            // 항상 shallow-copy와 deep-copy를 주의하자.

            // 원본 객체 메모리 해제
            if (pistol != NULL)
                delete pistol;
            
            // 대입할 객체의 참조 변수는 deep-copy를 해줘야 한다.
            handcuffs = ref.handcuffs;
            if (ref.pistol == NULL)
                pistol = NULL;
            else
                pistol = new Gun(*(ref.pistol));

            return *this;
        }

        

        void PutHancuff() {
            cout << "SNAP!" << endl;
            handcuffs--;
        }

        void Shot() {
            if (pistol == NULL)
                cout << "Hut BBANG!" << endl;
            else
                pistol -> Shot();
        }

        ~Police() {
            if (pistol != NULL)
                delete pistol;
        }
};

int main(void) {
    Police pman1(5, 3);
    Police pman2 = pman1;
    pman2.PutHancuff();
    pman2.Shot();

    Police pman3(2, 4);
    pman3 = pman1;
    pman3.PutHancuff();
    pman3.Shot();
    return 0;

}
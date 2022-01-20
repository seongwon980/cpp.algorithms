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

        Police(const Police& ref) {
            handcuffs = ref.handcuffs;
            if (ref.pistol == NULL)
                pistol = new Gun(*(ref.pistol));
            else
                pistol = NULL;
        }

        Police& operator=(const Police& ref) {
            handcuffs = ref.handcuffs;
            if (pistol != NULL)
                delete pistol;
            
            if (ref.pistol != NULL)
                pistol = new Gun(*(ref.pistol));
            else
                pistol = NULL;
            
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
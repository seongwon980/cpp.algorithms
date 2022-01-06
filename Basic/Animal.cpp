#include <iostream>
using namespace std;

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);
        void show_status();
};

Marine::Marine() {      // Constructor
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {      // Constructor overloaded
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() {
    return damage;
}

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    cout << " *** Marine *** " << endl;
    cout << " Location : (" << coord_x << ", " << coord_y << ")" << endl;
    cout << " HP : " << hp << endl;
}

int main(void) {
    Marine* marines[100];       // Pointer array, each of which pointing Marine instance.
    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);

    marines[0] -> show_status();
    marines[1] -> show_status();

    delete marines[0];
    delete marines[1];
    
    return 0;
}
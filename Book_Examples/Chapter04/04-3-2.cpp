#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPositionInfo(int pos) {
        switch(pos) {
            case CLERK:
                cout << "1" << endl;
                break;
            case SENIOR:
                cout << "2" << endl;
                break;
            case ASSIST:
                cout << "3" << endl;
                break;
            case MANAGER:
                cout << "4" << endl;
                break;
        }
    }
}

class NameCard {
    private:
        char* name;
        char* company;
        char* phone;
        int position;

    public:
        NameCard(const char* _name, const char* _company, const char* _phone, int _position)
            : position(_position) {
                name = new char[strlen(_name) + 1];
                company = new char[strlen(_company) + 1];
                phone = new char[strlen(_phone) + 1];
                strcpy(name, _name);
                strcpy(company, _company);
                strcpy(phone, _phone);
            }
        
        NameCard(const NameCard &copy)
            : position(copy.position) {
                cout << "User-defined copy constructor called!" << endl;
                name = new char[strlen(copy.name) + 1];
                company = new char[strlen(copy.company) + 1];
                phone = new char[strlen(copy.phone) + 1];
                
                strcpy(name, copy.name);
                strcpy(company, copy.company);
                strcpy(phone, copy.phone);
            }
        void ShowNameCardInfo() {
            cout << "Name: " << name << endl;
            cout << "Company: " << company << endl;
            cout << "Phone: " << phone << endl;
            cout << "Status: "; COMP_POS::ShowPositionInfo(position);
            cout << endl;
        }
};

int main(void) {
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}
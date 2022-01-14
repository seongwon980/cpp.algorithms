#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
    private:
        char* name;
        int age;
    
    public:
        MyFriendInfo(const char* _name, int _age) : age(_age) {
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }

        void ShowMyFriendInfo() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class MyFriendDetailedInfo : public MyFriendInfo {
    private:
        char* addr;
        char* phone;
    
    public:
        MyFriendDetailedInfo(const char* _name, int _age, const char* _addr, const char* _phone)
            : MyFriendInfo(_name, _age) {
                addr = new char[strlen(_addr) + 1];
                phone = new char[strlen(_phone) + 1];
                strcpy(addr, _addr);
                strcpy(phone, _phone);
            }
        
        void ShowMyFriendDetailedInfo() const {
            ShowMyFriendInfo();
            cout << "Address: " << addr << endl;
            cout << "Phone number: " << phone << endl << endl;
        }
};


int main(void) {
    MyFriendDetailedInfo mfdi("Cho", 23, "Seoul, Korea", "010-8744-4383");
    mfdi.ShowMyFriendInfo();

}
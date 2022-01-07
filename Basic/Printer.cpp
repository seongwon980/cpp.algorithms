#include <iostream>
#include <cstring>
using namespace std;

class Printer {
    private:
        char* currentString;
    
    public:
        void SetString(char* newString);
        void ShowString(void);
};

void Printer::SetString(char* newString) {
    currentString = newString;
}

void Printer::ShowString() {
    cout << currentString << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();

    return 0;
}
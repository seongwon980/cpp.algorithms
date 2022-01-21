#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        int len;
        char* str;
    public:
        String();
        String(const char* s);
        String(const String &ref);
        ~String();
        String& operator= (const String &ref);
        String& operator+= (const String &ref);
        bool operator== (const String &ref);
        String operator+ (const String& ref);

        friend ostream& operator<< (ostream& os, const String &ref);
        friend istream& operator>> (istream& is, String &ref);
};

String::String() {
    len = 0;
    str = NULL;
}

String::String(const char* s) {
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}

String::String(const String &ref) {
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
}

String::~String() {
    if (str != NULL)
        delete []str;
}

String& String::operator=(const String &ref) {
    if (str != NULL)
        delete []str;
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
    return *this;
}

String& String::operator+=(const String &ref) {
    len += (ref.len - 1);
    char* tempStr = new char[len];
    strcpy(tempStr, str);
    strcat(tempStr, ref.str);

    if (str != NULL)
        delete []str;
    str = tempStr;
    return *this;
}

bool String::operator== (const String &ref) {
    return strcmp(str, ref.str) ? false : true;
}

String String::operator+ (const String& ref) {
    char* tempStr = new char[len + ref.len - 1];
    strcpy(tempStr, str);
    strcat(tempStr, ref.str);

    String temp(tempStr);
    delete []tempStr;
    return temp;
}

ostream& operator<< (ostream& os, const String &ref) {
    os << ref.str;
    return os;
}

istream& operator>> (istream& is, String &ref) {
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}

int main(void) {
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    return 0;
}
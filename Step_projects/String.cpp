#include "String.h"

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
    // Copy constructor
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);
}

String::~String() {
    // Destructor
    if (str != NULL)
        delete []str;
}

String& String::operator= (const String &ref) {
    // Memory deallocation
    if (str != NULL)
        delete []str;
    
    // Copy instance variables
    len = ref.len;
    str = new char[len];
    strcpy(str, ref.str);

    // return reference
    return *this;
}

String& String::operator+= (const String &ref) {
    len += (ref.len - 1);
    char* tempStr = new char[len];
    strcpy(tempStr, str);
    strcat(tempStr, ref.str);

    // Memory deallocation
    if (str != NULL)
        delete []str;
    str = tempStr;
    return *this;
}

bool String::operator== (const String &ref) {
    return strcmp(str, ref.str) ? false : true;
}

String String::operator+ (const String &ref) {
    char* tempStr = new char[len + ref.len - 1];
    strcpy(tempStr, str);
    strcat(tempStr, ref.str);

    // Create a new String object and return the copy.
    String temp(tempStr);

    // Memory deallocation
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
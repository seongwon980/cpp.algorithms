#include <iostream>
#include <cstring>
using namespace std;

class Book {
    private:
        char* title;
        char* isbn;
        int price;

    public:
        Book(const char* _title, const char* _isbn, int _price)
            : price(_price) {
                title = new char[strlen(_title) + 1];
                isbn = new char[strlen(_isbn) + 1];
                strcpy(title, _title);
                strcpy(isbn, _isbn);
            }
        
        void ShowBookInfo() {
            cout << "Title: " << title << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Price: " << price << endl;
        }

        ~Book() {
            delete []title;
            delete []isbn;
        }
};

class EBook : public Book {
    private:
        char* DRMKey;
    
    public:
        EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
            : Book(_title, _isbn, _price) {
                DRMKey = new char[strlen(_DRMKey) + 1];
                strcpy(DRMKey, _DRMKey);
            }
        
        void ShowEBookInfo() {
            ShowBookInfo();
            cout << "DRM: " << DRMKey << endl;
        }

        ~EBook() {
            delete []DRMKey;
        }
};

int main(void) {
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}
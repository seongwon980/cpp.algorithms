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

        Book(const Book &ref) : price(ref.price) {
            title = new char[strlen(ref.title)];
            isbn = new char[strlen(ref.isbn)];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }

        Book& operator=(const Book &ref) {
            price = ref.price;
            delete []title;
            delete []isbn;
            title = new char[strlen(ref.title)];
            isbn = new char[strlen(ref.isbn)];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);

            return *this;
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

        EBook(const EBook &ref) : Book(ref) {
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
        }

        EBook& operator=(const EBook &ref) {
            Book::operator=(ref);
            delete []DRMKey;
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);

            return *this; 
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
    EBook ebook1("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;
    ebook2.ShowEBookInfo();
    cout << endl;

    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2;
    ebook3.ShowEBookInfo();
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;


enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account {
    private:
        int accountID;
        int balance;
        char* customerName;
    
    public:
        Account(int id, int bal, char* cName)
            : accountID(id), balance(bal) {
                customerName = new char[strlen(cName) + 1];
                strcpy(customerName, cName);
            }
        
        Account(const Account &copy)
            : accountID(copy.accountID), balance(copy.balance) {
                customerName = new char[strlen(copy.customerName) + 1];
                strcpy(customerName, copy.customerName);
            }
        int GetAccountID() const {
            return accountID;
        }

        void Deposit(int money) {
            balance += money;
        }

        int Withdraw(int money) {
            if (balance < money) return 0;
            balance -= money;
            return money;
        }

        void ShowAccountInfo() const {
            cout << "계좌ID: " << accountID << endl;
            cout << "이름: " << customerName << endl;
            cout << "잔액: " << balance << endl;
        }

        ~Account() {
            delete []customerName;
        }
};

class AccountHandler {
    private:
        Account* accountArr[100];
        int accountNum;
    
    public:
        AccountHandler() : accountNum(0) {}
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccountInfo(void) const;
        ~AccountHandler() {
            for (int i = 0; i < accountNum; i++)
                delete accountArr[i];
        }
};


int main(void) {
    AccountHandler manager;
    int choice;

    while(true) {
        manager.ShowMenu();
        cout << "선택: ";;
        cin >> choice;
        cout << endl;

        switch(choice) {
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithdrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccountInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void AccountHandler::ShowMenu(void) const {
    cout << "----- Menu -----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accountArr[accountNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void) {
    int money;
    int id;
    cout << "[입금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == id) {
            accountArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "Invalid ID..." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int id;
    cout << "[출금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == id) {
            if (accountArr[i]->Withdraw(money) == 0) {
                cout << "잔액부족" << endl << endl;
                return;
            }
            cout << "출금완료" << endl;
            return;
        }
    }
    cout << "Invalid ID..." << endl << endl;
}

void AccountHandler::ShowAllAccountInfo(void) const{
    for (int i = 0; i < accountNum; i++) {
        accountArr[i]->ShowAccountInfo();
        cout << endl;
    }
}


#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;


enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};
enum {NORMAL = 1, CREDIT = 2};

class Account {
    private:
        int accountID;
        int balance;
        char* customerName;
    
    public:
        Account(int id, int bal, const char* cName)
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

        virtual void Deposit(int money) {
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

class NormalAccount : public Account {
    private:
        int interestRate;
    public:
        NormalAccount(int _accountID, int _balance, const char* _customerName, int _interestRate)
            : Account(_accountID, _balance, _customerName), interestRate(_interestRate) {}

        virtual void Deposit(int money) {
            Account::Deposit(money);
            Account::Deposit(money * (interestRate / 100.0));
        }
};

class HighCreditAccount : public NormalAccount {
    private:
        int specialRate;
    public:
        HighCreditAccount(int _accountID, int _balance, const char* _customerName, int _interestRate, int _specialRate)
            : NormalAccount(_accountID, _balance, _customerName, _interestRate), specialRate(_specialRate) {}
        
        virtual void Deposit(int money) {
            NormalAccount::Deposit(money);
            Account::Deposit(money * (specialRate / 100.0));
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
    
    protected:
        void MakeNormalAccount(void);
        void MakeCreditAccount(void);
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
    int select;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 " << endl;
    cout << "2. 신용신뢰계좌 " << endl;
    cout << "선택: ";
    cin >> select;

    if (select == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interestRate;
    cout << endl;

    accountArr[accountNum++] = new NormalAccount(id, balance, name, interestRate);
}

void AccountHandler::MakeCreditAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate;
    int creditLevel;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interestRate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch(creditLevel) {
        case 1:
            accountArr[accountNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_A);
            break;
        case 2:
            accountArr[accountNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_B);
            break;
        case 3:
            accountArr[accountNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_C);
    }
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


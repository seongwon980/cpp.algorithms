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
            cout << "����ID: " << accountID << endl;
            cout << "�̸�: " << customerName << endl;
            cout << "�ܾ�: " << balance << endl;
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
        cout << "����: ";;
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
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void) {
    int select;
    cout << "[������������]" << endl;
    cout << "1. ���뿹�ݰ��� " << endl;
    cout << "2. �ſ�ŷڰ��� " << endl;
    cout << "����: ";
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

    cout << "[���뿹�ݰ��� ����]" << endl;
    cout << "���� ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << endl;

    accountArr[accountNum++] = new NormalAccount(id, balance, name, interestRate);
}

void AccountHandler::MakeCreditAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate;
    int creditLevel;

    cout << "[�ſ�ŷڰ��� ����]" << endl;
    cout << "���� ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
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
    cout << "[�Ա�]" << endl;
    cout << "���� ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == id) {
            accountArr[i]->Deposit(money);
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "Invalid ID..." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int id;
    cout << "[���]" << endl;
    cout << "���� ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == id) {
            if (accountArr[i]->Withdraw(money) == 0) {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl;
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


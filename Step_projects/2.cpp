#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccountInfo(void);

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

        void ShowAccountInfo() {
            cout << "����ID: " << accountID << endl;
            cout << "�̸�: " << customerName << endl;
            cout << "�ܾ�: " << balance << endl;
        }

        ~Account() {
            delete []customerName;
        }
};

Account* accountArr[100];
int accountNum = 0;

int main(void) {
    int choice;
    while(true) {
        ShowMenu();
        cout << "����: ";;
        cin >> choice;
        cout << endl;

        switch(choice) {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccountInfo();
                break;
            case EXIT:
                for (int i = 0; i < accountNum; i++) {
                    delete accountArr[i];
                }
                return 0;
            
            default:
                cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void ShowMenu(void) {
    cout << "----- Menu -----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "���� ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << endl;

    accountArr[accountNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {
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

void WithdrawMoney(void) {
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

void ShowAllAccountInfo(void) {
    for (int i = 0; i < accountNum; i++) {
        accountArr[i]->ShowAccountInfo();
        cout << endl;
    }
}


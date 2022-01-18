#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::ShowMenu(void) const {
    cout << "========= Menu =========" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. ���¹�ȣ ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void) {
    int select;
    cout << "[������������]" << endl;
    cout << "1. ���뿹�ݰ���" << endl;
    cout << "2. �ſ�ŷڰ���" << endl;
    cout << "���� : ";
    cin >> select;

    if (select == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
    int accountID;
    char customerName[NAME_LEN];
    int balance;
    int interestRate;

    cout << "[���뿹�ݰ��� ����]" << endl;
    cout << "���� ID: "; cin >> accountID;
    cout << "�̸�: "; cin >> customerName;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << endl;

    accountArr[accountNum++] = new NormalAccount(accountID, balance, customerName, interestRate);
}

void AccountHandler::MakeCreditAccount(void) {
    int accountID;
    char customerName[NAME_LEN];
    int balance;
    int interestRate;
    int creditLevel;

    cout << "[�ſ�ŷڰ��� ����]" << endl;
    cout << "���� ID: "; cin >> accountID;
    cout << "�̸�: "; cin >> customerName;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch(creditLevel) {
        case 1:
            accountArr[accountNum++] = new HighCreditAccount(accountID, balance, customerName, interestRate, LEVEL_A);
            break;
        case 2:
            accountArr[accountNum++] = new HighCreditAccount(accountID, balance, customerName, interestRate, LEVEL_B);
            break;
        case 3:
            accountArr[accountNum++] = new HighCreditAccount(accountID, balance, customerName, interestRate, LEVEL_C);
    }
}

void AccountHandler::DepositMoney(void) {
    int money;
    int accountID;
    cout << "[�Ա�]" << endl;
    cout << "���� ID: "; cin >> accountID;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == accountID) {
            accountArr[i]->Deposit(money);
            cout << "�Ա� �Ϸ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�. " << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int accountID;
    cout << "[���]" << endl;
    cout << "���� ID: "; cin >> accountID;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == accountID) {
            if (accountArr[i]->WithDraw(money) == 0) {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

AccountHandler::AccountHandler() : accountNum(0) {}

void AccountHandler::ShowAllAccountInfo(void) const {
    for (int i = 0; i < accountNum; i++) {
        accountArr[i]->ShowAccountInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler() {
    for (int i = 0; i < accountNum; i++) {
        delete accountArr[i];
    }
}
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu(void) const {
    cout << "========= Menu =========" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌번호 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void) {
    int select;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌" << endl;
    cout << "2. 신용신뢰계좌" << endl;
    cout << "선택 : ";
    cin >> select;

    if (select == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
    int accountID;
    // char customerName[NAME_LEN];
    String customerName;
    int balance;
    int interestRate;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> accountID;
    cout << "이름: "; cin >> customerName;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interestRate;
    cout << endl;

    accountArr[accountNum++] = new NormalAccount(accountID, balance, customerName, interestRate);
}

void AccountHandler::MakeCreditAccount(void) {
    int accountID;
    // char customerName[NAME_LEN];
    String customerName;
    int balance;
    int interestRate;
    int creditLevel;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> accountID;
    cout << "이름: "; cin >> customerName;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interestRate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
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
    cout << "[입금]" << endl;
    cout << "계좌 ID: "; cin >> accountID;
    cout << "입금액: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == accountID) {
            accountArr[i]->Deposit(money);
            cout << "입금 완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID입니다. " << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int accountID;
    cout << "[출금]" << endl;
    cout << "계좌 ID: "; cin >> accountID;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < accountNum; i++) {
        if (accountArr[i]->GetAccountID() == accountID) {
            if (accountArr[i]->WithDraw(money) == 0) {
                cout << "잔액부족" << endl << endl;
                return;
            }
            cout << "출금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID입니다." << endl << endl;
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
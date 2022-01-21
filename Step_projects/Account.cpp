#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int _accountID, int _balance, const char* _customerName)
    : accountID(_accountID), balance(_balance) {
        customerName = new char[strlen(_customerName) + 1];
        strcpy(customerName, _customerName);
    }

Account::Account(const Account &ref)
    : accountID(ref.accountID), balance(ref.balance) {
        customerName = new char[strlen(ref.customerName) + 1];
        strcpy(customerName, ref.customerName);
}

Account& Account::operator=(const Account &ref) {
    accountID = ref.accountID;
    balance = ref.balance;

    delete []customerName;
    customerName = new char[strlen(ref.customerName) + 1];
    strcpy(customerName, ref.customerName);
    return *this;
}

int Account::GetAccountID() const {
    return accountID;
}

void Account::Deposit(int money) {
    balance += money;
}

int Account::WithDraw(int money) {
    if (balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccountInfo() const {
    cout << "ID: " << accountID << endl;
    cout << "Name: " << customerName << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account() {
    delete []customerName;
}

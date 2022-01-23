#include <iostream>
#include <cstring>
using namespace std;

class DepositException {
    private:
        int requestedDeposit;
    public:
        DepositException(int money) : requestedDeposit(money) {}
        void ShowExceptionReason() {
            cout << "[Exception message: " << requestedDeposit << " is invalid amount of money\n";
        }
};

class WithdrawException {
    private:
        int balance;
    public:
        WithdrawException(int money) : balance(money) {}
        void ShowExceptionReason() {
            cout << "[Exception message: " << balance << ", no...]" << endl;
        }
};

class Account {
    private:
        char accountNum[50];
        int balance;
    
    public:
        Account(char* acc, int money) : balance(money) {
            strcpy(accountNum, acc);
        }
        void Deposit(int money) {
            if (money < 0) {
                DepositException expn(money);
                throw expn;
            }
            balance += money;
        }

        void Withdraw(int money) {
            if (money > balance)
                throw WithdrawException(balance);
            balance -= money;
        }
        void ShowMoney() {
            cout << "Remains: " << balance << endl << endl;
        }
};

int main(void) {
    Account myAcc("56789-827120", 5000);

    try {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    } catch (DepositException &expn) {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMoney();

    try {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    } catch (WithdrawException &expn) {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMoney();
    return 0;
}
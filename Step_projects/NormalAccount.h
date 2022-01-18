#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

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
#endif
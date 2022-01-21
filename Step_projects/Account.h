#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"
class Account {
    private:
        int accountID;
        int balance;
        String customerName;

    public:
        Account(int _accountID, int _balance, String _customerName);
        // Account(int _accountID, int _balance, char* _customerName);
        // Account(const Account &ref);
        // Account& operator=(const Account &ref);
        
        int GetAccountID() const;
        virtual void Deposit(int money);
        int WithDraw(int money);
        void ShowAccountInfo() const;
        // ~Account();
};
#endif

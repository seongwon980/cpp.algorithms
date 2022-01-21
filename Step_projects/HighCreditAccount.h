#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
    private:
        int specialRate;
    public:
        // HighCreditAccount(int _accountID, int _balance, const char* _customerName, int _interestRate, int _specialRate)
        //     : NormalAccount(_accountID, _balance, _customerName, _interestRate), specialRate(_specialRate) {}
        
        HighCreditAccount(int _accountID, int _balance, String _customerName, int _interestRate, int _specialRate)
            : NormalAccount(_accountID, _balance, _customerName, _interestRate), specialRate(_specialRate) {}

        virtual void Deposit(int money) {
            NormalAccount::Deposit(money);
            Account::Deposit(money * (specialRate / 100.0));
        }
};
#endif
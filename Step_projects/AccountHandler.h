#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler {
    private:
        Account* accountArr[100];
        int accountNum;
    public:
        AccountHandler();
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccountInfo(void) const;
        ~AccountHandler();
    protected:
        void MakeNormalAccount(void);
        void MakeCreditAccount(void);
};
#endif
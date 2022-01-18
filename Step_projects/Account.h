#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
    private:
        int accountID;
        int balance;
        char* customerName;

    public:
        Account(int _accountID, int _balance, const char* _customerName);
        Account(const Account &ref);

        int GetAccountID() const;
        virtual void Deposit(int money);
        int WithDraw(int money);
        void ShowAccountInfo() const;
        ~Account();
};
#endif

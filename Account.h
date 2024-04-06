//Account Header

#ifndef _ACCOUNT_
#define _ACCOUNT_
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class Account
{
protected:
    int id;
    double balance;
    int withdrawals;
    int deposits;
    Customer accountCustomer;

public:

    Account();

    Account(int _id, double _balance, string _fName, string _lName, string _address, string _phone, string _email);

    void deposit(double amount);


    void withdraw(double amount);


    void printInfo();


    //setter
    void setId(int _id);

    void setBalance(double _balance);

    void setWithdrawals(int _withdrawals);

    void setAccountCustomer(string _fName, string _lName, string _address, string _phone, string _email);

    void setAll(int _id, double _balance, int _withdrawals, int _deposits, string _fName, string _lName, string _address, string _phone, string _email);

    //getters
    int getId() const;

    double getBalance() const;

    int getWithdrawals() const;


    const Customer getAccountCustomer() const
    {
        return accountCustomer;
    }
};

#endif // !_ACCOUNT_
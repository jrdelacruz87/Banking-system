//Savings Account Header

#ifndef _SAVING_ACCOUNT_
#define _SAVING_ACOUNT_
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
class SavingAccount : public Account
{
    double interestRate;

public:
    //constructors
    SavingAccount() : Account()
    {
        interestRate = 0;
    }

    SavingAccount(double _interestRate, int _id, double _balance, string& _fName, string& _lName, string& _address, string& _phone, string& _email)
        : Account(_id, _balance, _fName, _lName, _address, _phone, _email)
    {
        interestRate = _interestRate;
    }

    void getInterest();


    void setInterestRate(double _interestRate);


    double getInterestRate() const;

};
#endif // !_SAVING_ACCOUNT_
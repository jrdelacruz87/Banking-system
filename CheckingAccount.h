//Checking Account Header

#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_
#include <iostream>
#include <string>
#include "Account.h"  
using namespace std;
class CheckingAccount : public Account
{
    double overDraftLimit;

public:
    //contructors
    CheckingAccount() : Account()
    {
        overDraftLimit = 0;
    }

    CheckingAccount(int _id, double _balance, string& _fName, string& _lName, string& _address,
        string& _phone, string& _email)
        : Account(_id, _balance, _fName, _lName, _address, _phone, _email)
    {
        overDraftLimit = overDraftLimit;

    }

    void withdraw(double amount);


    double getOverDraftLimit() const;


    void setOverDraftLimit(double _overDraftLimit);


};


#endif // !_CHECKING_ACCOUNT_
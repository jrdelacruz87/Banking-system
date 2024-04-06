//Checking Account Cpp
#include<iostream>
#include<string>
#include <iomanip>
#include "CheckingAccount.h"
void CheckingAccount::withdraw(double amount)
{
    setOverDraftLimit(100);

    if (amount <= 0) 
    {
            cout << "Withdrawal amount must be positive." << endl;
    }

    else if (balance >= amount) 
    {// If there's enough balance, proceed as normal
        Account::withdraw(amount);
    }

    else if (balance < amount && (amount - balance) <= overDraftLimit) 
    {
    // If the withdrawal amount is within the overdraft limit
    cout << "Overdraft protection used. An additional $20 service fee charged." << endl;
    balance -= (amount + 20); // Withdraw the amount plus a $20 fee
    withdrawals++; // Update withdrawal count
    cout << "Withdrew $" << fixed << setprecision(2) << amount << ". Current balance: $" << balance << "." << endl;
    }

    else 
    {
    // If the withdrawal amount exceeds the overdraft limit
    cout << "Withdrawal failed: Amount exceeds overdraft limit. Current balance: $" << balance << ", Overdraft limit: $" << overDraftLimit << "." << endl;
    }
}

double CheckingAccount::getOverDraftLimit() const
{
    return overDraftLimit;
}
void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
    CheckingAccount::overDraftLimit = _overDraftLimit;
}
//Savings Account Cpp

#include "SavingAccount.h"
void SavingAccount::getInterest()
{
    setInterestRate(5);

    double interest = balance * interestRate;
    balance = balance + interest;
    cout << "Interest added: $" << interest << "New balance: $" << balance << endl;
}
void SavingAccount::setInterestRate(double _interestRate)
{
    interestRate = _interestRate;
}
double SavingAccount::getInterestRate() const
{
    return interestRate;
}
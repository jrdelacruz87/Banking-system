//Account Cpp
#include<iostream>
#include<string>
#include<iomanip>
#include "Account.h"

Account::Account()
{
    id = 0;
    balance = 0;
    withdrawals = 0;
    deposits = 0;
    accountCustomer.setAll("", "", "", "", "");
}
Account::Account(int _id, double _balance, string _fName, string _lName, string _address, string _phone, string _email)
{
    id = _id;
    balance = _balance;
    withdrawals = 0;
    deposits = 0;
    accountCustomer.setAll(_fName, _lName, _address, _phone, _email);
}

void Account::deposit(double amount)
{
    if (amount > 0) 
    {
        balance += amount;
        deposits++;
        cout << "Deposited $" << fixed << setprecision(2) << amount << " to the account." << endl;
    }
    else 
    {
        cout << "Invalid deposit amount." << endl;
    }
}

void Account::withdraw(double amount)
{
    if (amount <= 0) 
    {
        cout << "Withdrawal amount must be positive." << endl;
    }
    else if (balance >= amount) 
    {
        balance -= amount; // Subtract the amount from the balance
        withdrawals++; // Increment the number of withdrawals
        cout << "Withdrew $" << fixed << setprecision(2) << amount << " from the account. Current balance: $" << balance << "." << endl;
    }
    else 
    {
        // Insufficient funds
        cout << "Withdrawal failed: Insufficient funds. Attempted to withdraw $" << amount << ", but the current balance is $" << balance << "." << endl;
    }
}

void Account::printInfo()
{
    cout << "Account ID: " << id << endl;
    cout << "Current Balance: " << balance << endl;
    cout << "Number of Withdrawals: " << withdrawals << endl;
    cout << "Number of Deposits: " << deposits << endl;
    accountCustomer.Customer::printInfo();
}
void Account::setId(int _id)
{
    id = _id;
}
void Account::setBalance(double _balance)
{
    balance = _balance;
}
void Account::setWithdrawals(int _withdrawals)
{
    withdrawals = _withdrawals;
}
void Account::setAccountCustomer(string _fName, string _lName, string _address, string _phone, string _email)
{
    accountCustomer.setFname(_fName);
    accountCustomer.setLname(_lName);
    accountCustomer.setAddress(_address);
    accountCustomer.setPhone(_phone);
    accountCustomer.setEmail(_email);

}
void Account::setAll(int _id, double _balance, int _withdrawals, int _deposits, string _fName, string _lName, string _address, string _phone, string _email)
{
    id = _id;
    balance = _balance;
    withdrawals = _withdrawals;
    deposits = _deposits;
    accountCustomer.setAll(_fName, _lName, _address, _phone, _email);
}
int Account::getId() const
{
    return id;
}
double Account::getBalance() const
{
    return balance;
}
int Account::getWithdrawals() const
{
    return withdrawals;
}
//Main file

#include <iostream>
#include <string>
#include <iomanip>

#include "Account.h"
#include "SavingAccount.h"
#include "Customer.h"
#include "CheckingAccount.h"

using namespace std;

//global variable

int id;
string fName, lName, address, phone, email;
double balance;
int withdrawals;
int deposits;
CheckingAccount* checkings = nullptr;
int numCheckings = 0;

SavingAccount* savings = nullptr;
int numSavings = 0;

string nun;

//prototypes

void addChecking();
void addSaving();
void viewCheckingAccounts();
void viewSavingAccounts();

void modifyCheckingAccount();

void depositToAccount();
void withdrawFromAccount();



int main()
{
    //Customer cust1("John", "Doe", "123 Elm St", "555-1234", "johndoe@example.com");
    //CheckingAccount chkAccount1(1001, 500.00, cust1, 200.00);
    //SavingAccount savAccount1(2001, 1000.00, cust1, 2.0);

    //// Example operations
    //chkAccount1.deposit(200);
    //chkAccount1.withdraw(250);
    //chkAccount1.printInfo();

    //savAccount1.getInterestRate();
    //savAccount1.printInfo();


    int ans;
   
   

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create Checking Account" << endl;
        cout << "2. Create Saving Account" << endl;
        cout << "3. View Checking Accounts Information" << endl;
        cout << "4. View Savings Accounts Information" << endl;
        cout << "5. Delete Checking Account" << endl;
        cout << "6. Delete Saving Account" << endl;
        cout << "7. Modify Checking Account" << endl;
        cout << "8. Modify Saving Account" << endl;
        cout << "9. Deposit to Account" << endl;
        cout << "10. Withdraw from Account" << endl;
        cout << "11. Transfer from Account" << endl;
        cout << "12. Exit" << endl;
        cout << "Choose an option: ";
        cin >> ans;

        if (ans == 1)
        {
            addChecking();

        }
        else if (ans == 2)
        {
            addSaving();
        }

        else if (ans == 3)
        {
            viewCheckingAccounts();
        
        }
        else if (ans == 4)
        {
            viewSavingAccounts();

        }
        else if (ans == 7)
        {
            modifyCheckingAccount();

        }
        else if (ans == 9)
        {
            depositToAccount();

        }
        else if (ans == 10)
        {
            withdrawFromAccount();

        }
        
        else if (ans == 12)
        {
            cout << "Exiting" << endl;
            break;
        }
        else
        {
            cout << "\nInvalid Option. Please input valid option." << endl;
        }
        
    }
    delete[] checkings;
    delete[] savings;

    checkings = nullptr;
    savings = nullptr;

    system("pause");
    return 0;

}

void addChecking()
{
    cout << "How many savings accounts do you want to create?" << endl;
    cin >> numCheckings;

    checkings = new CheckingAccount[numCheckings];

    for (int i = 0; i < numCheckings; i++)
    {
        cout << "Enter First Name: ";
        cin >> fName;
        cout << "Enter Last Name: ";
        cin >> lName;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email Address: ";
        getline(cin, email);

        cout << "Enter Account ID: ";
        cin >> id;
        cout << "Enter Balance: $";
        cin >> balance;

        checkings[i].setAccountCustomer(fName, lName, address, phone, email);
        checkings[i].setBalance(balance);
        checkings[i].setId(id);
        checkings[i].setWithdrawals(0);
        checkings[i].deposit(0);

        cout << "Account Created!" << endl;
    }
}

void addSaving()
{
    cout << "How many savings accounts do you want to create?" << endl;
    cin >> numSavings;

    savings = new SavingAccount[numSavings];

    for (int i = 0; i < numSavings; i++)
    {
        cout << "Enter First Name: ";
        cin >> fName;
        cout << "Enter Last Name: ";
        cin >> lName;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email Address: ";
        getline(cin, email);

       /* cout << "Enter Account ID: ";
        cin >> id;*/

        savings[i].setAccountCustomer(fName, lName, address, phone, email);
        savings[i].setBalance(balance);
        savings[i].setId(id);
        savings[i].setWithdrawals(0);
        savings[i].deposit(0);

        cout << "Account Created!" << endl;
    }
    
}

void viewCheckingAccounts()
{
    cout << "\nChecking Accounts:" << endl;

    for (int i = 0; i < numCheckings; ++i)
    {
        checkings[i].printInfo();
    }
}

void viewSavingAccounts()
{
    cout << "\Saving Accounts:" << endl;

    for (int i = 0; i < numSavings; ++i)
    {
        savings[i].printInfo();
    }
}


void modifyCheckingAccount()
{
    if (numCheckings == 0) 
    {
        cout << "\nThere are no Checking Accounts to modify." << endl;
        return; // Exit the function early
    }

    int accountId;

    cout << "\nEnter Checking Account ID to modify: ";
    cin >> accountId;
    //clearCin();

    for (int i = 0; i < numCheckings; ++i)
    {
        if (checkings[i].getId() == accountId)
        {
            checkings[i] = CheckingAccount();
            cout << "\nSuccessfully modified Checking Account." << endl;
            return;
        }
    }
    cout << "\nAccount not found." << endl;
}

void depositToAccount()
{
    if (numCheckings == 0 && numSavings == 0)
    {
        cout << "\nThere are no Accounts." << endl;
        return; // Exit the function early
    }

    int accountType, id;
    double amount;

    cout << "\nSelect account type (1 for Checking, 2 for Saving): ";
    cin >> accountType;
    //clearCin();

    if (accountType != 1 && accountType != 2)
    {
        cout << "Invalid account type selected. Please select 1 for Checking or 2 for Saving." << endl;
        return; // Exit 
    }

    cout << "Enter account ID: ";
    cin >> id;
    //clearCin();

    if (accountType == 1)
    {
        for (int i = 0; i < numCheckings; ++i)
        {
            if (id == checkings[i].getId())
            {
                cout << "Enter amount to deposit: $";
                cin >> amount;
                //clearCin();

                checkings[i].deposit(amount);
                cout << "Deposit successful." << endl;
                return; // Exit function after successful operation
            }
        }
    }

    else
    { // accountType == 2, already validated
        for (int i = 0; i < numSavings; ++i)
        {
            if (id == savings[i].getId())
            {
                cout << "Enter amount to deposit: $";
                cin >> amount;
                //clearCin();

                savings[i].deposit(amount);
                cout << "Deposit successful." << endl;
                return; // Exit function 
            }
        }
    }

    cout << "Account not found." << endl;
}

void withdrawFromAccount()
{
    if (numCheckings == 0 && numSavings == 0)
    {
        cout << "\nThere are no Accounts." << endl;
        return; // Exit the function early
    }

    int accountType, id;
    double amount;

    cout << "\nSelect account type (1 for Checking, 2 for Saving): ";
    cin >> accountType;
    //clearCin();

    cout << "Enter account ID: ";
    cin >> id;
    //clearCin();

    cout << "Enter amount to withdraw: $";
    cin >> amount;
    //clearCin();

    if (accountType == 1)
    {
        for (int i = 0; i < numCheckings; ++i)
        {
            if (checkings[i].getId() == id)
            {
                checkings[i].withdraw(amount);
                //cout << "Withdrawal successful." << endl;
                return;
            }
        }
    }
    else if (accountType == 2)
    {
        for (int i = 0; i < numSavings; ++i)
        {
            if (savings[i].getId() == id)
            {
                savings[i].withdraw(amount);
                //cout << "Withdrawal successful." << endl;
                return;
            }
        }
    }
    else
    {
        cout << "Invalid account type selected." << endl;
    }

    cout << "Account not found." << endl;
}

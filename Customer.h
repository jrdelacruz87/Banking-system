//Customer Header

#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <iostream>
#include <string>
using namespace std;

class Customer
{
	string fName, lName, address, phone, email;
public:
	Customer();
	Customer(string fName, string lName, string address, string phone, string email);
	void setFname(string _fname);
	void setLname(string _lname);
	void setAddress(string _address);
	void setPhone(string _phone);
	void setEmail(string _email);
	string getfname()const;
	string getLname()const;
	string getAddress()const;
	string getPhone() const;
	string getEmail() const;
	void printInfo();
	void setAll(string _fName, string _lName, string _address, string _phone, string _email);

};
#endif // !
//Customer cpp
#include<iomanip>
#include<string>
#include "Customer.h"
Customer::Customer()
{
	fName = " ";
	lName = " ";
	address = " ";
	phone = " ";
	email = " ";

}
Customer::Customer(string _fName, string _lName, string _address, string _phone, string _email)
{
	fName = _fName;
	lName = _lName;
	address = _address;
	phone = _phone;
	email = _email;
}
void Customer::setFname(string _fname)
{
	fName = _fname;
}
void Customer::setLname(string _lname)
{
	lName = _lname;
}
void Customer::setAddress(string _address)
{
	address = _address;
}
void Customer::setPhone(string _phone)
{
	phone = _phone;
}
void Customer::setEmail(string _email)
{
	email = _email;
}
string Customer::getfname()const
{
	return fName;
}
string Customer::getLname()const
{
	return lName;
}
string Customer::getAddress()const
{
	return address;
}
string Customer::getPhone() const
{
	return phone;
}
string Customer::getEmail() const
{
	return email;
}
void Customer::printInfo()
{
	cout << left
		<< setw(15) << "First Name"
		<< setw(15) << "Last Name"
		<< setw(25) << "Address"
		<< setw(15) << "Phone"
		<< setw(25) << "Email" << endl;

	cout << left
		<< setw(15) << fName
		<< setw(15) << lName
		<< setw(25) << address
		<< setw(15) << phone
		<< setw(25) << email << endl;
}
void Customer::setAll(string _fName, string _lName, string _address, string _phone, string _email)
{
	fName = _fName;
	lName = _lName;
	address = _address;
	phone = _phone;
	email = _email;
}
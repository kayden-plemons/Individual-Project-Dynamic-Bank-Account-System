#include "account.h"
#include <iostream>

Account::Account()
{
	acctNumber = nullptr;;
	name = "";
	balance = 0.0;	
	//cout<<"Default constructor called."<<endl;
}
int Account::nextAcct = 1000;

Account::~Account() { delete acctNumber; } //deconstructor
Account::Account(const Account &other)
{
    // Allocate memory for the new account number and copy the value
    if (other.acctNumber != nullptr) {
        acctNumber = new int(*(other.acctNumber));
    } else {
        acctNumber = nullptr;
    }
    // Copy the name and balance
    name = other.name;
    balance = other.balance;
}

Account& Account::operator+=(double amount) {
    // Add the amount to the balance of this account
    this->balance += amount;
    return *this;
}

// Overloaded operator-= to subtract an amount from the balance
Account& Account::operator-=(double amount) {
    // Subtract the amount from the balance of this account
    this->balance -= amount;
    return *this;
}

bool Account::deposit(double tempAmount) {
    
	if (tempAmount <= 0)
	{
		return false;
	}
	 return true;
}

bool Account::withdraw(double tempAmount) {
    
	if (tempAmount <= 0)
	{
		return false;
	}
	 return true;
}



//setters
void Account::setAcctNum(int tempAcctNum) { acctNumber = new int(tempAcctNum); }
void Account::setName(const string& tempName) { name = tempName; }
void Account::setBalance(double tempBalance) { balance = tempBalance; }

//getters
int* Account::getAcctNum() const { return acctNumber; }
string Account::getName() const { return name; }
double Account::getBalance() const { return  balance; }




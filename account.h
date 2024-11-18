#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Account {
	public:
		Account(); //Default constructor
		Account(const Account &other); //constructor overload
		//Account& operator+=(const Account& other);
		Account& operator+=(double amount);
		Account& operator-=(double amount);
		~Account();
		static int nextAcct;
		
		void setAcctNum(int tempAcctNum);
		void setName(const string& tempName);
		void setBalance(double tempBalance); //test
		
		int* getAcctNum() const;
		string getName() const;
		double getBalance() const;
		
		bool deposit(double tempAmount); //just to make sure amount isnt 0 or less than.
		bool withdraw(double tempAmount);
	
	private:
		int *acctNumber;
		string name;
		double balance;	
	
};

#endif

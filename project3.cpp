#include "account.h"
#include "project3.h"
#include <iostream>
#include <vector> 
#include <iomanip>
#include <algorithm>
using namespace std;

void openAccount(vector<Account>& accts)
{
	// Prompt the user for account name and initial deposit
	string name;
    double initialDeposit;

    cout << "Enter customer account name: ";
	cin.ignore();
    getline(cin,name);
    cout << "Enter initial deposit amount: $";
    cin >> initialDeposit;

	if (initialDeposit >= 0)
	{
    // Generate the account number from the static variable nextAcct
    int accountNumber = Account::nextAcct++;

    // Create a new Account object with the provided information
    Account newAccount;
    newAccount.setAcctNum(accountNumber);
    newAccount.setName(name);
   
	
	//setting balance
	double tempBalance=0;
	tempBalance+=initialDeposit;
	newAccount.setBalance(tempBalance);
	

    // Add the new Account object to the vector of accounts
    accts.push_back(newAccount);

    // Print status message with account details
	cout<<endl;
    cout << "New account opened successfully." << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Name: " << name << endl;
    cout << "Initial Deposit: $" << fixed << setprecision(2) << initialDeposit << endl;
	}
	else 
	{
		cout<<"Account not created."<<endl;
	}
}
void deposit(vector<Account>& accts)
{
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;
    bool deposit = false;
	int acctNum=0;

    for (size_t i = 0; i < accts.size(); ++i)
    {
        if (accountNumber == *accts[i].getAcctNum()) // Corrected comparison
        {
			cout<<endl;
            cout << "Account found. Enter name for security purposes: ";
            string name;
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, name);
            if (name == accts[i].getName())
            {
                cout << "Verification successful." << endl;
				acctNum=i;
                deposit = true;
                break; // Exit the loop if verification is successful
            }
            else
            {
                cout << "Verification failed." << endl;
                break; // Exit the loop if verification fails
            }
        }
		
    }

	
    if (deposit)  //checking if account number matches
    {
		double tempAmount= accts[acctNum].getBalance();
		double deposit;
        cout << "Enter deposit amount: $";
		cin>>deposit;
		
		
		if (accts[acctNum].deposit(deposit) == true)
		{
		accts[acctNum].setBalance(tempAmount + deposit);
		cout<<"Deposit successful."<<endl;
		cout<<"New balance: $"<<accts[acctNum].getBalance()<<endl;
		}
		else 
		{
			cout<<"Invalid deposit."<<endl;
			return;
		}
		
    }
    else
    {
		cout<<endl;
        cout << "Account not found." << endl;
    }
}
void withdraw(vector<Account>& accts)
{
	int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;
    bool withdraw = false;
	int acctNum=0;

    for (size_t i = 0; i < accts.size(); ++i)
    {
        if (accountNumber == *accts[i].getAcctNum()) // Corrected comparison
        {
			cout<<endl;
            cout << "Account found. Enter name for security purposes: ";
            string name;
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, name);
            if (name == accts[i].getName())
            {
                cout << "Verification successful." << endl;
				acctNum=i;
                withdraw = true;
                break; // Exit the loop if verification is successful
            }
            else
            {
                cout << "Verification failed." << endl;
                break; // Exit the loop if verification fails
            }
        }
		
    }

	
    if (withdraw)  //checking if account number matches
    {
		double tempAmount= accts[acctNum].getBalance();
		double withdraw;
        cout << "Enter withdraw amount: $";
		cin>>withdraw;
		
		if (tempAmount >= withdraw)
		{
		if (accts[acctNum].withdraw(withdraw) == true)
		{
		accts[acctNum].setBalance(tempAmount - withdraw);
		cout<<"Withdraw successful."<<endl;
		cout<<"New balance: $"<<accts[acctNum].getBalance()<<endl;
		}
		else 
		{
			cout<<"Invalid withdraw."<<endl;
			return;
		}
		}
		else {
			cout<<"Insufficient funds. "<<endl;
		}
    }
    else
    {
		cout<<endl;
        cout << "Account not found." << endl;
    }
}

void fastTransfer(vector<Account>& accts)
{
	int srcAccountNumber, dstAccountNumber;
    cout << "Enter source account number: ";
    cin >> srcAccountNumber;
    cout << "Enter destination account number: ";
    cin >> dstAccountNumber;

    // Find the indices of the source and destination accounts
    int srcIndex = -1, dstIndex = -1;
    for (size_t i = 0; i < accts.size(); ++i) {
        if (*accts[i].getAcctNum() == srcAccountNumber) {
            srcIndex = i;
        } else if (*accts[i].getAcctNum() == dstAccountNumber) {
            dstIndex = i;
        }
    }
	
	
	
    // Check if both accounts exist
     if (srcIndex != -1 && dstIndex != -1) {
        // Check if source account has sufficient balance
        if (accts[srcIndex].getBalance() >= 40.0) {
            // Perform fast transfer
           // accts[srcIndex].setBalance(accts[srcIndex].getBalance() - 40.0); // Subtract $40 from source
           // accts[dstIndex].setBalance(accts[dstIndex].getBalance() + 40.0); // Add $40 to destination
			accts.at(dstIndex) += 40.0; // Add $40 to destination account
			accts.at(srcIndex) -= 40.0; // Subtract $40 from source account
			cout<<endl;
            cout << "Fast transfer successful." << endl;
            cout << "Transferred $40.00 from account " << srcAccountNumber << " to account " << dstAccountNumber << "." << endl;
            cout << "New balance of destination account " << dstAccountNumber << ": $" << accts[dstIndex].getBalance() << endl;
            cout << "New balance of source account " << srcAccountNumber << ": $" << accts[srcIndex].getBalance() << endl;
        } else {
            cout << "\nInsufficient funds in the source account." << endl;
        }
    } else {
        cout << "One or both of the accounts do not exist." << endl;
    }

}

void printAccount(vector<Account> accts) //prints accounts
{
	//checks if accounts empty 
	if(accts.empty()){
		cout << "No accounts found."<<endl;
		return;
	}
	cout<<endl;
	cout<<"----------Bank Accounts----------"<<endl;
	cout<<"Account#"<<"    "<<"Name"<<"      "<<"Balance"<<endl;
	cout<<"---------------------------------"<<endl;
	for (size_t i=0; i < accts.size(); ++i)
	{
		cout<<*accts[i].getAcctNum()<<"      "<<accts[i].getName()<<"       "<<accts[i].getBalance()<<endl;
	}
}

int main() {
    
	cout<<endl;
	cout<<"\t"<<"\t"<<"Computer Science and Engineering"<<endl;
	cout<<"\t"<<"\t"<<"CSCE 1040 - Computer Science II"<<endl;
	cout<<"\t"<<"Kayden Plemons, krp0190, kaydenplemons@my.unt.edu"<<endl;
	cout<<endl;

    vector<Account> accounts;

    int choice;
    do {
		cout<<endl;
        cout << "-------Menu-------"<<endl;
        cout << "1. Open new account\n";
        cout << "2. Deposit into account\n";
        cout << "3. Withdraw from account\n";
		cout << "4. Fast transfer $40 into account\n";
        cout << "5. Print a list of all accounts\n";
        cout << "6. End transaction (Exit)\n";
        cout << "Enter your choice (1-6): ";
        
		char input[100];
		cin>>input; 
		choice=atoi(input);  //checks if valid input
		
        switch (choice) {
            case 1:
                // Call function to open a new account
                openAccount(accounts);
                break;
            case 2:
                // Call function to deposit into account
                deposit(accounts);
                break;
            case 3:
                // Call function to withdraw from account
                withdraw(accounts);
                break;
			case 4:
				//Call function to fast transfer 40 between accounts
				fastTransfer(accounts);
				break;
            case 5:
                // Call function to print list of all accounts
                printAccount(accounts);
                break;
            case 6:
				cout<<endl;
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
				cout<<endl;
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}

//Rifa Safeer Shah
//CECS 282 LAB 2 PROBLEM 1

#include <iostream>
#include <cmath>
using namespace std;

class Account
{
	public:
		double amount;
		double bal;
		Account(double money)
		{
			amount = money;
		} //Set amount in account = money
		
		double get_balance()
		{
			return amount;
		} //Return balance
		
		void deposit(double money)
		{
			if (money < 0)
			{
				return;
			}
			else
			{
				amount = amount + money;
			}
		} //Deposit money to the account
		
		void withdraw(double money)
		{
			bal = amount - money;
			if (bal < 0)
			{
				amount = amount - 20; //Penalty if more than balance is withdrawn
			}
			else
			{
				amount = bal;
			}
		} //Withdraw money from the account
};

int main()
{
	Account my_account(100); //Set up my account with $100
	my_account.deposit(50); //Deposit $50
	my_account.withdraw(175); //Penalty of $20 will apply
	my_account.withdraw(25); //Withdraw $25
	
	cout << "Account balance: " << my_account.get_balance() << "\n";
	
	my_account.withdraw(my_account.get_balance());
	cout << "Account balance: " << my_account.get_balance() << "\n";
	
	return 0;
}

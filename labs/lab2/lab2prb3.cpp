//Rifa Safeer Shah
//CECS 282 LAB 2 PROBLEM 3

#include <iostream>
#include <cmath>
using namespace std;

class Bank{
	public:
	double s_amount, c_amount, rate;
	Bank(){
		s_amount = 0;
		c_amount = 0;
		rate = 6;
	}
	Bank(double a, double r){
		s_amount = a;
		rate = r;
	}
	void deposit(double a, string account){
		if (a < 0)
		{
		return;
		}
		if (account == "S"){
			s_amount += a;
		}
		if (account == "C"){
			c_amount += a;
		}
	}
	void withdraw(double a, string account){
		if (s_amount - a < 0)
		{
			s_amount = s_amount - 20;
		}
		if (c_amount - a < 0)
		{
			c_amount = c_amount - 20;
		}
		if (account == "S"){
			s_amount -= a;
		}
		if (account == "C"){
			c_amount -= a;
		}
	}
	void print_balances()
	{
		cout << "Saving Amount is : " << s_amount << endl;
		cout << "Checking Amount is : " << c_amount << endl;
	}
	void transfer(double amount, string account)
	{
			if (account == "C"){
				if (c_amount - amount < 0){
					c_amount -= 20;
					return;
				}
				c_amount -= amount;
				s_amount += amount;
			}
			if (account == "S"){
				if (s_amount - amount < 0){
					s_amount -= 20;
					return;
				}
				s_amount -= amount;
				c_amount += amount;
			}
		}
		
};
int main(){
	Bank my_bank;
	cout << "Inital bank balances: \n";
	my_bank.print_balances(); /* set up empty accounts */
	
	cout << "Adding some money to accounts: \n";
	my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
	my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
	my_bank.print_balances();
	
	cout << "Taking out $1500 from checking,and moving $200 from";
	cout << " savings to checking.\n";
	my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
	my_bank.transfer(200, "S"); /* transfer $200 from savings */
	my_bank.print_balances();
	
	cout << "Trying to transfer $900 from Checking.\n";
	my_bank.transfer(900,"C");
	my_bank.print_balances();
	
	cout << "trying to transfer $900 from Savings.\n";
	my_bank.transfer(900,"S");
	my_bank.print_balances();
	
	return 0;
}

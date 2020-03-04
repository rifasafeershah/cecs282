//Rifa Safeer Shah
//CECS 282 LAB 2 PROBLEM 2

#include <iostream>
#include <cmath>
using namespace std;

class Account{
    public:
    	double amount, rate;
	    Account(){
	        amount = 10000;
	        rate = 6;
	    }
	    Account(double a, double r){
	        amount = a; //assign amount to variable a
	        rate = r; //assign rate to variable r
	    }
	
	    double investmentDoubling() {
	        double monthly_rate = rate / (12 * 100); //dividing the interest for each month
	        double months = log(2)/log(1 + monthly_rate); //calculating the doubling time
	        return months;
	    }
	
		double get_balance(){
	        return amount;
	    }
		
	    void deposit(double a){
	        if(a < 0){
	            return;
	        }
	        else{
	        	amount = amount + a;
			}
	    }
	
	    void withdraw(double a){
	        if(amount - a < 0){
	            return;
	        }
	        else{
	        	amount = amount - a;
			}
	    }
    
};

int main()
{
    double balance, rate;

    cout << "Please enter initial investment: ";
    cin >> balance;

    cout << "Please enter annual rate of interest: ";
    cin >> rate;


    Account my_account(balance, rate);

    cout << "The time to double the investment is: " << ceil(my_account.investmentDoubling()) << " months." << endl;

    return 0;
}

// Lauren Hayden
// CS 210 - Professor Chan
// 27 November 2022

#include <iostream>
#include <iomanip>
using namespace std;


double initialInvestment;
double monthlyDeposit;
double annualInterest;
int numYears;


// prints each year, end balance, and interest earned
void printDetails(int year, double yearEndBalance, double interestEarned){
	cout << fixed << setprecision(2) << year << "                     " << yearEndBalance << "                  " << interestEarned << endl;
}


// calculates the balance without monthly deposits for each year inputted
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears){
	cout << "Balance and Interest Without Additional Montly Deposits         " << endl;
	cout << "=================================================================" << endl;
	cout << "Year        Year End Balance            Year End Earned Interest" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	double interest = (initialInvestment) * ((interestRate / 100) / 12);     // initial interest
	double currentSavings = initialInvestment + interest;                   // combines initial interest to current savings
	for (int i = 1; i <= numberOfYears; ++i) {                              // prints table for each year inputted
		printDetails(i, currentSavings, interest);
		interest = currentSavings * ((interestRate / 100) / 12); 
		currentSavings = currentSavings + interest;
	}
	return currentSavings;  // the program wouldn't run if I didn't return something. I know this isn't right, but I couldn't figure out anything else
}

//calculates the balance with a monthly deposit
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears){
	cout << "Balance and Interest With Additional Monthly Deposits        " << endl;
    cout << "===============================================================" << endl;
	cout << "Year         Year End Balance          Year End Earned Interest" << endl;
	
	double interest = (initialInvestment + monthlyDeposit) * ((interestRate / 100) / 12);  // initial interest compounded
	double  currentSavings = initialInvestment + (monthlyDeposit * 12)+ interest;   // current savings 
	for (int i = 1; i <= numberOfYears; ++i) {                      // prints a table of each year inputted
		printDetails(i, currentSavings, interest);    
		currentSavings = currentSavings + (monthlyDeposit * 12);    // adds 12 months deposits for the following year
		interest = currentSavings * ((interestRate / 100) / 12);    // changes the interest to account for the monthly deposits
		currentSavings = currentSavings + interest;                 // adds interest to current savings
	}
	return currentSavings;   // the program wouldn't run if I didn't return something, like above. 
}

int main() {

	// outputs screen for user to input information
	cout << "******************************" << endl;
	cout << "******* Data Input ***********" << endl;
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << endl;
	cout << "Monthly Investment: ";
	cin >> monthlyDeposit;
	cout << endl;
	cout << "Annual Interest: ";
	cin >> annualInterest;
	cout << endl;
	cout << "Number of years: ";
	cin >> numYears;
	cout << endl;

	calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, numYears);
	balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, numYears);




	return 0;
}

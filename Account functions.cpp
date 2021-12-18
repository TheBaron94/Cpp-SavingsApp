#include <iostream>
#include <iomanip>

using namespace std;

#include "Account functions.h"

AccountFunctions::AccountFunctions() {//default constructor
	//default values
	m_initInvest = 1.0;
	m_monthDeposit = 50.0;
	m_interest = 5;
	m_years = 5;

}



void AccountFunctions::interestCalculation(const double t_monthlyInvest, double& t_openingAmount, double& t_endingAmount, double& t_interestEarned, const int t_interestRate) { // calculates monthly compunding interest
	double originalOpening = t_openingAmount;
	double interestMonthly = 0.0;
	t_interestEarned = 0.0;

	for (int i = 0; i < 12; ++i) {
		interestMonthly = ((t_openingAmount + t_monthlyInvest) * ((t_interestRate / 100.0) / 12.0));
		t_openingAmount = (t_openingAmount + interestMonthly + t_monthlyInvest);
		t_interestEarned = t_interestEarned + interestMonthly;
	}
	t_endingAmount = t_openingAmount;
	t_openingAmount = originalOpening;
}



void AccountFunctions::changeInput(AccountFunctions& t_Account) {
	int userInput; // varaible decleration for in function use
	double newDouble;
	int newInt;
	bool loopCheck = true;
	bool validCheck = true;

	while (loopCheck) {
		system("CLS");
		cout << "Which Input would you like to change?" << endl;
		cout << "=====================================" << endl;
		cout << "1) Initial Investment Amount" << endl;
		cout << "2) Monthly Deposit Amount" << endl;
		cout << "3) Annual Interest Rate" << endl;
		cout << "4) Length of Investment in Years" << endl;

		cin >> userInput;
		while ((cin.fail()) || (userInput > 4) || (userInput < 1)) {
			cout << "Invalid selection, Please try again." << endl;
			cin.clear();
			cin.ignore();
			cin >> userInput;
		}
		cout << endl;
		validCheck = true; //ensure proper start for validation check
		switch (userInput) {

		case 1: // change initial investment amount and returns
			while (validCheck) {
				try {
					cout << "New Initial Investment Amount (In dollars and cents form IE: 10.00): $";
					cin >> newDouble;
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						throw runtime_error("Invalid Investment Amount");
					}
					cout << endl;
					if (newDouble < 0.01) {
						throw runtime_error("Invalid Investment Amount");
					}
					else {
						t_Account.setInitInvest(newDouble);
						validCheck = false;
					}
				}
				catch (runtime_error& excpt) {
					//print the error out and try again
					cout << excpt.what() << endl;
					cout << "Try A Different Amount" << endl;
					cout << endl;
				}
			}
			break;


		case 2: //change monthly deposit amount.
			while (validCheck) {
				try {
					cout << "New Monthly Deposit Amount (In dollars and cents form IE: 10.00): $";
					cin >> newDouble;
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						throw runtime_error("Invalid Deposit Amount");
					}
					cout << endl;
					if (newDouble < 0.01) {
						throw runtime_error("Invalid Deposit Amount");
					}
					else {
						t_Account.setMonthDeposit(newDouble);
						validCheck = false;
					}
				}
				catch (runtime_error& excpt) {
					//print the error out and try again
					cout << excpt.what() << endl;
					cout << "Try A Different Amount" << endl;
					cout << endl;
				}
			}
			break;


		case 3:// change annual interest rate.
			while (validCheck) {
				cout << "New Annual Interest rate (as a whole number): %";
				cin >> newInt;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw runtime_error("Invalid Interest Rate");
				}
				cout << endl;
				try {
					if (newInt < 0) {
						throw runtime_error("Invalid Interest Rate");
					}
					else {
						t_Account.setAnnInterest(newInt);
						validCheck = false;
					}
				}
				catch (runtime_error& excpt) {
					//print the error out and try again
					cout << excpt.what() << endl;
					cout << "Try A Different Amount" << endl;
					cout << endl;
				}
			}
			break;


		case 4:// change length of investment
			while (validCheck) {
				cout << "New Length of investment in years (Min of 1 year): ";
				cin >> newInt;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw runtime_error("Invalid Investment Time Length");
				}
				cout << endl;
				try {
					if (newInt < 1) {
						throw runtime_error("Invalid Investment Time Length");
					}
					else {
						t_Account.setYears(newInt);
						validCheck = false;
					}
				}
				catch (runtime_error& excpt) {
					//print the error out and try again
					cout << excpt.what() << endl;
					cout << "Try A Different Amount" << endl;
					cout << endl;
				}
			}

			break;
		}


		//check if other inputs to change
		cout << endl;
		cout << "Would you like to change another input?" << endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		cin >> userInput;
		while ((cin.fail()) || (userInput > 2) || (userInput < 1)) {
			cout << "Invalid selection, Please try again." << endl;
			cin.clear();
			cin.ignore();
			cin >> userInput;
		}
		if (userInput == 1) {
			continue;
		}
		else if (userInput == 2) {
			loopCheck = false;
		}
	}
}



//setters
void AccountFunctions::setInitInvest(double t_initInvest) {
	this->m_initInvest = t_initInvest;
}

void AccountFunctions::setMonthDeposit(double t_monthDeposit) {
	this->m_monthDeposit = t_monthDeposit;
}

void AccountFunctions::setAnnInterest(int t_interest) {
	this->m_interest = t_interest;
}

void AccountFunctions::setYears(int t_years) {
	this->m_years = t_years;
}



//getters
int AccountFunctions::getYears() {
	return this->m_years;
}

double AccountFunctions::getInitInvest() {
	return this->m_initInvest;
}

int AccountFunctions::getAnnInterest() {
	return this->m_interest;
}

double AccountFunctions::getMonthDeposit() {
	return this->m_monthDeposit;
}



void AccountFunctions::inputDisplay(AccountFunctions& t_Account) { // user input display function
	//initalize function local temp variables
	double tempInvest;
	double tempMonthly;
	int tempInterest;
	int tempYears;
	bool validCheck = true;

	cout << "===========================================================================================" << endl;
	cout << "                                   Account Information                                     " << endl;
	cout << "===========================================================================================" << endl;
	cout << endl;
	while (validCheck) {
		try {
			cout << "Initial Investment amount (In dollars and cents form IE: 10.00): $";
			cin >> tempInvest;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				throw runtime_error("Invalid Initial Investment Amount");
			}
			cout << endl;
			if ((tempInvest) < 0.01) {
				throw runtime_error("Invalid Initial Investment Amount");
			}
			else {
				t_Account.setInitInvest(tempInvest);
				validCheck = false;
			}
		}
		catch (runtime_error& excpt) {
			//print the error out and try again
			cout << excpt.what() << endl;
			cout << "Try A Different Amount" << endl;
			cout << endl;
		}
	}
	validCheck = true; //reset check bool

	while (validCheck) {
		try {
			cout << "Monthly Deposit (In dollars and cents form): $";
			cin >> tempMonthly;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				throw runtime_error("Invalid Monthly Deposit");
			}
			cout << endl;
			if (tempMonthly < 0.01) {
				throw runtime_error("Invalid Monthely Deposit");
			}
			else {
				t_Account.setMonthDeposit(tempMonthly);
				validCheck = false;
			}
		}
		catch (runtime_error& excpt) {
			//print the error out and try again
			cout << excpt.what() << endl;
			cout << "Try A Different Amount" << endl;
			cout << endl;
		}
	}

	validCheck = true; // reset bool for next loop
	while (validCheck) {
		try {
			cout << "Annual Interest rate (as a whole number): %";
			cin >> tempInterest;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				throw runtime_error("Invalid Interest Rate");
			}
			cout << endl;

			if (tempInterest < 0) {
				throw runtime_error("Invalid Interest Rate");
			}
			else {
				t_Account.setAnnInterest(tempInterest);
				validCheck = false;
			}
		}
		catch (runtime_error& excpt) {
			//print the error out and try again
			cout << excpt.what() << endl;
			cout << "Try A Different Amount" << endl;
			cout << endl;
		}
	}
	validCheck = true; // reset bool for next loop
	while (validCheck) {
		try{
		cout << "Length of investment in years (Min of 1 year): ";
		cin >> tempYears;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			throw runtime_error("Invalid Investment Time Length");
		}
		cout << endl;
		
			if (tempYears < 1) {
				throw runtime_error("Invalid Investment Time Length");
			}
			else {
				t_Account.setYears(tempYears);
				validCheck = false;
			}
		}
		catch (runtime_error& excpt) {
			//print the error out and try again
			cout << excpt.what() << endl;
			cout << "Try A Different Amount" << endl;
			cout << endl;
		}

	}

	cout << endl;
	cout << endl;
	//cout << "Press any key to display account information";
	system("Pause");


}



//function to calculate and display year end account info both with and with out monthly deposits
void AccountFunctions::yearEndDisplay(AccountFunctions& t_Account) {
	//local function variables
	double openingAmount;
	double endingAmount;
	double interestEarned;
	int interestRate;
	double monthlyInvestment;
	cout << fixed << setprecision(2);//set display precision for doubles

	//screen display header for without monthly deposits
	cout << "                     Balance and Interest Without Additional Monthly Deposits                     " << endl;
	cout << "==================================================================================================" << endl;
	cout << "||" << setw(30) << left << "Year" << "||";
	cout << setw(30) << left << "Ending Balance" << "||";
	cout << setw(30) << left << "Earned Interest" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	
	//acount caluclations and display
	monthlyInvestment = 0; //no monthly deposit
	openingAmount = t_Account.getInitInvest();
	endingAmount = 0.0;
	interestEarned = 0.0;
	interestRate = t_Account.getAnnInterest();
	for (int i = 1; i <= t_Account.getYears(); ++i) {
		t_Account.interestCalculation(monthlyInvestment, openingAmount, endingAmount, interestEarned, interestRate);
		cout << "||" << setw(30) << left << i << "||";
		cout << setw(30) << left << endingAmount << "||";
		cout << setw(30) << left << interestEarned << "||" << endl;
		cout << endl;
		openingAmount = endingAmount; // set opening to ending for next years compunding interest.
	}

	cout << "==================================================================================================" << endl;
	cout << endl;

	//screen display header for with monthly deposits
	cout << "                      Balance and Interest With Additional Monthly Deposits                       " << endl;
	cout << "==================================================================================================" << endl;
	cout << "||" << setw(30) << left << "Year" << "||";
	cout << setw(30) << left << "Ending Balance" << "||";
	cout << setw(30) << left << "Earned Interest" << "||" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//acount caluclations and display
	monthlyInvestment = t_Account.getMonthDeposit();
	openingAmount = t_Account.getInitInvest();
	endingAmount = 0.0;
	interestEarned = 0.0;
	interestRate = t_Account.getAnnInterest();
	for (int i = 1; i <= t_Account.getYears(); ++i) {
		t_Account.interestCalculation(monthlyInvestment, openingAmount, endingAmount, interestEarned, interestRate);
		cout << "||" << setw(30) << left << i << "||";
		cout << setw(30) << left << endingAmount << "||";
		cout << setw(30) << left << interestEarned << "||" << endl;
		cout << endl;
		openingAmount = endingAmount; // set opening to ending for next years compunding interest.
	}

	cout << "==================================================================================================" << endl;

}


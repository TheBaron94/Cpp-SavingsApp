/*
* Airgead Banking App
* Project 2
* SNHU CS-210
* Adam Schmidt
* 11/19/2021
*/

#include <iostream>

using namespace std;

#include "Account functions.h"



int main() {

	//declare account
	AccountFunctions Account1;
	int userChoice = 2;

	//these two lines will through errors on any machines that arent running windows, if youre running something that isnt windows i recommend commenting them out
	//system("mode 125");//sizes cmd window to display properly
	system("color 04"); // changes console color, why? because i can, lol

	Account1.inputDisplay(Account1);//display input menu

	//main while loop
	while (userChoice != 3) {
		system("CLS");
		Account1.yearEndDisplay(Account1);//run and display calculations.

		//display choice menu after program has run through at least once
		cout << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) Change a previous input." << endl << "2) Start over" << endl << "3) Exit Program" << endl;
		cin >> userChoice;
		while ((cin.fail()) || (userChoice > 3) || (userChoice < 1)) {
			cout << "Invalid selection, Please try again." << endl;
			cin.clear();
			cin.ignore();
			cin >> userChoice;
		}

		if (userChoice == 1) {
			Account1.changeInput(Account1);
			continue;
		}
		else if (userChoice == 2) {
			system("CLS");
			Account1.inputDisplay(Account1);
			continue;
		}
		else if (userChoice == 3) {
			exit(0);//end program
		}

		
	}


	return 0;
}
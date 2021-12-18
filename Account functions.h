#ifndef ACCOUNT_FUNCTIONS_H
#define ACCOUNT_FUNCTIONS_H

using namespace std;

class AccountFunctions {
	public:
		void inputDisplay(AccountFunctions& t_Account); // displays input to user and validates as well as sets input
		AccountFunctions();//constructor
		void changeInput(AccountFunctions& t_Account);
		//setters
		void setInitInvest(double t_initInvest);
		void setMonthDeposit(double t_monthDeposit);
		void setAnnInterest(int t_interest);
		void setYears(int t_years);
		void yearEndDisplay(AccountFunctions& t_Account); //caclulates and Displays interest reports for both with monthly deposits and without
		//getters
		int getYears();
		double getInitInvest();
		int getAnnInterest();
		double getMonthDeposit();

	private:
		double m_initInvest;
		double m_monthDeposit;
		int m_interest;
		int m_years;
		void interestCalculation(const double t_monthlyInvest, double& t_openingAmount, double& t_endingAmount, double& t_interestEarned, const int t_interestRate);
};

#endif



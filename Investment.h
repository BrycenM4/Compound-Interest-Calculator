#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>
using namespace std;

class Investment {
private:
	double m_initialAmount;
	double m_annualInterestRate;
	int m_years;
	double m_monthlyDeposits;

public:
	// Constructor
	Investment(double t_initAmount, double t_interestRate, int t_numYears, double t_monthlyDep = 0);

	// Destructor
	~Investment();

	// Calculates without monthly deposits
	void WithoutMonthlyDeposits(vector<double>&balances, vector<double>&interests);

		// Calculates with monthly deposits
	void WithMonthlyDeposits(vector<double>&balances, vector<double>&interests);
};

#endif // Investment_H
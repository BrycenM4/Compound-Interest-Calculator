#include "Investment.h"

using namespace std;

// Constructor
Investment::Investment(double t_initAmount, double t_interestRate, int t_numYears, double t_monthlyDep)
    : m_initialAmount(t_initAmount), m_annualInterestRate(t_interestRate),
    m_years(t_numYears), m_monthlyDeposits(t_monthlyDep) {
}

// Destructor
Investment::~Investment() {
    // Destructor body
}

// Calculates without monthly deposits
void Investment::WithoutMonthlyDeposits(std::vector<double>& balances, std::vector<double>& interests) {
    double balance = m_initialAmount;
    double ratePerMonth = (m_annualInterestRate / 100) / 12;

    for (int year = 1; year <= m_years; year++) {
        double yearStartBalance = balance;
        for (int i = 0; i < 12; i++) {
            balance *= (1 + ratePerMonth);
        }
        double yearEndInterest = balance - yearStartBalance;
        balances.push_back(balance);
        interests.push_back(yearEndInterest);
    }
}

// Calculates with monthly deposits
void Investment::WithMonthlyDeposits(std::vector<double>& balances, std::vector<double>& interests) {
    double balance = m_initialAmount;
    double ratePerMonth = (m_annualInterestRate / 100) / 12;

    for (int year = 1; year <= m_years; year++) {
        double yearStartBalance = balance;
        for (int i = 0; i < 12; i++) {
            balance += m_monthlyDeposits;
            balance *= (1 + ratePerMonth);
        }
        double yearEndInterest = balance - yearStartBalance - (m_monthlyDeposits * 12);
        balances.push_back(balance);
        interests.push_back(yearEndInterest);
    }
}
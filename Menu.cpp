#include "Menu.h"

// Constructor
Menu::Menu() {
    investment = nullptr;
}

// Destructor
Menu::~Menu() {
    delete investment;
}

// Validate input
double Menu::getValidInput(const string& prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < minValue || value > maxValue) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            return value;
        }
    }
}

// Method to format the table output
void Menu::formatting(bool withDeposits) {
    if (withDeposits) {
        cout << "============================================================\n";
        cout << "Balance and Interest With Additional Monthly Deposits\n";
        cout << "============================================================\n";
    }
    else {
        cout << "============================================================\n";
        cout << "Balance and Interest Without Additional Monthly Deposits\n";
        cout << "============================================================\n";
    }
    cout << right << setw(1) << "Year"
        << right << setw(25) << "Year End Balance"
        << right << setw(30) << "Year End Earned Interest\n";
    cout << "------------------------------------------------------------\n";
}

// Main program function
void Menu::run() {
    cout << "Welcome to Airgead Banking!\n" << endl;

    double initialAmount = getValidInput("Initial investment amount: $", 1);
    double annualInterestRate = getValidInput("Interest Rate (%): ");
    int years = static_cast<int>(getValidInput("Number of years: ", 1));
    double monthlyDeposit = getValidInput("Monthly deposit amount: $", 0);

    // Create a new Investment object
    investment = new Investment(initialAmount, annualInterestRate, years, monthlyDeposit);

    vector<double> balancesWithoutMonthlyDeposits, interestsWithoutDeposits;
    vector<double> balancesWithMonthlyDeposits, interestWithMonthlyDeposits;

    investment->WithoutMonthlyDeposits(balancesWithoutMonthlyDeposits, interestsWithoutDeposits);
    investment->WithMonthlyDeposits(balancesWithMonthlyDeposits, interestWithMonthlyDeposits);

    // Output without monthly deposits
    formatting(false);
    cout << fixed << setprecision(2);
    for (int i = 0; i < years; ++i) {
        cout << setw(2) << (i + 1)
            << right << setw(20) << balancesWithoutMonthlyDeposits[i]
            << right << setw(25) << interestsWithoutDeposits[i] << endl;
    }

    // Output with monthly deposits
    formatting(true);
    cout << fixed << setprecision(2);
    for (int i = 0; i < years; ++i) {
        cout << setw(2) << (i + 1)
            << right << setw(20) << balancesWithMonthlyDeposits[i]
            << right << setw(25) << interestWithMonthlyDeposits[i] << endl;
    }
}
